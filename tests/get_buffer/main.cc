#include <iostream>
#include <gtkmm.h>
#include <gtksourceviewmm.h>

int
main (int argc, char* argv[])
{
    Glib::RefPtr<Gtk::Application> app =
        Gtk::Application::create(argc, argv,
            "org.gtksourceviewmm.test");

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


