/* $Id: generate_defs_gtk.cc,v 1.1.1.1 2006/05/28 18:56:55 rob Exp $ */

/* generate_defs_gtk.cc
 *
 * Copyright (C) 2001 The Free Software Foundation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
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

#include "glibmm_generate_extra_defs/generate_extra_defs.h"

#include <gtksourceview/gtksourcebuffer.h>
#include <gtksourceview/gtksourceiter.h>
#include <gtksourceview/gtksourcelanguage.h>
#include <gtksourceview/gtksourcelanguagemanager.h>
#include <gtksourceview/gtksourcemark.h>
#include <gtksourceview/gtksourcestyle.h>
#include <gtksourceview/gtksourcestylescheme.h>
#include <gtksourceview/gtksourcestyleschememanager.h>
#include <gtksourceview/gtksourceview.h>
#include <gtksourceview/gtksourceview-typebuiltins.h>

int main (int argc, char *argv[])
{
  gtk_init(&argc, &argv);

  std::cout << get_defs ( GTK_TYPE_SOURCE_BUFFER )
	        << get_defs ( GTK_TYPE_SOURCE_LANGUAGE )
	        << get_defs ( GTK_TYPE_SOURCE_LANGUAGE_MANAGER )
	        << get_defs ( GTK_TYPE_SOURCE_MARK )
	        << get_defs ( GTK_TYPE_SOURCE_STYLE )
	        << get_defs ( GTK_TYPE_SOURCE_STYLE_SCHEME )
	        << get_defs ( GTK_TYPE_SOURCE_STYLE_SCHEME_MANAGER )
	        << get_defs ( GTK_TYPE_SOURCE_VIEW )
	        << get_defs ( GTK_TYPE_SOURCE_SEARCH_FLAGS );
  return 0;
}
