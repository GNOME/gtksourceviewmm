/* gtksourceviewmm.h
 *
 * Based on gtksourceviewmm by Jae Jang
 * Copyright (C) 2005 Rob Page
 * Copyright (C) 2010, 2011 Krzesimir Nowak
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

/** @mainpage gtksourceviewmm - A C++ binding for gtksourceview
 *
 * @section introduction Introduction
 * gtksourceviewmm is a C++ wrapper for the gtksourceview widget library.
 * It offers all the power of gtksourceview with an interface familiar to C++
 * developers, including users of the gtkmm library.
 *
 * @section status Status
 * gtksourceviewmm wraps all relevant parts of the gtksourceview library and has
 * proven to be useable so far.
 *
 * @section sourcecode Source code
 *
 * Source code is developed on GNOME git and release tarballs are stored on
 * GNOME FTP site.
 *
 * @subsection browsecode Browse the source code
 *
 * See: <tt>http://git.gnome.org/browse/gtksourceviewmm/</tt>.
 *
 * @subsection bleedingedge Getting bleeding edge code from git
 *
 * <tt>git clone git://git.gnome.org/gtksourceviewmm gtksourceviewmm</tt>
 *
 * @subsection download Download releases tarballs
 *
 * See <tt>http://download.gnome.org/sources/gtksourceviewmm/</tt>.
 *
 * @section license License
 * gtksourceviewmm is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 * See the text of the LGPL for more details:
 * http://www.gnu.org/licenses/lgpl.html .
 *
 * @section Contact
 * To contact the developers of gtksourceviewmm please send an email to
 * the gtkmm mailing list at gtkmm-list@gnome.org. See
 * <tt>http://www.gtkmm.org/mailinglist.shtml</tt>. Or join @c c++ channel at
 * <tt>irc.gnome.org</tt>. See <tt>http://live.gnome.org/GnomeIrcChannels</tt>.
 *
 * @section about About
 * Initial work has been done by Rob Page.
 * Dodji Seketeli, Murray Cumming, Daniel Elstner, Jonathon Jongsma and
 * Krzesimir Nowak with contributions from other people wrote most of the code
 * of this project.
 */

