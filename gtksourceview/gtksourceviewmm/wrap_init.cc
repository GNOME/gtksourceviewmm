
#include <glib.h>

// Disable the 'const' function attribute of the get_type() functions.
// GCC would optimize them out because we don't use the return value.
#undef  G_GNUC_CONST
#define G_GNUC_CONST /* empty */

#include <gtksourceviewmm/wrap_init.h>
#include <glibmm/error.h>
#include <glibmm/object.h>

// #include the widget headers so that we can call the get_type() static methods:

#include "sourcetagstyle.h"
#include "sourcestylescheme.h"
#include "sourcetag.h"
#include "sourcetagtable.h"
#include "sourcelanguage.h"
#include "sourcelanguagesmanager.h"
#include "sourcemarker.h"
#include "sourceview.h"
#include "sourcebuffer.h"

extern "C"
{

//Declarations of the *_get_type() functions:

GType gtk_source_buffer_get_type(void);
GType gtk_source_language_get_type(void);
GType gtk_source_languages_manager_get_type(void);
GType gtk_source_tag_get_type(void);
GType gtk_source_tag_table_get_type(void);
GType gtk_source_view_get_type(void);

//Declarations of the *_error_quark() functions:

} // extern "C"


//Declarations of the *_Class::wrap_new() methods, instead of including all the private headers:

namespace gtksourceview {  class SourceBuffer_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace gtksourceview {  class SourceLanguage_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace gtksourceview {  class SourceLanguagesManager_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace gtksourceview {  class SourceTag_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace gtksourceview {  class SourceTagTable_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace gtksourceview {  class SourceView_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }

namespace gtksourceview { 

void wrap_init()
{
  // Register Error domains:

// Map gtypes to gtkmm wrapper-creation functions:
  Glib::wrap_register(gtk_source_buffer_get_type(), &gtksourceview::SourceBuffer_Class::wrap_new);
  Glib::wrap_register(gtk_source_language_get_type(), &gtksourceview::SourceLanguage_Class::wrap_new);
  Glib::wrap_register(gtk_source_languages_manager_get_type(), &gtksourceview::SourceLanguagesManager_Class::wrap_new);
  Glib::wrap_register(gtk_source_tag_get_type(), &gtksourceview::SourceTag_Class::wrap_new);
  Glib::wrap_register(gtk_source_tag_table_get_type(), &gtksourceview::SourceTagTable_Class::wrap_new);
  Glib::wrap_register(gtk_source_view_get_type(), &gtksourceview::SourceView_Class::wrap_new);

  // Register the gtkmm gtypes:
  gtksourceview::SourceBuffer::get_type();
  gtksourceview::SourceLanguage::get_type();
  gtksourceview::SourceLanguagesManager::get_type();
  gtksourceview::SourceTag::get_type();
  gtksourceview::SourceTagTable::get_type();
  gtksourceview::SourceView::get_type();

} // wrap_init()

} //gtksourceview


