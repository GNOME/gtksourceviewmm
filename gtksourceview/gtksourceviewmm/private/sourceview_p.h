// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKSOURCEVIEWMM_SOURCEVIEW_P_H
#define _GTKSOURCEVIEWMM_SOURCEVIEW_P_H
#include <gtkmm/private/textview_p.h>

#include <glibmm/class.h>

namespace gtksourceview
{

class SourceView_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef SourceView CppObjectType;
  typedef GtkSourceView BaseObjectType;
  typedef GtkSourceViewClass BaseClassType;
  typedef Gtk::TextView_Class CppClassParent;
  typedef GtkTextViewClass BaseClassParent;

  friend class SourceView;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();

  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void redo_callback(GtkSourceView* self);
  static void undo_callback(GtkSourceView* self);

  //Callbacks (virtual functions):
};


} // namespace gtksourceview

#endif /* _GTKSOURCEVIEWMM_SOURCEVIEW_P_H */

