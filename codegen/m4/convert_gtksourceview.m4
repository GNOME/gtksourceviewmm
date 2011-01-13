#
# When adding a new conversion please put here conversions only for types
# specific for GtkSourceView library and only for methods. Conversions from
# other libraries (like Gtk+ or Gdk) are to be put inside source files. The same
# with conversions specifically for wrapping vfuncs and signals. Also please
# sort conversions alphabetically with preference to first write conversions
# from C type to C++, and then from C++ to C. Just see below how this is done.
#


#
## GTKSOURCE
#


# GtkSourceBuffer -> Gsv::SourceBuffer
_CONVERSION(`GtkSourceBuffer*',`Glib::RefPtr<SourceBuffer>',`Glib::wrap($3)')


# Gsv::SourceBuffer -> GtkSourceBuffer
_CONVERSION(`const Glib::RefPtr<SourceBuffer>&',`GtkSourceBuffer*',__CONVERT_REFPTR_TO_P)


# GtkSourceCompletion -> Gsv::SourceCompletion
_CONVERSION(`GtkSourceCompletion*',`Glib::RefPtr<SourceCompletion>',`Glib::wrap($3)')


# GtkSourceCompletionContext -> Gsv::SourceCompletionContext
_CONVERSION(`GtkSourceCompletionContext*',`Glib::RefPtr<SourceCompletionContext>',`Glib::wrap($3)')


# Gsv::SourceCompletionContext -> GtkSourceCompletionContext
_CONVERSION(`const Glib::RefPtr<SourceCompletionContext>&',`GtkSourceCompletionContext*',`Glib::unwrap($3)')
_CONVERSION(`const Glib::RefPtr<const SourceCompletionContext>&',`GtkSourceCompletionContext*',`const_cast<GtkSourceCompletionContext*>(Glib::unwrap($3))')


# GtkSourceCompletionInfo -> Gsv::SourceCompletionInfo
_CONVERSION(`GtkSourceCompletionInfo*',`SourceCompletionInfo*',`Glib::wrap($3)')


# Gsv::SourceCompletionInfo -> GtkSourceCompletionInfo
_CONVERSION(`const SourceCompletionInfo&',`GtkSourceCompletionInfo*',`const_cast<GtkSourceCompletionInfo*>(($3).gobj())')


# Gsv::SourceCompletionProposal -> GtkSourceCompletionProposal
_CONVERSION(`const Glib::RefPtr<const SourceCompletionProposal>&',`GtkSourceCompletionProposal*',`const_cast<GtkSourceCompletionProposal*>(Glib::unwrap($3))')
_CONVERSION(`const Glib::RefPtr<SourceCompletionProposal>&',`GtkSourceCompletionProposal*',`Glib::unwrap($3)')


# Gsv::SourceCompletionProvider -> GtkSourceCompletionProvider
_CONVERSION(`const Glib::RefPtr<SourceCompletionProvider>&',`GtkSourceCompletionProvider*',`Glib::unwrap($3)')


# GtkSourceGutter -> Gsv::SourceGutter
_CONVERSION(`GtkSourceGutter*',`Glib::RefPtr<SourceGutter>',`Glib::wrap($3)')


# Gsv::SourceGutterRenderer -> GtkSourceGutterRenderer
_CONVERSION(`SourceGutterRenderer*',`GtkSourceGutterRenderer*',`($3)->gobj()')


# GtkSourceLanguage -> Gsv::SourceLanguage
_CONVERSION(`GtkSourceLanguage*',`Glib::RefPtr<SourceLanguage>',`Glib::wrap($3)')


# Gsv::SourceLanguage -> GtkSourceLanguage
_CONVERSION(`const Glib::RefPtr<SourceLanguage>&',`GtkSourceLanguage*',`Glib::unwrap($3)')


# GtkSourceLanguageManager -> Gsv::SourceLanguageManager
_CONVERSION(`GtkSourceLanguageManager*',`Glib::RefPtr<SourceLanguageManager>',`Glib::wrap($3)')


# GtkSourceMark -> Gsv::SourceMark
_CONVERSION(`GtkSourceMark*',`Glib::RefPtr<SourceMark>',`Glib::wrap($3)')


# Gsv::SourceMark -> GtkSourceMark
_CONVERSION(`const Glib::RefPtr<SourceMark>&',`GtkSourceMark*',`Glib::unwrap($3)')


# GtkSourceMarkAttributes -> Gsv::SourceMarkAttributes
_CONVERSION(`'GtkSourceMarkAttributes*,`Glib::RefPtr<SourceMarkAttributes>',`Glib::wrap($3)')


# Gsv::SourceMarkAttributes -> GtkSourceMarkAttributes
_CONVERSION(`const Glib::RefPtr<SourceMarkAttributes>&',`GtkSourceMarkAttributes*',`Glib::unwrap($3)')


# GtkSourceStyle -> Gsv::SourceStyle
_CONVERSION(`GtkSourceStyle*',`Glib::RefPtr<SourceStyle>',`Glib::wrap($3)')


# GtkSourceStyleScheme -> Gsv::SourceStyleScheme
_CONVERSION(`GtkSourceStyleScheme*',`Glib::RefPtr<SourceStyleScheme>',`Glib::wrap($3)')


# Gsv::SourceStyleScheme -> GtkSourceStyleScheme
_CONVERSION(`const Glib::RefPtr<SourceStyleScheme>&',`GtkSourceStyleScheme*',`Glib::unwrap($3)')


# GtkSourceStyleSchemeManager -> Gsv::SourceStyleSchemeManager
_CONVERSION(`GtkSourceStyleSchemeManager*',`Glib::RefPtr<SourceStyleSchemeManager>',`Glib::wrap($3)')


# GtkSourceUndoManager -> Gsv::SourceUndoManager
_CONVERSION(`GtkSourceUndoManager*',`Glib::RefPtr<SourceUndoManager>',`Glib::wrap($3)')


# Gsv::SourceUndoManager -> GtkSourceUndoManager
_CONVERSION(`const Glib::RefPtr<const SourceUndoManager>&',`GtkSourceUndoManager*',`const_cast<GtkSourceUndoManager*>(Glib::unwrap($3))')


# GtkSourceView -> Gsv::SourceView
_CONVERSION(`GtkSourceView*',`SourceView*',`Glib::wrap($3)')


#
## ENUMS
#


_CONV_ENUM(Gtk,SourceSmartHomeEndType)
_CONV_ENUM(Gtk,SourceDrawSpacesFlags)
_CONV_ENUM(Gtk,SourceCompletionActivation)
_CONV_ENUM(Gtk,SourceBracketMatchType)
_CONV_ENUM(Gtk,SourceGutterRendererState)
_CONV_ENUM(Gtk,SourceGutterRendererAlignmentMode)
