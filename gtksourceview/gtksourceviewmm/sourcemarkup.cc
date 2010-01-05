/* markup.cc
 *
 * Copyright 2009 Krzesimir Nowak
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

#include <gtksourceviewmm/sourcemarkup.h>


namespace gtksourceview
{

SourceMarkup::SourceMarkup()
:
  markup_ ("")
{}

SourceMarkup::SourceMarkup(const Glib::ustring& markup)
:
  markup_ (markup)
{}

SourceMarkup::SourceMarkup(const char* markup)
:
  markup_ ((markup) ? markup : "")
{}

SourceMarkup::~SourceMarkup()
{}

SourceMarkup::SourceMarkup(const SourceMarkup& other)
:
  markup_ (other.markup_)
{}

SourceMarkup& SourceMarkup::operator=(const SourceMarkup& other)
{
  markup_ = other.markup_;
  return *this;
}

SourceMarkup::operator bool() const
{
  return !(markup_.empty());
}

bool SourceMarkup::equal(const SourceMarkup& rhs) const
{
  return (markup_.raw() == rhs.markup_.raw());
}

Glib::ustring SourceMarkup::get_string() const
{
  return markup_;
}

const char* SourceMarkup::get_c_str() const
{
  return markup_.c_str();
}

} // namespace gtksourceview

