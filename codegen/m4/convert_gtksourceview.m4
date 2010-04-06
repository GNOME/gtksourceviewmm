#
## GDK
#

# Gdk::Color -> GdkColor
_CONVERSION(`const Gdk::Color&',`const GdkColor*',`($3).gobj()')
_CONVERSION(`Gdk::Color&',`GdkColor*',`($3).gobj()')

#
## GTK
#

# GtkCellRenderer -> Gtk::CellRenderer
_CONVERSION(`GtkCellRenderer*',`Gtk::CellRenderer*',`Glib::wrap($3)')


# Gtk::CellRenderer -> GtkCellRenderer
_CONVERSION(`Gtk::CellRenderer*',`GtkCellRenderer*',`Glib::unwrap($3)')


# Gtk::PrintContext -> GtkPrintContext
_CONVERSION(`const Glib::RefPtr<Gtk::PrintContext>&',`GtkPrintContext*',`Glib::unwrap($3)')


# Gtk::TextBuffer -> GtkTextBuffer
_CONVERSION(`const Glib::RefPtr<Gtk::TextBuffer>&',`GtkTextBuffer*',`Glib::unwrap($3)')


# GtkTextIter -> Gtk::TextIter
_CONVERSION(`GtkTextIter*',`const Gtk::TextIter&',`Glib::wrap($3)')
_CONVERSION(`GtkTextIter*',`Gtk::TextIter&',`Glib::wrap($3)')


# Gtk::TextIter -> GtkTextIter
_CONVERSION(`const Gtk::TextIter&',`GtkTextIter*',`const_cast<GtkTextIter*>(($3).gobj())')
_CONVERSION(`Gtk::TextIter&',`GtkTextIter*',`($3).gobj()')
_CONVERSION(`const Gtk::TextIter&',`const GtkTextIter*',`($3).gobj()')


# Gtk::TextTagTable -> GtkTextTagTable
_CONVERSION(`const Glib::RefPtr<Gtk::TextTagTable>&',`GtkTextTagTable*',`Glib::unwrap($3)')


# Gtk::TextView -> GtkTextView
_CONVERSION(`const Gtk::TextView&',`GtkTextView*',`const_cast<GtkTextView*>(($3).gobj())')


# GtkTooltip -> Gtk::Tooltip
_CONVERSION(`GtkTooltip*',`const Glib::RefPtr<Gtk::Tooltip>&',`Glib::wrap($3)')


# Gtk::Tooltip -> GtkTooltip
_CONVERSION(`const Glib::RefPtr<Gtk::Tooltip>&',`GtkTooltip*',`const_cast<GtkTooltip*>(Glib::unwrap($3))')


#
## GTKSOURCE
#

# GtkSourceBuffer -> gtksourceview::SourceBuffer
_CONVERSION(`GtkSourceBuffer*',`Glib::RefPtr<SourceBuffer>',`Glib::wrap($3)')