/** @page migration Migration from 2.0 to 3.0
 *
 * This page lists some notable API/ABI breaks. Probably not all were listed,
 * but this is provided in hope that with help of this page migrating from
 * gtksourceviewmm-2.0 to 3.0 won't be a cause of headaches.
 *
 * <ul>
 * <li>Stuff marked as deprecated was removed of course.</li>
 * <li>Removed Source prefix from all types, SOURCE_ prefix from all enum value
 * names and source prefix from all file names. There is a helper script called
 * source_truncate.pl in git repository in codegen directory to aid programmer
 * in boring task of renaming everything.</li>
 * <li>"source-mark-updated" signal in Gsv::Buffer now takes Gtk::TextMark
 * instead of Mark.</li>
 * <li>Vfuncs in Gsv::CompletionProposal, Gsv::CompletionProvider
 * and Gsv::UndoManager are now private. They shouldn't be called directly
 * anyway - there are respective methods for this.</li>
 * <li>Some methods now takes std::string instead of Glib::ustring. These are:
 * <ul>
 * <li>Gsv::LanguageManager::get_search_path()</li>
 * <li>Gsv::LanguageManager::set_search_path()</li>
 * <li>Gsv::LanguageManager::get_language_ids()</li>
 * <li>Gsv::LanguageManager::get_language()</li>
 * <li>Gsv::LanguageManager::guess_language()</li>
 * <li>Gsv::StyleSchemeManager::set_search_path()</li>
 * <li>Gsv::StyleSchemeManager::get_search_path()</li>
 * <li>Gsv::StyleSchemeManager::append_search_path()</li>
 * <li>Gsv::StyleSchemeManager::prepend_search_path()</li>
 * <li>Gsv::StyleSchemeManager::get_scheme()</li>
 * <li>Gsv::StyleSchemeManager::get_scheme_ids()</li>
 * </ul></li>
 * <li>Gsv::Mark's constructor with category and name has parameter order
 * the same as C gtk_source_mark_new(). Previously parameter order was reversed,
 * because name parameter could be omitted - it has a default value of empty
 * string, which was interpreted as creating anonymous Gsv::Mark. Now
 * there is separate constructor for creating anonymous SourceMarks. If there
 * was:
 * @code
 * Glib::RefPtr<Gsv::Mark> sm (Gsv::Mark::create ("category", "name"));
 * @endcode
 * Now should be:
 * @code
 * Glib::RefPtr<Gsv::Mark> sm (Gsv::Mark::create ("name", "category"));
 * @endcode
 * If there was:
 * @code
 * Glib::RefPtr<Gsv::Mark> sm (Gsv::Mark::create ("category"));
 * @endcode
 * Nothing needs to be changed. If there was:
 * @code
 * Glib::RefPtr<Gsv::Mark> sm (Gsv::Mark::create ("category", ""));
 * @endcode
 * Now should be:
 * @code
 * Glib::RefPtr<Gsv::Mark> sm (Gsv::Mark::create ("category"));
 * @endcode
 * </li>
 * <li>If there is a code that somehow depended on Gsv::StyleScheme being
 * a Glib::Interface, then this code is wrong, because it should always be
 * a Glib::Object.</li>
 * <li>SourceIter is gone - all its features are now supported by Gtk::TextIter.
 * </li>
 * <li>Gsv::Completion is now a Glib::Object, not Gtk::Object. So it
 * should be used as Glib::RefPtr<Gsv::Completion> instead of plain
 * Gsv::Completion.</li>
 * <li>Namespace @b gtksourceview was renamed to @b Gsv. If there is a lot
 * of code using  @b gtksourceview namespace then a workaround would be creating
 * a backward compatibility header and including it a place included by affected
 * sources. A header could contain a lines like that:
 * @code
 * #ifndef GTKSOURCEVIEWMM_COMPAT_H
 * #define GTKSOURCEVIEWMM_COMPAT_H
 * namespace gtksourceview = Gsv;
 * #endif // GTKSOURCEVIEWMM_COMPAT_H
 * @endcode</li>
 * <li>Replaced Glib::*Handle<> with std::vector<> - that means that passing
 * std::list<> or std::deque<> is now not supported. Affected methods are:
 * <ul>
 * <li>Gsv::Buffer::get_source_marks_at_line()</li>
 * <li>Gsv::Buffer::get_source_marks_at_iter()</li>
 * <li>Gsv::Buffer::get_context_classes_at_iter()</li>
 * <li>Gsv::Completion::get_providers()</li>
 * <li>Gsv::Completion::show()</li>
 * <li>Gsv::CompletionContext::add_proposals()</li>
 * <li>Gsv::Language::get_mime_types()</li>
 * <li>Gsv::Language::get_globs()</li>
 * <li>Gsv::Language::get_style_ids()</li>
 * <li>Gsv::LanguageManager::get_search_path()</li>
 * <li>Gsv::LanguageManager::set_search_path()</li>
 * <li>Gsv::LanguageManager::get_language_ids()</li>
 * <li>Gsv::StyleScheme::get_authors()</li>
 * <li>Gsv::StyleSchemeManager::get_search_path()</li>
 * <li>Gsv::StyleSchemeManager::set_search_path()</li>
 * <li>Gsv::StyleSchemeManager::get_scheme_ids()</li>
 * </ul></li>
 * <li>Gsv::Markup now has operator const void* instead of operator bool, so
 * implicit casts to int are avoided.</li>
 * </ul>
 */

#ifndef _GTKSOURCEVIEWMM_H
#define _GTKSOURCEVIEWMM_H

#include <gtksourceviewmmconfig.h>
#include <gtksourceviewmm/init.h>
#include <gtksourceviewmm/buffer.h>
#include <gtksourceviewmm/completion.h>
#include <gtksourceviewmm/completionactivation.h>
#include <gtksourceviewmm/completioncontext.h>
#include <gtksourceviewmm/completioninfo.h>
#include <gtksourceviewmm/completionitem.h>
#include <gtksourceviewmm/completionproposal.h>
#include <gtksourceviewmm/completionprovider.h>
#include <gtksourceviewmm/completionwords.h>
#include <gtksourceviewmm/gutter.h>
#include <gtksourceviewmm/gutterrenderer.h>
#include <gtksourceviewmm/gutterrendererpixbuf.h>
#include <gtksourceviewmm/gutterrenderertext.h>
#include <gtksourceviewmm/language.h>
#include <gtksourceviewmm/languagemanager.h>
#include <gtksourceviewmm/mark.h>
#include <gtksourceviewmm/markattributes.h>
#include <gtksourceviewmm/markup.h>
#include <gtksourceviewmm/printcompositor.h>
#include <gtksourceviewmm/style.h>
#include <gtksourceviewmm/stylescheme.h>
#include <gtksourceviewmm/styleschememanager.h>
#include <gtksourceviewmm/undomanager.h>
#include <gtksourceviewmm/view.h>
#include <gtksourceviewmm/wrap_init.h>

#endif /* #ifndef _GTKSOURCEVIEWMM_H */

