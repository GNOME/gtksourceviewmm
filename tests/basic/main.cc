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
    Gtk::Main main_loop (a_argc, a_argv) ;
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

    window.show_all () ;

    main_loop.run (window) ;

    return 0 ;
}

