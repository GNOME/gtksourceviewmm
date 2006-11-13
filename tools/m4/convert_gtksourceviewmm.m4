#SourceLanguage
_CONVERSION(`GtkSourceLanguage*',`Glib::RefPtr<SourceLanguage>',`Glib::wrap($3)')
_CONVERSION(`GtkSourceLanguage*',`Glib::RefPtr<const SourceLanguage>',`Glib::wrap($3)')
_CONVERSION(`Glib::RefPtr<SourceLanguage>',`GtkSourceLanguage*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`Glib::RefPtr<SourceLanguage>&',`GtkSourceLanguage*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`GSList*',`Glib::SListHandle<Glib::ustring>', `$2($3, Glib::OWNERSHIP_DEEP)')
_CONVERSION(`GList*',`Glib::ListHandle<Glib::ustring>', `$2($3, Glib::OWNERSHIP_DEEP)')
_CONVERSION(`const Glib::SListHandle<const Glib::ustring>&',`const GSList*', `$3.data()')
_CONVERSION(`Glib::ListHandle<const Glib::ustring>&',`const GSList*', `$3.data()')
_CONVERSION(`Glib::ListHandle<Glib::ustring>',`GSList*', `$3.data()')

#SourceTagStyle
_CONVERSION(`GtkSourceTagStyle*',`SourceTagStyle',`Glib::wrap ($3)')
_CONVERSION(`SourceTagStyle&',`const GtkSourceTagStyle*',`$3.gobj()')
_CONVERSION(`const SourceTagStyle&',`const GtkSourceTagStyle*',`$3.gobj()')

#SourceTag
_CONVERSION(`const Glib::SListHandle<Glib::RefPtr<Gtk::TextTag> >&',`const GSList*',`$3.data()')
_CONVERSION(`const Glib::SListHandle<Glib::RefPtr<SourceTag> >&',`const GSList*',`$3.data()')
_CONVERSION(`Glib::SListHandle<Glib::RefPtr<SourceTag> >',`GSList*',`$3.data()')
_CONVERSION(`GSList*',`Glib::SListHandle<Glib::RefPtr<SourceTag> >',`$2($3, Glib::OWNERSHIP_SHALLOW)')
_CONVERSION(`GSList*',`Glib::SListHandle<Glib::RefPtr<const SourceTag> >',`$2($3, Glib::OWNERSHIP_SHALLOW)')

#SourceTagTable
_CONVERSION(`Glib::RefPtr<SourceTagTable>&', `GtkSourceTagTable*', __CONVERT_REFPTR_TO_P)


#SourceStyleScheme
_CONVERSION(`GtkSourceStyleScheme*',`Glib::RefPtr<SourceStyleScheme>',`Glib::wrap($3)')
_CONVERSION(`GtkSourceStyleScheme*',`Glib::RefPtr<const SourceStyleScheme>',`Glib::wrap($3)')
_CONVERSION(`Glib::RefPtr<SourceStyleScheme>',`GtkSourceStyleScheme*',__CONVERT_REFPTR_TO_P)

#SourceMarker
_CONVERSION(`GtkSourceMarker*',`Glib::RefPtr<SourceMarker>',`Glib::wrap($3)')
_CONVERSION(`GtkSourceMarker*',`Glib::RefPtr<const SourceMarker>',`Glib::wrap($3)')
_CONVERSION(`Glib::RefPtr<SourceMarker>',`GtkSourceMarker*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`Glib::RefPtr<SourceMarker>&',`GtkSourceMarker*',__CONVERT_REFPTR_TO_P)
#_CONVERSION(`GSList*',`Glib::SListHandle<Glib::RefPtr<SourceMarker> >', __FL2H_SHALLOW)
_CONVERSION(`GSList*',`Glib::SListHandle<Glib::RefPtr<SourceMarker> >', `$2($3, Glib::OWNERSHIP_SHALLOW)')
_CONVERSION(`GSList*',`Glib::SListHandle<Glib::RefPtr<const SourceMarker> >', `$2($3, Glib::OWNERSHIP_SHALLOW)')

#TextIter
_CONVERSION(`const Gtk::TextIter&',`const GtkTextIter*',`$3.gobj()')
_CONVERSION(`Gtk::TextIter&',`GtkTextIter*',`$3.gobj()')
_CONVERSION(`Glib::RefPtr<SourceBuffer>&',`GtkSourceBuffer*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`GtkTextIter*',`Gtk::TextIter&',Glib::wrap($3))

#SourceLanguagesManager

_CONVERSION(`const GSList*',`Glib::SListHandle<Glib::RefPtr<SourceLanguage> >',`$2((GSList*)$3, Glib::OWNERSHIP_NONE)')
_CONVERSION(`const GSList*',`Glib::SListHandle<Glib::RefPtr<const SourceLanguage> >',`$2((GSList*)$3, Glib::OWNERSHIP_NONE)')
_CONVERSION(`const GSList*',`Glib::SListHandle<Glib::ustring>',`$2((GSList*)$3, Glib::OWNERSHIP_NONE)')


#SourceLanguage

#_CONVERSION(`GtkSourceLanguage*',`SourceLanguage&',`*Glib::wrap($3, true).operator->()')


#_CONVERSION(`GdkPixbuf*',`Glib::RefPtr<Gdk::Pixbuf>',`Glib::wrap($3)')
_CONVERSION(`GdkPixbuf*',`Glib::RefPtr<const Gdk::Pixbuf>',`Glib::wrap($3)')
