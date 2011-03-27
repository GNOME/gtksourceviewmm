// standard
#include <iostream>
#include <string>
#include <vector>
// gtkmm
#include <gtkmm.h>
// gtksourceviewmm
#include <gtksourceviewmm/languagemanager.h>
#include <gtksourceviewmm/init.h>

int
main (int /* argc */, char** /* argv */)
{
  Gsv::init () ;

  Glib::RefPtr<Gsv::LanguageManager> lang_mgr = Gsv::LanguageManager::create ();
  if (!lang_mgr)
  {
    std::cerr << "Could not create the language manager.\n";
    return -1;
  }

  std::vector<std::string> mime_types;
  mime_types.push_back ("text/xml");
  mime_types.push_back ("text/html");
  mime_types.push_back ("text/x-c");
  mime_types.push_back ("text/x-c++");

  Glib::RefPtr<Gsv::Language> lang;

  unsigned int size (mime_types.size ());
  for (unsigned int idx (0); idx < size ; ++idx)
  {
    const std::string mime_type (mime_types[idx]);

    std::cout << "Looking for language that matches mime type '"
              << mime_type
              << "'.\n";
    lang = lang_mgr->guess_language (std::string (), mime_type);
    if (lang)
    {
      std::cout << "Found language '" << lang->get_name () << "'.\n";
    }
    else
    {
      std::cout << "No language matching that mime type.\n";
    }
  }
  return 0 ;
}

