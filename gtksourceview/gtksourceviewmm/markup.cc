/* markup.cc
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

#include <gtksourceviewmm/markup.h>


namespace Gsv
{

Markup::Markup()
:
  markup_ ("")
{}

Markup::Markup(const Glib::ustring& markup)
:
  markup_ (markup)
{}

Markup::Markup(const char* markup)
:
  markup_ ((markup) ? markup : "")
{}

Markup::~Markup()
{}

Markup::Markup(const Markup& other)
:
  markup_ (other.markup_)
{}

Markup& Markup::operator=(const Markup& other)
{
  markup_ = other.markup_;
  return *this;
}

#ifndef GTKMM_DISABLE_DEPRECATED
Markup::operator const void*() const
{
  return !(markup_.empty()) ? GINT_TO_POINTER(1) : 0;
}
#endif // GTKMM_DISABLE_DEPRECATED

Markup::operator bool() const
{
  return !(markup_.empty());
}

bool Markup::equal(const Markup& rhs) const
{
  return (markup_.raw() == rhs.markup_.raw());
}

Glib::ustring Markup::get_string() const
{
  return markup_;
}

const char* Markup::get_c_str() const
{
  return markup_.c_str();
}

} // namespace Gsv
