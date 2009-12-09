#include <iostream>
#include <gtkmm.h>
#include <gtksourceviewmm.h>
namespace Gsv = gtksourceview ;

int
main (int argc, char* argv[])
{
    Gtk::Main kit (argc, argv) ;
    Gsv::init () ;

    Gsv::SourceView view ;
    Glib::RefPtr<Gsv::SourceBuffer> buf = view.get_source_buffer () ;
    if (buf) {
        std::cout << "PASSED" << std::endl;
    } else {
        std::cout << "FAILED" << std::endl;
    }
    return 0 ;
}


