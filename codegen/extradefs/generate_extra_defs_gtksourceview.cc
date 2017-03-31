/* generate_extra_defs_gtksourceview.cc
 *
 * Copyright (C) 2001 The Free Software Foundation
 * Copyright (C) 2009 Krzesimir Nowak
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

#include <gtksourceview/gtksource.h>
#include <gtksourceview/completion-providers/words/gtksourcecompletionwords.h>

int main ()
{
  gtk_init();

  std::cout << get_defs (GTK_SOURCE_TYPE_BUFFER)
            << get_defs (GTK_SOURCE_TYPE_COMPLETION)
            << get_defs (GTK_SOURCE_TYPE_COMPLETION_CONTEXT)
            << get_defs (GTK_SOURCE_TYPE_COMPLETION_INFO)
            << get_defs (GTK_SOURCE_TYPE_COMPLETION_ITEM)
            << get_defs (GTK_SOURCE_TYPE_COMPLETION_PROPOSAL)
            << get_defs (GTK_SOURCE_TYPE_COMPLETION_PROVIDER)
            << get_defs (GTK_SOURCE_TYPE_GUTTER)
            << get_defs (GTK_SOURCE_TYPE_GUTTER_RENDERER)
            << get_defs (GTK_SOURCE_TYPE_GUTTER_RENDERER_PIXBUF)
            << get_defs (GTK_SOURCE_TYPE_GUTTER_RENDERER_TEXT)
            << get_defs (GTK_SOURCE_TYPE_LANGUAGE)
            << get_defs (GTK_SOURCE_TYPE_LANGUAGE_MANAGER)
            << get_defs (GTK_SOURCE_TYPE_MARK)
            << get_defs (GTK_SOURCE_TYPE_MARK_ATTRIBUTES)
            << get_defs (GTK_SOURCE_TYPE_PRINT_COMPOSITOR)
            << get_defs (GTK_SOURCE_TYPE_SEARCH_CONTEXT)
            << get_defs (GTK_SOURCE_TYPE_SEARCH_SETTINGS)
            << get_defs (GTK_SOURCE_TYPE_STYLE)
            << get_defs (GTK_SOURCE_TYPE_STYLE_SCHEME)
            << get_defs (GTK_SOURCE_TYPE_STYLE_SCHEME_CHOOSER)
            << get_defs (GTK_SOURCE_TYPE_STYLE_SCHEME_CHOOSER_BUTTON)
            << get_defs (GTK_SOURCE_TYPE_STYLE_SCHEME_CHOOSER_WIDGET)
            << get_defs (GTK_SOURCE_TYPE_STYLE_SCHEME_MANAGER)
            << get_defs (GTK_SOURCE_TYPE_UNDO_MANAGER)
            << get_defs (GTK_SOURCE_TYPE_VIEW)

            << get_defs (GTK_SOURCE_TYPE_COMPLETION_WORDS);
  return 0;
}
