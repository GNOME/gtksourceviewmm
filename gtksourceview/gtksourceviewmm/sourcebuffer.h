// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKSOURCEVIEWMM_SOURCEBUFFER_H
#define _GTKSOURCEVIEWMM_SOURCEBUFFER_H

#include <glibmm.h>

/* sourcebuffer.hg
 * 
 * Copyright (C) 2005-2006 The gtksourceviewmm development team
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

#include <gtkmm/textbuffer.h>
#include <gtksourceviewmm/sourcelanguage.h>
#include <gtksourceviewmm/sourcemarker.h>
#include <gtksourceviewmm/sourcetagstyle.h>
#include <gtksourceviewmm/sourcetagtable.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkSourceBuffer GtkSourceBuffer;
typedef struct _GtkSourceBufferClass GtkSourceBufferClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace gtksourceview
{ class SourceBuffer_Class; } // namespace gtksourceview
namespace gtksourceview
{

/** Multi-line source editing widget. It displays a Gtk::SourceBuffer.
 */


class SourceBuffer : public Gtk::TextBuffer
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef SourceBuffer CppObjectType;
  typedef SourceBuffer_Class CppClassType;
  typedef GtkSourceBuffer BaseObjectType;
  typedef GtkSourceBufferClass BaseClassType;

private:  friend class SourceBuffer_Class;
  static CppClassType sourcebuffer_class_;

private:
  // noncopyable
  SourceBuffer(const SourceBuffer&);
  SourceBuffer& operator=(const SourceBuffer&);

protected:
  explicit SourceBuffer(const Glib::ConstructParams& construct_params);
  explicit SourceBuffer(GtkSourceBuffer* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~SourceBuffer();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkSourceBuffer*       gobj()       { return reinterpret_cast<GtkSourceBuffer*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkSourceBuffer* gobj() const { return reinterpret_cast<GtkSourceBuffer*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkSourceBuffer* gobj_copy();

private:


protected:
  SourceBuffer();
  explicit SourceBuffer(Glib::RefPtr<SourceTagTable> &tagtable);
  explicit SourceBuffer (Glib::RefPtr<SourceLanguage> &language) ;

public:

   
  static Glib::RefPtr<SourceBuffer> create(Glib::RefPtr<SourceTagTable> & tagtable);

   
  static Glib::RefPtr<SourceBuffer> create(Glib::RefPtr<SourceLanguage> & language);


  bool get_check_brackets();
  
  void set_check_brackets(bool check_brackets);

  
  void set_bracket_match_style(const SourceTagStyle& style);

  
  bool get_highlight();
  
  void set_highlight(bool highlight=true);
  
  int get_max_undo_levels();
  
  void set_max_undo_levels(int max_undo_levels);

  
  Glib::RefPtr<SourceLanguage> get_language();
  
  void set_language(Glib::RefPtr<SourceLanguage> language);

  
  gunichar get_escape_char();
  
  void set_escape_char(gunichar escape_char);

  
  bool can_undo();
  
  bool can_redo();

  
  void undo();
  
  void redo();

  
  void begin_not_undoable_action();
  
  void end_notundoable_action();

  
  Glib::RefPtr<SourceMarker> create_marker(const Glib::ustring& name, const Glib::ustring& type, const Gtk::TextIter& where);

  
  void move_marker(Glib::RefPtr<SourceMarker>, const Gtk::TextIter& where);

  
  void delete_marker(Glib::RefPtr<SourceMarker>);

  
  Glib::RefPtr<SourceMarker> get_marker(const Glib::ustring& name);

  
  Glib::SListHandle<Glib::RefPtr<SourceMarker> > get_markers_in_region(const Gtk::TextIter& begin, const Gtk::TextIter& end);

  
  Glib::RefPtr<SourceMarker> get_first_marker();

  
  Glib::RefPtr<SourceMarker> get_last_marker();

  Gtk::TextIter get_iter_at_marker(Glib::RefPtr<SourceMarker> marker);
  

  Glib::RefPtr<SourceMarker> get_next_marker(Gtk::TextIter& iter);
  
  Glib::RefPtr<SourceMarker> get_prev_marker(Gtk::TextIter& iter);

  
  Glib::SignalProxy1< void,bool > signal_can_redo();

  
  Glib::SignalProxy1< void,bool > signal_can_undo();

  
  Glib::SignalProxy2< void,Gtk::TextIter &,Gtk::TextIter & > signal_highlight_updated();

  
  Glib::SignalProxy1< void,Gtk::TextIter & > signal_marker_updated();


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  virtual void on_can_redo(bool can_redo);
  virtual void on_can_undo(bool can_redo);
  virtual void on_highlight_updated(Gtk::TextIter & start, Gtk::TextIter & end);
  virtual void on_marker_updated(Gtk::TextIter & where);


};

} /* namespace gtksourceview */


namespace Glib
{
  /** @relates gtksourceview::SourceBuffer
   * @param object The C instance
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   */
  Glib::RefPtr<gtksourceview::SourceBuffer> wrap(GtkSourceBuffer* object, bool take_copy = false);
}


#endif /* _GTKSOURCEVIEWMM_SOURCEBUFFER_H */

