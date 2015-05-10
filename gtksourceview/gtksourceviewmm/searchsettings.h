// -*- c++ -*-
// Generated by gmmproc 2.44.0 -- DO NOT MODIFY!
#ifndef _GTKSOURCEVIEWMM_SEARCHSETTINGS_H
#define _GTKSOURCEVIEWMM_SEARCHSETTINGS_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* searchsettings.h
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


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkSourceSearchSettings GtkSourceSearchSettings;
typedef struct _GtkSourceSearchSettingsClass GtkSourceSearchSettingsClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gsv
{ class SearchSettings_Class; } // namespace Gsv
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gsv
{

/** A GtkSourceSearchSettings object represents the settings of a search. The search settings can be associated with one or
 * several GtkSourceSearchContexts.
 *
 * @newin{3,10}
 */

class SearchSettings : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef SearchSettings CppObjectType;
  typedef SearchSettings_Class CppClassType;
  typedef GtkSourceSearchSettings BaseObjectType;
  typedef GtkSourceSearchSettingsClass BaseClassType;

private:  friend class SearchSettings_Class;
  static CppClassType searchsettings_class_;

private:
  // noncopyable
  SearchSettings(const SearchSettings&);
  SearchSettings& operator=(const SearchSettings&);

protected:
  explicit SearchSettings(const Glib::ConstructParams& construct_params);
  explicit SearchSettings(GtkSourceSearchSettings* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~SearchSettings();

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkSourceSearchSettings*       gobj()       { return reinterpret_cast<GtkSourceSearchSettings*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkSourceSearchSettings* gobj() const { return reinterpret_cast<GtkSourceSearchSettings*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkSourceSearchSettings* gobj_copy();

private:

public:
  SearchSettings();

  
  /** Sets the text to search. If text is NULL or is empty, the search will be disabled. A copy of text will be made, so
   * you can safely free text after a call to this function.
   *
   * You may be interested to call gtk_source_utils_unescape_search_text() before this function.
   *
   * @param search_text the nul-terminated text to search, or NULL to disable the search.
   *
   * @newin{3,10}
   */
  void set_search_text(const Glib::ustring& search_text);

  
  /** Gets the text to search. The return value must not be freed.
   *
   * You may be interested to call gtk_source_utils_escape_search_text() after this function.
   *
   * @return the text to search, or NULL if the search is disabled.
   *
   * @newin{3,10}
   */
  Glib::ustring get_search_text();

  
  /** Enables or disables the case sensitivity for the search.
   *
   * @param case_sensitive the setting.
   *
   * @newin{3,10}
   */
  void set_case_sensitive(bool case_sensitive);

  
  /**
   * @return whether the search is case sensitive.
   *
   * @newin{3,10}
   */
  bool get_case_sensitive();

  
  /** Change whether the search is done at word boundaries. If at_word_boundaries is TRUE, a search match must start and end
   * a word. The match can span multiple words. See also gtk_text_iter_starts_word() and gtk_text_iter_ends_word().
   *
   * @param at_word_boundaries the setting.
   *
   * @newin{3,10}
   */
  void set_at_word_boundaries(bool at_word_boundaries);

  
  /**
   * @return whether to search at word boundaries.
   *
   * @newin{3,10}
   */
  bool get_at_word_boundaries();

  
  /** Enables or disables the wrap around search. If wrap_around is TRUE, the forward search continues at the beginning of the
   * buffer if no search occurrences are found. Similarly, the backward search continues to search at the end of the buffer.
   *
   * @param wrap_around the setting.
   *
   * @newin{3,10}
   */
  void set_wrap_around(bool wrap_around);

  
  /**
   * @return whether to wrap around the search.
   *
   * @newin{3,10}
   */
  bool get_wrap_around();

  
  /** Enables or disables whether to search by regular expressions. If enabled, the "search-text" property contains the pattern of
   * the regular expression.
   *
   * @param regex_enabled the setting.
   *
   * @newin{3,10}
   */
  void set_regex_enabled(bool regex_enabled);

  
  /**
   * @param whether to search by regular expressions.
   *
   * @newin{3,10}
   */
  bool get_regex_enabled();
  /** Search at word boundaries.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_at_word_boundaries() ;

/** Search at word boundaries.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_at_word_boundaries() const;

  /** Case sensitive.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_case_sensitive() ;

/** Case sensitive.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_case_sensitive() const;

  /** Whether to search by regular expression.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_regex_enabled() ;

/** Whether to search by regular expression.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_regex_enabled() const;

  /** The text to search.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Glib::ustring > property_search_text() ;

/** The text to search.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::ustring > property_search_text() const;

  /** Wrap around.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_wrap_around() ;

/** Wrap around.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_wrap_around() const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} /* namespace Gsv */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gsv::SearchSettings
   */
  Glib::RefPtr<Gsv::SearchSettings> wrap(GtkSourceSearchSettings* object, bool take_copy = false);
}


#endif /* _GTKSOURCEVIEWMM_SEARCHSETTINGS_H */
