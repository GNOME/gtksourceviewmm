#ifndef _GTKSOURCEVIEWMM_MARKUP_H
#define _GTKSOURCEVIEWMM_MARKUP_H

/* markup.h
 *
 * Copyright (C) 2009 Krzesimir Nowak
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

class SourceMarkup
{
public:
  SourceMarkup();

  explicit SourceMarkup(const Glib::ustring& id);

  explicit SourceMarkup(const char* id);

  ~SourceMarkup();

  SourceMarkup(const SourceMarkup& other);

  SourceMarkup& operator=(const SourceMarkup& other);

  operator bool() const;

  bool equal(const SourceMarkup& rhs) const;

  Glib::ustring get_string() const;

  const char* get_c_str()  const;

protected:
  Glib::ustring markup_;
};

inline bool operator==(const SourceMarkup& lhs, const SourceMarkup& rhs)
  { return lhs.equal(rhs); }

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

