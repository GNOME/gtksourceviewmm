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

namespace Gsv
{
/** It is just a class holding markup string.
 *
 * This class exists because now nice constructor overload could be used in some
 * places.
 *
 * @newin{2,10}
 */
class Markup
{
public:
  /** Creates empty Markup.
   *
   * @return A new Markup.
   *
   * @newin{2,10}
   */
  Markup();

  /** Creates Markup containing text from @a markup.
   *
   * @param markup A markup string.
   *
   * @return A new Markup.
   *
   * @newin{2,10}
   */
  explicit Markup(const Glib::ustring& markup);

  /** Creates Markup containing text from @a markup.
   *
   * @param markup A markup C string.
   *
   * @return A new Markup.
   *
   * @newin{2,10}
   */
  explicit Markup(const char* markup);

  ~Markup();

  /** Creates Markup containing text from @a other Markup.
   *
   * @param other Other Markup.
   *
   * @return A new Markup.
   *
   * @newin{2,10}
   */
  Markup(const Markup& other);

  /** Assigns contents of @a other Markup to this one.
   *
   * @param other Other Markup.
   *
   * @return This Markup.
   *
   * @newin{2,10}
   */
  Markup& operator=(const Markup& other);

  /** This typedef is just to make it more obvious that
   * our operator const void*() should be used like operator bool().
   */
  typedef const void* BoolExpr;

  /** Checks if Markup is not empty.
   * For instance,
   * @code
   * if(markup)
   *   do_something()
   * @endcode
   *
   * @return @c true if Markup is not empty, otherwise @c false.
   *
   * @newin{2,10}
   */
  operator BoolExpr() const;

  /** Checks if @a other Markup is the same as this one.
   *
   * @param other Other Markup.
   *
   * @return @c true if both this and @a other Markup are equal.
   *
   * @newin{2,10}
   */
  bool equal(const Markup& other) const;

  /** Get the string representation of the Markup.
   *
   * @return A string holding markup.
   *
   * @newin{2,10}
   */
  Glib::ustring get_string() const;

  /** Get the C string representation of the Markup.
   *
   * @return A C string holding markup.
   *
   * @newin{2,10}
   */
  const char* get_c_str()  const;

protected:
  Glib::ustring markup_;
};

/** See Markup::equal()
 *
 * @param lhs First Markup to compare.
 * @param rhs Second Markup to compare.
 *
 * @return Whether @a lhs is different from @a rhs.
 *
 * @relates Gsv::Markup
 *
 * @newin{2,10}
 */
inline bool operator==(const Markup& lhs, const Markup& rhs)
  { return lhs.equal(rhs); }

/** See Markup::equal()
 *
 * @param lhs First Markup to compare.
 * @param rhs Second Markup to compare.
 *
 * @return Whether @a lhs is different from @a rhs.
 *
 * @relates Gsv::Markup
 *
 * @newin{2,10}
 */
inline bool operator!=(const Markup& lhs, const Markup& rhs)
  { return !lhs.equal(rhs); }


#ifndef DOXYGEN_SHOULD_SKIP_THIS

struct SourceMarkup_Traits : public Glib::Container_Helpers::TypeTraits<Glib::ustring>
{
  typedef Gsv::Markup CppType;

  static const char* to_c_type(const Markup& markup) { return markup.get_c_str(); }
  static Markup     to_cpp_type(const char* str)     { return Markup(str);   }
};

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Gsv


#ifndef DOXYGEN_SHOULD_SKIP_THIS

namespace Glib
{

template <>
class Value<Gsv::Markup> : public Glib::ValueBase_String
{
public:
  typedef Gsv::Markup CppType;

  void set(const Gsv::Markup& data) { set_cstring(data.get_c_str());      }
  Gsv::Markup get() const           { return Gsv::Markup(get_cstring()); }
};

} // namespace Glib

#endif // DOXYGEN_SHOULD_SKIP_THIS

#endif // _GTKSOURCEVIEWMM_MARKUP_H

