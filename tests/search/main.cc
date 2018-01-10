#include <cassert>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <gtkmm.h>
#include <gtksourceviewmm.h>
#include <glib.h> //For <gmessages.h>

using namespace std ;
using namespace Gtk;
using namespace Glib;
using namespace Gsv ;

#define LOG(message) \
std::cout << __PRETTY_FUNCTION__ << ":" << __FILE__<< ":" << __LINE__ << ":" \
<< message << endl

#define THROW(message) \
LOG ("throwing exception: " + string (#message)) ; \
throw std::runtime_error (message) ;

#define THROW_IF_FAIL(cond) if (!(cond)) {\
THROW (std::string ("condition failed: ") + std::string (#cond)) \
}

class SearchDialog : public Dialog {
    //non copyable
    SearchDialog (const SearchDialog&) ;
    SearchDialog& operator= (const SearchDialog&) ;

    Gtk::Box *m_hbox ;
    Gtk::Entry *m_entry ;
    Gtk::Button *m_search_forward_button ;
    Gtk::Button *m_search_backward_button ;
    sigc::signal<void()> m_forward_search_requested_signal ;
    sigc::signal<void()> m_backward_search_requested_signal ;

    void init_members ()
    {
        m_hbox =  0 ;
        m_entry = 0 ;
        m_search_forward_button = 0;
        m_search_backward_button = 0;
    }

    void build_widget ()
    {
        add_button ("Close", ResponseType::ACCEPT) ;

        m_hbox = manage (new Gtk::Box(Gtk::Orientation::HORIZONTAL)) ;
        get_content_area ()->pack_start (*m_hbox) ;

        Label *label = manage (new Label ("Search: ")) ;
        m_hbox->pack_start (*label) ;

        m_entry = manage (new Entry ()) ;
        m_hbox->pack_start (*m_entry) ;

        m_search_forward_button = manage (new Button ("search forward")) ;
        m_search_forward_button->signal_clicked ().connect (sigc::mem_fun
                (*this, &SearchDialog::on_search_forward_button_clicked_signal)) ;
        m_hbox->pack_start (*m_search_forward_button, PACK_SHRINK) ;

        m_search_backward_button = manage (new Button ("search backward")) ;
        m_search_backward_button->signal_clicked ().connect (sigc::mem_fun
                (*this, &SearchDialog::on_search_backward_button_clicked_signal));

        m_hbox->pack_start (*m_search_backward_button, PACK_SHRINK) ;
    }

    void on_search_forward_button_clicked_signal ()
    {
        forward_search_requested_signal ().emit () ;
    }

    void on_search_backward_button_clicked_signal ()
    {
        backward_search_requested_signal ().emit () ;
    }

public:

    SearchDialog (const ustring &a_title="") :
        Dialog (a_title)
    {
        init_members () ;
        build_widget () ;
    }

    ~SearchDialog ()
    {
    }

    void get_search_string (ustring &a_str)
    {
        THROW_IF_FAIL (m_entry) ;
        a_str = m_entry->get_text () ;
    }

    sigc::signal<void()>& forward_search_requested_signal ()
    {
        return m_forward_search_requested_signal ;
    }

    sigc::signal<void()>& backward_search_requested_signal ()
    {
        return m_backward_search_requested_signal ;
    }
};//end class SearchDialog


class App {
    //non copyable
    App (const App&) ;
    App& operator= (const App&) ;

    Window *m_window ;
    MenuBar *m_menu_bar ;
    Menu *m_file_menu ;
    MenuItem *m_file_menu_item ;
    MenuItem *m_open_menu_item ;
    Menu *m_edit_menu;
    MenuItem *m_edit_menu_item ;
    MenuItem *m_search_menu_item ;
    Box *m_main_vbox ;
    View *m_source_view;

public:

    App ()
    {
        init_members () ;
        init_menu () ;
        init_body () ;
    }

    void init_members ()
    {
        m_window = new Window ;
        m_menu_bar = 0 ;
        m_file_menu = 0 ;
        m_file_menu_item = 0 ;
        m_main_vbox = 0 ;
        m_source_view = 0 ;
        m_open_menu_item = 0 ;
        m_edit_menu_item = 0 ;
        m_search_menu_item = 0 ;
    }

    ~App ()
    {
        if (m_window) {
            delete m_window ;
            m_window = 0 ;
        }
    }

    //********************
    //<signal handlers>
    //********************
    void on_open_menu_item_activate_signal ()
    {
        try {
            FileChooserDialog fc_dialog ("open a file",
                                         FileChooserAction::OPEN);
            fc_dialog.set_select_multiple (false) ;
            fc_dialog.add_button ("Cancel", ResponseType::CANCEL) ;
            fc_dialog.add_button ("OK", ResponseType::ACCEPT) ;
            int res = fc_dialog.run () ;
            if (res != ResponseType::ACCEPT) {return;}
            ustring filename = fc_dialog.get_filename () ;
            if (filename == "") {return;}
            open_file (filename) ;
        } catch (...) {
            LOG ("exception caught") ;
        }
    }

    void on_search_menu_item_activate_signal ()
    {
        SearchDialog search_dialog ;
        search_dialog.forward_search_requested_signal ().connect
            (sigc::bind (sigc::mem_fun (*this,
                                        &App::on_search_signal),
                         &search_dialog,
                         true)) ;

        search_dialog.backward_search_requested_signal ().connect
            (sigc::bind (sigc::mem_fun (*this,
                                        &App::on_search_signal),
                         &search_dialog,
                         false)) ;
        search_dialog.run () ;
        search_dialog.hide () ;
    }


    void on_search_signal (SearchDialog *a_dialog,
                           bool a_forward)
    {
        if (!a_dialog) {return;}

        ustring search_str ;
        a_dialog->get_search_string (search_str) ;
        if (search_str == "") {return ;}
        if (!do_search (search_str, a_forward)) {
            MessageDialog dialog (*a_dialog,
                                  "Did not find string " + search_str,
                                  false,
                                  MessageType::WARNING) ;
            dialog.run () ;
            dialog.hide () ;
        }
    }

    bool do_search (const ustring &a_text,
                    bool a_forward)
    {
        THROW_IF_FAIL (m_source_view) ;
        RefPtr<Buffer> source_buffer = m_source_view->get_source_buffer () ;

        TextIter search_iter (source_buffer->begin ());
        TextIter start, end, limit ;
        if (!a_forward) {
            search_iter = source_buffer->end () ;
            search_iter-- ;
        }
        TextIter last_sel_start ;

        bool found=false ;
        if (a_forward) {
            if (source_buffer->get_selection_bounds (start, last_sel_start)) {
                search_iter = last_sel_start ;
            }
            limit = source_buffer->end () ;
            found = search_iter.forward_search
                                    (a_text,
                                     TextSearchFlags::TEXT_ONLY | TextSearchFlags::CASE_INSENSITIVE,
                                     start,
                                     end,
                                     limit) ;
        } else {
            if (source_buffer->get_selection_bounds (last_sel_start, end)) {
                search_iter = last_sel_start ;
            }
            limit = source_buffer->begin () ;
            found = search_iter.backward_search
                                    (a_text,
                                     TextSearchFlags::TEXT_ONLY | TextSearchFlags::CASE_INSENSITIVE,
                                     start,
                                     end,
                                     limit) ;
        }
        if (found) {
            m_source_view->scroll_to (start, 0.1) ;
            m_source_view->get_source_buffer ()->select_range (start, end) ;
            return true ;
        }
        return false ;
    }

    //********************
    //</signal handlers>
    //********************

    void init_menu ()
    {
        if (m_menu_bar) {return;}

        //********************
        //<build the menu bar>
        //*********************
        m_menu_bar = manage (new MenuBar) ;

        //********************
        //build the File menu
        //**********************
        m_file_menu = manage (new Menu) ;
        m_file_menu_item = manage (new MenuItem ("File")) ;
        m_file_menu_item->set_submenu (*m_file_menu) ;
        m_open_menu_item = manage (new MenuItem ("Open")) ;
        m_file_menu->insert (*m_open_menu_item, -1) ;

        //*********************
        //build the edit menu
        //*********************
        m_edit_menu_item = manage (new MenuItem ("Edit")) ;
        m_edit_menu = manage (new Menu) ;
        m_edit_menu_item->set_submenu (*m_edit_menu) ;
        m_search_menu_item = manage (new MenuItem ("Search")) ;
        m_edit_menu->insert (*m_search_menu_item, -1) ;

        //now pack the menus into the menu_bar
        m_menu_bar->insert(*m_file_menu_item, -1) ;
        m_menu_bar->insert (*m_edit_menu_item, -1) ;
        //********************
        //</build the menu bar>
        //*********************

        connect_menu_signals () ;
    }

    void connect_menu_signals ()
    {
        THROW_IF_FAIL (m_open_menu_item) ;
        THROW_IF_FAIL (m_search_menu_item) ;

        m_open_menu_item->signal_activate ().connect (sigc::mem_fun
                (*this, &App::on_open_menu_item_activate_signal)) ;
        m_search_menu_item->signal_activate ().connect (sigc::mem_fun
                (*this, &App::on_search_menu_item_activate_signal)) ;
    }

    void init_body ()
    {
        if (m_main_vbox) {return;}

        m_main_vbox = manage (new Gtk::Box(Gtk::Orientation::VERTICAL)) ;
        g_return_if_fail (m_menu_bar) ;
        m_main_vbox->pack_start (*m_menu_bar, PACK_SHRINK) ;
        m_source_view = manage (new View) ;
        m_main_vbox->pack_start (*m_source_view) ;
        get_widget ().add (*m_main_vbox) ;
    }

    Window& get_widget ()
    {
        THROW_IF_FAIL (m_window) ;
        return *m_window ;
    }

    void open_file (const ustring& a_path)
    {
        if (a_path == "") {return;}
        THROW_IF_FAIL (m_source_view) ;

        ifstream file (filename_from_utf8 (a_path).c_str ()) ;
        if (!file.good ()) {
            LOG ("Could not open file " + locale_to_utf8 (a_path)) ;
            return ;
        }
        static const int BUFFER_SIZE=1024*10 ;

        static char buffer[BUFFER_SIZE + 1] ;
        memset (buffer, 0, BUFFER_SIZE + 1) ;
        RefPtr<Buffer> source_buffer = m_source_view->get_source_buffer () ;
        for (;;) {
            file.read (buffer, BUFFER_SIZE) ;
            THROW_IF_FAIL (file.good () || file.eof ()) ;
            source_buffer->insert (source_buffer->end (),
                                   buffer,
                                   buffer + file.gcount ()) ;
            if (file.gcount () != BUFFER_SIZE) {break ;}
        }
        file.close () ;
    }

};//end class App

int
main (int argc, char **argv)
{
    Glib::RefPtr<Gtk::Application> gtkmmapp =
        Gtk::Application::create("org.gtksourceviewmm.test");

    Gsv::init () ;

    App app ; //TODO: Derive from Gtk::Application?
    app.get_widget ().set_size_request (500, 400) ;
    if (argc == 2) {
        app.open_file (filename_to_utf8 (argv[1])) ;
    }

    gtkmmapp->run (app.get_widget ()) ;

    return 0 ;
}
