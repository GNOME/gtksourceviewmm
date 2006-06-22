// Generated by gtkmmproc -- DO NOT MODIFY!

#include <gtksourceviewmm/sourcelanguage.h>
#include <gtksourceviewmm/private/sourcelanguage_p.h>

#include <gtksourceview/gtksourcelanguage.h>
#include <gtksourceview/gtksourceview-typebuiltins.h>
/* GtkSourceView::SourceView
 *
 * Copyright 2004-2005 Jae Jang
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


namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<gtksourceview::SourceLanguage> wrap(GtkSourceLanguage* object, bool take_copy)
{
  return Glib::RefPtr<gtksourceview::SourceLanguage>( dynamic_cast<gtksourceview::SourceLanguage*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace gtksourceview
{


/* The *_Class implementation: */

const Glib::Class& SourceLanguage_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SourceLanguage_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_source_language_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  }

  return *this;
}

void SourceLanguage_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

}


Glib::ObjectBase* SourceLanguage_Class::wrap_new(GObject* object)
{
  return new SourceLanguage((GtkSourceLanguage*)object);
}


/* The implementation: */

GtkSourceLanguage* SourceLanguage::gobj_copy()
{
  reference();
  return gobj();
}

SourceLanguage::SourceLanguage(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{}

SourceLanguage::SourceLanguage(GtkSourceLanguage* castitem)
:
  Glib::Object((GObject*)(castitem))
{}

SourceLanguage::~SourceLanguage()
{}


SourceLanguage::CppClassType SourceLanguage::sourcelanguage_class_; // initialize static member

GType SourceLanguage::get_type()
{
  return sourcelanguage_class_.init().get_type();
}

GType SourceLanguage::get_base_type()
{
  return gtk_source_language_get_type();
}


SourceLanguage::SourceLanguage()
:
  Glib::ObjectBase(0), //Mark this class as gtkmmproc-generated, rather than a custom class, to allow vfunc optimisations.
  Glib::Object(Glib::ConstructParams(sourcelanguage_class_.init()))
{
  }

Glib::ustring SourceLanguage::get_id()
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_source_language_get_id(gobj()));
}

Glib::ustring SourceLanguage::get_name()
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_source_language_get_name(gobj()));
}

Glib::ustring SourceLanguage::get_section()
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_source_language_get_section(gobj()));
}

Glib::SListHandle<Glib::RefPtr<SourceTag> > SourceLanguage::get_tags()
{
  return Glib::SListHandle<Glib::RefPtr<SourceTag> >(gtk_source_language_get_tags(gobj()), Glib::OWNERSHIP_SHALLOW);
}

gunichar SourceLanguage::get_escape_char()
{
  return gtk_source_language_get_escape_char(gobj());
}

Glib::SListHandle<Glib::ustring> SourceLanguage::get_mime_types() const
{
  return Glib::SListHandle<Glib::ustring>(gtk_source_language_get_mime_types(const_cast<GtkSourceLanguage*>(gobj())), Glib::OWNERSHIP_DEEP);
}

void SourceLanguage::set_mime_types(const Glib::SListHandle<const Glib::ustring>& mime_types)
{
  gtk_source_language_set_mime_types(gobj(), mime_types.data());
}

Glib::RefPtr<SourceStyleScheme> SourceLanguage::get_style_scheme()
{
  return Glib::wrap(gtk_source_language_get_style_scheme(gobj()));
}

void SourceLanguage::set_style_scheme(Glib::RefPtr<SourceStyleScheme> scheme)
{
  gtk_source_language_set_style_scheme(gobj(), Glib::unwrap(scheme));
}

SourceTagStyle SourceLanguage::get_tag_style(const Glib::ustring& tag_id)
{
  return Glib::wrap (gtk_source_language_get_tag_style(gobj(), tag_id.c_str()));
}

void SourceLanguage::set_tag_style(const Glib::ustring& tag_id, const SourceTagStyle& style)
{
  gtk_source_language_set_tag_style(gobj(), tag_id.c_str(), style.gobj());
}

SourceTagStyle SourceLanguage::get_tag_default_style(const Glib::ustring& tag_id)
{
  return Glib::wrap (gtk_source_language_get_tag_default_style(gobj(), tag_id.c_str()));
}


} // namespace gtksourceview


