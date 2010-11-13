#include <iostream>
#include <string>
#include <vector>
#include <gtkmm.h>
#include <gtksourceviewmm/sourcelanguagemanager.h>
#include <gtksourceviewmm/init.h>

using namespace std ;
using namespace gtksourceview ;

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

    vector<string> mime_types;
    mime_types.push_back ("text/xml");
    mime_types.push_back ("text/html");
    mime_types.push_back ("text/x-c");
    mime_types.push_back ("text/x-c++");

    Glib::RefPtr<SourceLanguage> lang;
    unsigned int size (mime_types.size ());
    for (unsigned int i=0 ; i < size ; ++i) {
        cout << "Looking for language that matches mime type '"
             << mime_types[i]
             << "'" << std::endl;
        lang = lang_mgr->guess_language(std::string(), mime_types[i]);
        if (lang) {
            cout << "Found language '" << lang->get_name () << "'" << std::endl;
        } else {
            cout << "No language matching that mime type" << std::endl;
        }
    }
    return 0 ;
}

