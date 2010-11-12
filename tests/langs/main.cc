#include <iostream>
#include <gtkmm.h>
#include <gtksourceviewmm/sourceview.h>
#include<gtksourceviewmm/sourcelanguagemanager.h>
#include<gtksourceviewmm/init.h>

using namespace std ;
using namespace Gsv ;

int
main (int argc, char **argv)
{
    Gtk::Main loop (argc, argv) ;
    Gsv::init () ;

    Glib::RefPtr<SourceLanguageManager> language_manager =
                                                SourceLanguageManager::create();
    vector<Glib::ustring > langs = language_manager->get_language_ids ();
    cout << "number of languages found: " << langs.size () << std::endl;;

    for (vector<Glib::ustring>::const_iterator iter = langs.begin(); iter != langs.end (); ++iter) {
        if (!(iter->empty())) {
            Glib::RefPtr<SourceLanguage> lang = language_manager->get_language (*iter);
            cout << "language: " << lang->get_name () << std::endl;
        } else {
            cout << "language: null" << std::endl;;
        }
    }
    return 0 ;
}

