#SourceLanguage
_CONVERSION(`GtkSourceLanguage*',`Glib::RefPtr<SourceLanguage>',`Glib::wrap($3)')
_CONVERSION(`GtkSourceLanguage*',`Glib::RefPtr<const SourceLanguage>',`Glib::wrap($3)')
#_CONVERSION(`Glib::RefPtr<SourceLanguage>',`GtkSourceLanguage*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<SourceLanguage>&',`GtkSourceLanguage*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`GSList*',`Glib::SListHandle<Glib::ustring>', `$2($3, Glib::OWNERSHIP_DEEP)')
_CONVERSION(`GList*',`Glib::ListHandle<Glib::ustring>', `$2($3, Glib::OWNERSHIP_DEEP)')
_CONVERSION(`const Glib::SListHandle<const Glib::ustring>&',`const GSList*', `$3.data()')
_CONVERSION(`Glib::ListHandle<const Glib::ustring>&',`const GSList*', `$3.data()')
_CONVERSION(`Glib::ListHandle<Glib::ustring>',`GSList*', `$3.data()')


#SourceStyleScheme
_CONVERSION(`GtkSourceStyleScheme*',`Glib::RefPtr<SourceStyleScheme>',`Glib::wrap($3)')
_CONVERSION(`GtkSourceStyleScheme*',`Glib::RefPtr<const SourceStyleScheme>',`Glib::wrap($3)')
#_CONVERSION(`Glib::RefPtr<SourceStyleScheme>',`GtkSourceStyleScheme*',__CONVERT_REFPTR_TO_P)

_CONVERSION(`GtkSourceStyle*',`Glib::RefPtr<SourceStyle>',`Glib::wrap($3)')

#SourceMarker
_CONVERSION(`GtkSourceMarker*',`Glib::RefPtr<SourceMarker>',`Glib::wrap($3)')
_CONVERSION(`GtkSourceMarker*',`Glib::RefPtr<const SourceMarker>',`Glib::wrap($3)')
#_CONVERSION(`Glib::RefPtr<SourceMarker>',`GtkSourceMarker*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<SourceMarker>&',`GtkSourceMarker*',__CONVERT_REFPTR_TO_P)
#_CONVERSION(`GSList*',`Glib::SListHandle<Glib::RefPtr<SourceMarker> >', __FL2H_SHALLOW)
_CONVERSION(`GSList*',`Glib::SListHandle<Glib::RefPtr<SourceMarker> >', `$2($3, Glib::OWNERSHIP_SHALLOW)')
_CONVERSION(`GSList*',`Glib::SListHandle<Glib::RefPtr<const SourceMarker> >', `$2($3, Glib::OWNERSHIP_SHALLOW)')

#TextIter
_CONVERSION(`const Gtk::TextIter&',`const GtkTextIter*',`$3.gobj()')
_CONVERSION(`Gtk::TextIter&',`GtkTextIter*',`$3.gobj()')
_CONVERSION(`const Glib::RefPtr<SourceBuffer>&',`GtkSourceBuffer*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`GtkTextIter*',`Gtk::TextIter&',Glib::wrap($3))

#SourceLanguagesManager

_CONVERSION(`GtkSourceLanguageManager*',`Glib::RefPtr<SourceLanguageManager>',`Glib::wrap($3)')

_CONVERSION(`const GSList*',`Glib::SListHandle<Glib::RefPtr<SourceLanguage> >',`$2((GSList*)$3, Glib::OWNERSHIP_NONE)')
_CONVERSION(`const GSList*',`Glib::SListHandle<Glib::RefPtr<const SourceLanguage> >',`$2((GSList*)$3, Glib::OWNERSHIP_NONE)')
_CONVERSION(`const GSList*',`Glib::SListHandle<Glib::ustring>',`$2((GSList*)$3, Glib::OWNERSHIP_NONE)')

_CONVERSION(`const Glib::StringArrayHandle&',`gchar**',`const_cast<gchar**>(($3).data())')



#SourceLanguage

#_CONVERSION(`GtkSourceLanguage*',`SourceLanguage&',`*Glib::wrap($3, true).operator->()')


#_CONVERSION(`GdkPixbuf*',`Glib::RefPtr<Gdk::Pixbuf>',`Glib::wrap($3)')
_CONVERSION(`GdkPixbuf*',`Glib::RefPtr<const Gdk::Pixbuf>',`Glib::wrap($3)')


_CONV_ENUM(Gtk,SourceSmartHomeEndType)