# gtksourceview::SourceBuffer -> GtkSourceBuffer
_CONVERSION(`const Glib::RefPtr<SourceBuffer>&',`GtkSourceBuffer*',__CONVERT_REFPTR_TO_P)


# GtkSourceCompletion -> gtksourceview::SourceCompletion
_CONVERSION(`GtkSourceCompletion*',`SourceCompletion*',`Glib::wrap($3)')
_CONVERSION(`GtkSourceCompletion*',`const SourceCompletion*',`Glib::wrap($3)')


# GtkSourceCompletionContext -> gtksourceview::SourceCompletionContext
_CONVERSION(`GtkSourceCompletionContext*',`Glib::RefPtr<SourceCompletionContext>',`Glib::wrap($3)')
_CONVERSION(`GtkSourceCompletionContext*',`const Glib::RefPtr<SourceCompletionContext>&',`Glib::wrap($3)')
_CONVERSION(`GtkSourceCompletionContext*',`const Glib::RefPtr<const SourceCompletionContext>&',`Glib::wrap($3)')


# gtksourceview::SourceCompletionContext -> GtkSourceCompletionContext
_CONVERSION(`const Glib::RefPtr<SourceCompletionContext>&',`GtkSourceCompletionContext*',`Glib::unwrap($3)')
_CONVERSION(`const Glib::RefPtr<const SourceCompletionContext>&',`GtkSourceCompletionContext*',`const_cast<GtkSourceCompletionContext*>(Glib::unwrap($3))')


# GtkSourceCompletionInfo -> gtksourceview::SourceCompletionInfo
_CONVERSION(`GtkSourceCompletionInfo*',`SourceCompletionInfo*',`Glib::wrap($3)')
_CONVERSION(`GtkSourceCompletionInfo*',`const SourceCompletionInfo*',`Glib::wrap($3)')
_CONVERSION(`GtkSourceCompletionInfo*',`const SourceCompletionInfo&',`(*(Glib::wrap($3)))')


# gtksourceview::SourceCompletionInfo -> GtkSourceCompletionInfo
_CONVERSION(`const SourceCompletionInfo&',`GtkSourceCompletionInfo*',`const_cast<GtkSourceCompletionInfo*>(($3).gobj())')


# GtkSourceCompletionProposal -> gtksourceview::SourceCompletionProposal
_CONVERSION(`GtkSourceCompletionProposal*',`const Glib::RefPtr<SourceCompletionProposal>&',`Glib::wrap($3)')
_CONVERSION(`GtkSourceCompletionProposal*',`const Glib::RefPtr<const SourceCompletionProposal>&',`Glib::wrap($3)')


# gtksourceview::SourceCompletionProposal -> GtkSourceCompletionProposal
_CONVERSION(`const Glib::RefPtr<const SourceCompletionProposal>&',`GtkSourceCompletionProposal*',`const_cast<GtkSourceCompletionProposal*>(Glib::unwrap($3))')
_CONVERSION(`const Glib::RefPtr<SourceCompletionProposal>&',`GtkSourceCompletionProposal*',`Glib::unwrap($3)')


# gtksourceview::SourceCompletionProvider -> GtkSourceCompletionProvider
_CONVERSION(`const Glib::RefPtr<SourceCompletionProvider>&',`GtkSourceCompletionProvider*',`Glib::unwrap($3)')


# GtkSourceGutter -> gtksourceview::SourceGutter
_CONVERSION(`GtkSourceGutter*',`Glib::RefPtr<SourceGutter>',`Glib::wrap($3)')
_CONVERSION(`GtkSourceGutter*',`Glib::RefPtr<const SourceGutter>',`Glib::wrap($3)')


# GtkSourceLanguage -> gtksourceview::SourceLanguage
_CONVERSION(`GtkSourceLanguage*',`Glib::RefPtr<SourceLanguage>',`Glib::wrap($3)')


# gtksourceview::SourceLanguage -> GtkSourceLanguage
_CONVERSION(`const Glib::RefPtr<SourceLanguage>&',`GtkSourceLanguage*',`Glib::unwrap($3)')


# GtkSourceLanguageManager -> gtksourceview::SourceLanguageManager
_CONVERSION(`GtkSourceLanguageManager*',`Glib::RefPtr<SourceLanguageManager>',`Glib::wrap($3)')


# GtkSourceMark -> gtksourceview::SourceMark
_CONVERSION(`GtkSourceMark*',`Glib::RefPtr<SourceMark>',`Glib::wrap($3)')


# GtkSourceStyle -> gtksourceview::SourceStyle
_CONVERSION(`GtkSourceStyle*',`Glib::RefPtr<SourceStyle>',`Glib::wrap($3)')


# GtkSourceStyleScheme -> gtksourceview::SourceStyleScheme
_CONVERSION(`GtkSourceStyleScheme*',`Glib::RefPtr<SourceStyleScheme>',`Glib::wrap($3)')


# gtksourceview::SourceStyleScheme -> GtkSourceStyleScheme
_CONVERSION(`const Glib::RefPtr<SourceStyleScheme>&',`GtkSourceStyleScheme*',`Glib::unwrap($3)')


# GtkSourceStyleSchemeManager -> gtksourceview::SourceStyleSchemeManager
_CONVERSION(`GtkSourceStyleSchemeManager*',`Glib::RefPtr<SourceStyleSchemeManager>',`Glib::wrap($3)')


# GtkSourceUndoManager -> gtksourceview::SourceUndoManager
_CONVERSION(`GtkSourceUndoManager*',`Glib::RefPtr<SourceUndoManager>',`Glib::wrap($3)')


# gtksourceview::SourceUndoManager -> GtkSourceUndoManager
_CONVERSION(`const Glib::RefPtr<const SourceUndoManager>&',`GtkSourceUndoManager*',`const_cast<GtkSourceUndoManager*>(Glib::unwrap($3))')


# GtkSourceView -> Gtk::SourceView
_CONVERSION(`GtkSourceView*',`SourceView*',`Glib::wrap($3)')
_CONVERSION(`GtkSourceView*',`const SourceView*',`Glib::wrap($3)')

#
## ENUMS
#

_CONV_ENUM(Gtk,SourceSmartHomeEndType)
_CONV_ENUM(Gtk,SourceDrawSpacesFlags)
_CONV_ENUM(Gtk,SourceCompletionActivation)
