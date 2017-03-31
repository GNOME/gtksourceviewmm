#include <iostream>
#include <gtkmm.h>
#include <gtksourceviewmm.h>
using namespace std ;
using namespace Glib ;
using namespace Gtk ;
using namespace Gsv;

int
main (int a_argc, char *a_argv[])
{
    Glib::RefPtr<Gtk::Application> app =
        Gtk::Application::create(a_argc, a_argv,
            "org.gtksourceviewmm.test");

    Gsv::init () ;

    View source_view ;
    RefPtr<Buffer> buffer = source_view.get_source_buffer () ;
    if (!buffer) {
        cerr << "Gsv::View::get_source_buffer () failed" << std::endl ;
        return -1;
    }
    buffer->set_text ("coin") ;

    Window window ;
    window.add (source_view) ;

    app->run (window) ;

    return 0 ;
}

