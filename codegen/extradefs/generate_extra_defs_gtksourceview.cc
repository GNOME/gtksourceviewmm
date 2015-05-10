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

#include <gtksourceview/gtksourcebuffer.h>
#include <gtksourceview/gtksourcecompletion.h>
#include <gtksourceview/gtksourcecompletioncontext.h>
#include <gtksourceview/gtksourcecompletioninfo.h>
#include <gtksourceview/gtksourcecompletionitem.h>
#include <gtksourceview/gtksourcecompletionproposal.h>
#include <gtksourceview/gtksourcecompletionprovider.h>
#include <gtksourceview/gtksourcegutter.h>
#include <gtksourceview/gtksourcegutterrenderer.h>
#include <gtksourceview/gtksourcegutterrendererpixbuf.h>
#include <gtksourceview/gtksourcegutterrenderertext.h>
#include <gtksourceview/gtksourcelanguage.h>
#include <gtksourceview/gtksourcelanguagemanager.h>
#include <gtksourceview/gtksourcemark.h>
#include <gtksourceview/gtksourcemarkattributes.h>
#include <gtksourceview/gtksourceprintcompositor.h>
#include <gtksourceview/gtksourcesearchcontext.h>
#include <gtksourceview/gtksourcesearchsettings.h>
#include <gtksourceview/gtksourcestyle.h>
#include <gtksourceview/gtksourcestylescheme.h>
#include <gtksourceview/gtksourcestyleschememanager.h>
#include <gtksourceview/gtksourceundomanager.h>
#include <gtksourceview/gtksourceview.h>
#include <gtksourceview/gtksourceview-typebuiltins.h>

#include <gtksourceview/completion-providers/words/gtksourcecompletionwords.h>

int main (int argc, char *argv[])
{
  gtk_init(&argc, &argv);

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
            << get_defs (GTK_SOURCE_TYPE_STYLE_SCHEME_MANAGER)
            << get_defs (GTK_SOURCE_TYPE_UNDO_MANAGER)
            << get_defs (GTK_SOURCE_TYPE_VIEW)

            << get_defs (GTK_SOURCE_TYPE_COMPLETION_WORDS);
  return 0;
}
