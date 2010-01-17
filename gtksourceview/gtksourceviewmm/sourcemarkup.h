#ifndef _GTKSOURCEVIEWMM_MARKUP_H
#define _GTKSOURCEVIEWMM_MARKUP_H

/* markup.h
 *
 * Based on Gtk::StockID.
 *
 * Copyright (C) 2009, 2010 Krzesimir Nowak
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <glibmm/ustring.h>
#include <glibmm/containerhandle_shared.h>

namespace gtksourceview
{
/** It is just a class holding markup string.
 *
 * This class exists because now nice constructor overload could be used in some
 * places.
 *
 * @newin{2,10}
 */
class SourceMarkup
{
public:
  /** Creates empty SourceMarkup.
   *
   * @return A new SourceMarkup.
   *
   * @newin{2,10}
   */
  SourceMarkup();

  /** Creates SourceMarkup containing text from @a markup.
   *
   * @param markup A markup string.
   *
   * @return A new SourceMarkup.
   *
   * @newin{2,10}
   */
  explicit SourceMarkup(const Glib::ustring& markup);

  /** Creates SourceMarkup containing text from @a markup.
   *
   * @param markup A markup C string.
   *
   * @return A new SourceMarkup.
   *
   * @newin{2,10}
   */
  explicit SourceMarkup(const char* markup);

  ~SourceMarkup();

  /** Creates SourceMarkup containing text from @a other SourceMarkup.
   *
   * @param other Other SourceMarkup.
   *
   * @return A new SourceMarkup.
   *
   * @newin{2,10}
   */
  SourceMarkup(const SourceMarkup& other);

  /** Assigns contents of @a other SourceMarkup to this one.
   *
   * @param other Other SourceMarkup.
   *
   * @return This SourceMarkup.
   *
   * @newin{2,10}
   */
  SourceMarkup& operator=(const SourceMarkup& other);

  /** Checks if SourceMarkup is not empty.
   *
   * @return @c true if SourceMarkup is not empty, otherwise @c false.
   *
   * @newin{2,10}
   */
  operator bool() const;

  /** Checks if @a other SourceMarkup is the same as this one.
   *
   * @param other Other SourceMarkup.
   *
   * @return @c true if both this and @a other SourceMarkup are equal.
   *
   * @newin{2,10}
   */
  bool equal(const SourceMarkup& other) const;

  /** Get the string representation of the SourceMarkup.
   *
   * @return A string holding markup.
   *
   * @newin{2,10}
   */
  Glib::ustring get_string() const;

  /** Get the C string representation of the SourceMarkup.
   *
   * @return A C string holding markup.
   *
   * @newin{2,10}
   */
  const char* get_c_str()  const;

protected:
  Glib::ustring markup_;
};

/** See SourceMarkup::equal()
 *
 * @relates gtksourceview::SourceMarkup
 *
 * @newin{2,10}
 */
inline bool operator==(const SourceMarkup& lhs, const SourceMarkup& rhs)
  { return lhs.equal(rhs); }

/** See SourceMarkup::equal()
 *
 * @relates gtksourceview::SourceMarkup
 *
 * @newin{2,10}
 */
inline bool operator!=(const SourceMarkup& lhs, const SourceMarkup& rhs)
  { return !lhs.equal(rhs); }


#ifndef DOXYGEN_SHOULD_SKIP_THIS

struct SourceMarkup_Traits : public Glib::Container_Helpers::TypeTraits<Glib::ustring>
{
  typedef gtksourceview::SourceMarkup CppType;

  static const char* to_c_type(const SourceMarkup& markup) { return markup.get_c_str(); }
  static SourceMarkup     to_cpp_type(const char* str)     { return SourceMarkup(str);   }
};

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace gtksourceview


#ifndef DOXYGEN_SHOULD_SKIP_THIS

namespace Glib
{

template <>
class Value<gtksourceview::SourceMarkup> : public Glib::ValueBase_String
{
public:
  typedef gtksourceview::SourceMarkup CppType;

  void set(const gtksourceview::SourceMarkup& data) { set_cstring(data.get_c_str());      }
  gtksourceview::SourceMarkup get() const           { return gtksourceview::SourceMarkup(get_cstring()); }
};

} // namespace Glib

#endif // DOXYGEN_SHOULD_SKIP_THIS

#endif // _GTKSOURCEVIEWMM_MARKUP_H

