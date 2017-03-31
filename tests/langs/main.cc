#include <iostream>
#include <gtkmm.h>
#include <gtksourceviewmm/view.h>
#include<gtksourceviewmm/languagemanager.h>
#include<gtksourceviewmm/init.h>

using namespace std ;
using namespace Gsv ;

int
main ()
{
    Glib::RefPtr<Gtk::Application> app =
        Gtk::Application::create("org.gtksourceviewmm.test");

    Gsv::init ();

    Glib::RefPtr<LanguageManager> language_manager =
                                                LanguageManager::create();
    vector<string> langs = language_manager->get_language_ids ();
    cout << "number of languages found: " << langs.size () << std::endl;

    for (vector<string>::const_iterator iter = langs.begin(); iter != langs.end (); ++iter) {
        if (!(iter->empty())) {
            Glib::RefPtr<Language> lang = language_manager->get_language (*iter);
            cout << "language: " << lang->get_name () << std::endl;
        } else {
            cout << "language: null" << std::endl;
        }
    }

    return 0 ;
}

