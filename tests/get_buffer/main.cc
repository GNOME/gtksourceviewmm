#include <iostream>
#include <gtkmm.h>
#include <gtksourceviewmm.h>

int
main (int argc, char* argv[])
{
    Gtk::Main kit (argc, argv) ;
    Gsv::init () ;

    Gsv::View view ;
    Glib::RefPtr<Gsv::Buffer> buf = view.get_source_buffer () ;
    if (buf) {
        std::cout << "PASSED" << std::endl;
    } else {
        std::cout << "FAILED" << std::endl;
    }
    return 0 ;
}


