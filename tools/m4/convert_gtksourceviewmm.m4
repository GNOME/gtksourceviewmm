#SourceLanguage
_CONVERSION(`GtkSourceLanguage*',`Glib::RefPtr<SourceLanguage>',`Glib::wrap($3)')
_CONVERSION(`GtkSourceLanguage*',`Glib::RefPtr<const SourceLanguage>',`Glib::wrap($3)')
#_CONVERSION(`Glib::RefPtr<SourceLanguage>',`GtkSourceLanguage*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<SourceLanguage>&',`GtkSourceLanguage*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`Glib::ListHandle<const Glib::ustring>&',`const GSList*', `$3.data()')
_CONVERSION(`Glib::ListHandle<Glib::ustring>',`GSList*', `$3.data()')


#SourceStyleScheme
_CONVERSION(`GtkSourceStyleScheme*',`Glib::RefPtr<SourceStyleScheme>',`Glib::wrap($3)')
_CONVERSION(`GtkSourceStyleScheme*',`Glib::RefPtr<const SourceStyleScheme>',`Glib::wrap($3)')
_CONVERSION(`Glib::RefPtr<SourceStyleScheme>',`GtkSourceStyleScheme*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<SourceStyleScheme>&',`GtkSourceStyleScheme*',__CONVERT_REFPTR_TO_P)

_CONVERSION(`GtkSourceStyle*',`Glib::RefPtr<SourceStyle>',`Glib::wrap($3)')

#SourceMark
_CONVERSION(`GtkSourceMark*',`Glib::RefPtr<SourceMark>',`Glib::wrap($3)')
_CONVERSION(`GtkSourceMark*',`Glib::RefPtr<const SourceMark>',`Glib::wrap($3)')
#_CONVERSION(`Glib::RefPtr<SourceMark>',`GtkSourceMark*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<SourceMark>&',`GtkSourceMark*',__CONVERT_REFPTR_TO_P)


#TextIter
_CONVERSION(`const Gtk::TextIter&',`const GtkTextIter*',`$3.gobj()')
_CONVERSION(`Gtk::TextIter&',`GtkTextIter*',`$3.gobj()')
_CONVERSION(`const Glib::RefPtr<SourceBuffer>&',`GtkSourceBuffer*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`GtkTextIter*',`Gtk::TextIter&',Glib::wrap($3))

#SourceLanguagesManager

_CONVERSION(`GtkSourceLanguageManager*',`Glib::RefPtr<SourceLanguageManager>',`Glib::wrap($3)')


_CONVERSION(`const Glib::StringArrayHandle&',`gchar**',`const_cast<gchar**>(($3).data())')



#SourceLanguage

#_CONVERSION(`GtkSourceLanguage*',`SourceLanguage&',`*Glib::wrap($3, true).operator->()')


#_CONVERSION(`GdkPixbuf*',`Glib::RefPtr<Gdk::Pixbuf>',`Glib::wrap($3)')
_CONVERSION(`GdkPixbuf*',`Glib::RefPtr<const Gdk::Pixbuf>',`Glib::wrap($3)')


_CONV_ENUM(Gtk,SourceSmartHomeEndType)

