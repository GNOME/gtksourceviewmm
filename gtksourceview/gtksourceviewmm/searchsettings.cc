// Generated by gmmproc 2.44.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtksourceviewmm/searchsettings.h>
#include <gtksourceviewmm/private/searchsettings_p.h>


/* searchsettings.cc
 *
 * Copyright (C) 2015 Christoph Brill
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <gtksourceview/gtksourcesearchsettings.h>
namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gsv::SearchSettings> wrap(GtkSourceSearchSettings* object, bool take_copy)
{
  return Glib::RefPtr<Gsv::SearchSettings>( dynamic_cast<Gsv::SearchSettings*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gsv
{


/* The *_Class implementation: */

const Glib::Class& SearchSettings_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SearchSettings_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_source_search_settings_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void SearchSettings_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* SearchSettings_Class::wrap_new(GObject* object)
{
  return new SearchSettings((GtkSourceSearchSettings*)object);
}


/* The implementation: */

GtkSourceSearchSettings* SearchSettings::gobj_copy()
{
  reference();
  return gobj();
}

SearchSettings::SearchSettings(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

SearchSettings::SearchSettings(GtkSourceSearchSettings* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


SearchSettings::~SearchSettings()
{}


SearchSettings::CppClassType SearchSettings::searchsettings_class_; // initialize static member

GType SearchSettings::get_type()
{
  return searchsettings_class_.init().get_type();
}


GType SearchSettings::get_base_type()
{
  return gtk_source_search_settings_get_type();
}


SearchSettings::SearchSettings()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(searchsettings_class_.init()))
{
  

}

void SearchSettings::set_search_text(const Glib::ustring& search_text)
{
  gtk_source_search_settings_set_search_text(gobj(), search_text.c_str());
}

Glib::ustring SearchSettings::get_search_text()
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_source_search_settings_get_search_text(gobj()));
}

void SearchSettings::set_case_sensitive(bool case_sensitive)
{
  gtk_source_search_settings_set_case_sensitive(gobj(), static_cast<int>(case_sensitive));
}

bool SearchSettings::get_case_sensitive()
{
  return gtk_source_search_settings_get_case_sensitive(gobj());
}

void SearchSettings::set_at_word_boundaries(bool at_word_boundaries)
{
  gtk_source_search_settings_set_at_word_boundaries(gobj(), static_cast<int>(at_word_boundaries));
}

bool SearchSettings::get_at_word_boundaries()
{
  return gtk_source_search_settings_get_at_word_boundaries(gobj());
}

void SearchSettings::set_wrap_around(bool wrap_around)
{
  gtk_source_search_settings_set_wrap_around(gobj(), static_cast<int>(wrap_around));
}

bool SearchSettings::get_wrap_around()
{
  return gtk_source_search_settings_get_wrap_around(gobj());
}

void SearchSettings::set_regex_enabled(bool regex_enabled)
{
  gtk_source_search_settings_set_regex_enabled(gobj(), static_cast<int>(regex_enabled));
}

bool SearchSettings::get_regex_enabled()
{
  return gtk_source_search_settings_get_regex_enabled(gobj());
}


Glib::PropertyProxy< bool > SearchSettings::property_at_word_boundaries() 
{
  return Glib::PropertyProxy< bool >(this, "at-word-boundaries");
}

Glib::PropertyProxy_ReadOnly< bool > SearchSettings::property_at_word_boundaries() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "at-word-boundaries");
}

Glib::PropertyProxy< bool > SearchSettings::property_case_sensitive() 
{
  return Glib::PropertyProxy< bool >(this, "case-sensitive");
}

Glib::PropertyProxy_ReadOnly< bool > SearchSettings::property_case_sensitive() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "case-sensitive");
}

Glib::PropertyProxy< bool > SearchSettings::property_regex_enabled() 
{
  return Glib::PropertyProxy< bool >(this, "regex-enabled");
}

Glib::PropertyProxy_ReadOnly< bool > SearchSettings::property_regex_enabled() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "regex-enabled");
}

Glib::PropertyProxy< Glib::ustring > SearchSettings::property_search_text() 
{
  return Glib::PropertyProxy< Glib::ustring >(this, "search-text");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > SearchSettings::property_search_text() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "search-text");
}

Glib::PropertyProxy< bool > SearchSettings::property_wrap_around() 
{
  return Glib::PropertyProxy< bool >(this, "wrap-around");
}

Glib::PropertyProxy_ReadOnly< bool > SearchSettings::property_wrap_around() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "wrap-around");
}


} // namespace Gsv

