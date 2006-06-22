#include <iostream>
#include <gtkmm.h>
#include <gtksourceview/gtksourceview.h>
#include <gtksourceviewmm/sourceview.h>
#include <gtksourceviewmm/sourcebuffer.h>
#include <gtksourceviewmm/init.h>

using namespace std ;
using namespace Glib ;
using namespace Gtk ;
using namespace gtksourceview ;

int
main (int a_argc, char *a_argv[])
{
    Gtk::Main main_loop (a_argc, a_argv) ;
    gtksourceview::init () ;

    SourceView source_view ;
    RefPtr<SourceBuffer> buffer = source_view.get_source_buffer () ;
    if (!buffer) {
        cerr << "gtksourceview::SourceView::get_source_buffer () failed\n" ;
        return -1;
    }
    buffer->set_text ("coin") ;

    Window window ;
    window.add (source_view) ;

    window.show_all () ;

    main_loop.run (window) ;

    return 0 ;
}

