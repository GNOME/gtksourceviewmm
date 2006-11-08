#include <iostream>
#include <gtkmm.h>
#include <gtksourceviewmm/sourceview.h>
#include<gtksourceviewmm/sourcelanguagesmanager.h>
#include<gtksourceviewmm/init.h>

using namespace std ;
using namespace gtksourceview ;

int
main (int argc, char **argv)
{
    Gtk::Main loop (argc, argv) ;
    gtksourceview::init () ;

    Glib::RefPtr<SourceLanguagesManager> language_manager =
                                                SourceLanguagesManager::create();
    vector<Glib::RefPtr<SourceLanguage> > langs;
    langs = language_manager->get_available_languages ();
    vector<Glib::RefPtr<SourceLanguage> >::iterator iter;
    cout << "number of languages found: '" << langs.size () << "'\n";
    for (iter = langs.begin(); iter != langs.end (); ++iter) {
        if (*iter) {
            cout << "language: '" << (*iter)->get_name () << "'\n";
        } else {
            cout << "language: null\n" ;
        }
    }
    return 0 ;
}

