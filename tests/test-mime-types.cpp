#include <iostream>
#include <gtkmm.h>
#include <gtksourceviewmm/sourcelanguagesmanager.h>
#include <gtksourceviewmm/init.h>

using namespace std ;
using namespace gtksourceview ;

const char * s_mime_types [] = {
"text/xml",
"text/html",
"text/x-c",
"text/x-c++",
0
};

int
main (int argc, char **a_argv)
{
    gtksourceview::init () ;

    Glib::RefPtr<SourceLanguagesManager> lang_mgr =
                                            SourceLanguagesManager::create () ;
    if (!lang_mgr) {
        cerr << "Could not create the languages manager\n" ;
        return -1 ;
    }

    Glib::RefPtr<SourceLanguage> lang ;
    for (int i=0 ; s_mime_types[i] ; ++i) {
        cout << "Looking for language that matches mime type '"
             << s_mime_types[i]
             << "'\n";
        lang = lang_mgr->get_language_from_mime_type (s_mime_types[i]) ;
        if (lang) {
            cout << "Found language '" << lang->get_name () << "'\n";
        } else {
            cout << "No language matching that mime type \n" ;
        }
    }
    return 0 ;
}

