#include <iostream>
#include <gtkmm.h>
#include <gtksourceviewmm/sourcelanguagemanager.h>
#include <gtksourceviewmm/init.h>
#include <gtksourceview/gtksourcelanguagemanager.h>

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
main (int argc, char **argv)
{
    if (argc || argv) {}

    gtksourceview::init () ;

    Glib::RefPtr<SourceLanguageManager> lang_mgr =
                                            SourceLanguageManager::create () ;
    if (!lang_mgr) {
        cerr << "Could not create the languages manager" << std::endl;
        return -1 ;
    }

    Glib::RefPtr<SourceLanguage> lang;
    for (int i=0 ; s_mime_types[i] ; ++i) {
        cout << "Looking for language that matches mime type '"
             << s_mime_types[i]
             << "'" << std::endl;
        lang = lang_mgr->guess_language(std::string(), s_mime_types[i]);
        if (lang) {
            cout << "Found language '" << lang->get_name () << "'" << std::endl;
        } else {
            cout << "No language matching that mime type" << std::endl;
        }
    }
    return 0 ;
}

