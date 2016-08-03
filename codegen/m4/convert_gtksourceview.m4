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


# GtkSourceBuffer -> Gsv::Buffer
_CONVERSION(`GtkSourceBuffer*',`Glib::RefPtr<Buffer>',`Glib::wrap($3)')


# Gsv::Buffer -> GtkSourceBuffer
_CONVERSION(`const Glib::RefPtr<Buffer>&',`GtkSourceBuffer*',__CONVERT_REFPTR_TO_P)


# GtkSourceCompletion -> Gsv::Completion
_CONVERSION(`GtkSourceCompletion*',`Glib::RefPtr<Completion>',`Glib::wrap($3)')


# GtkSourceCompletionContext -> Gsv::CompletionContext
_CONVERSION(`GtkSourceCompletionContext*',`Glib::RefPtr<CompletionContext>',`Glib::wrap($3)')


# Gsv::CompletionContext -> GtkSourceCompletionContext
_CONVERSION(`const Glib::RefPtr<CompletionContext>&',`GtkSourceCompletionContext*',`Glib::unwrap($3)')
_CONVERSION(`const Glib::RefPtr<const CompletionContext>&',`GtkSourceCompletionContext*',`const_cast<GtkSourceCompletionContext*>(Glib::unwrap($3))')


# GtkSourceCompletionInfo -> Gsv::CompletionInfo
_CONVERSION(`GtkSourceCompletionInfo*',`CompletionInfo*',`Glib::wrap($3)')


# Gsv::CompletionInfo -> GtkSourceCompletionInfo
_CONVERSION(`const CompletionInfo&',`GtkSourceCompletionInfo*',`const_cast<GtkSourceCompletionInfo*>(($3).gobj())')


# Gsv::CompletionProposal -> GtkSourceCompletionProposal
_CONVERSION(`const Glib::RefPtr<const CompletionProposal>&',`GtkSourceCompletionProposal*',`const_cast<GtkSourceCompletionProposal*>(Glib::unwrap($3))')
_CONVERSION(`const Glib::RefPtr<CompletionProposal>&',`GtkSourceCompletionProposal*',`Glib::unwrap($3)')


# Gsv::CompletionProvider -> GtkSourceCompletionProvider
_CONVERSION(`const Glib::RefPtr<CompletionProvider>&',`GtkSourceCompletionProvider*',`Glib::unwrap($3)')


# GtkSourceGutter -> Gsv::Gutter
_CONVERSION(`GtkSourceGutter*',`Glib::RefPtr<Gutter>',`Glib::wrap($3)')


# Gsv::GutterRenderer -> GtkSourceGutterRenderer
_CONVERSION(`GutterRenderer*',`GtkSourceGutterRenderer*',`($3)->gobj()')


# GtkSourceGutterRenderer -> Gsv::GutterRenderer
_CONVERSION(`GtkSourceGutterRenderer*',`GutterRenderer*',`Glib::wrap($3)')


# GtkSourceLanguage -> Gsv::Language
_CONVERSION(`GtkSourceLanguage*',`Glib::RefPtr<Language>',`Glib::wrap($3)')


# Gsv::Language -> GtkSourceLanguage
_CONVERSION(`const Glib::RefPtr<Language>&',`GtkSourceLanguage*',`Glib::unwrap($3)')


# GtkSourceLanguageManager -> Gsv::LanguageManager
_CONVERSION(`GtkSourceLanguageManager*',`Glib::RefPtr<LanguageManager>',`Glib::wrap($3)')


# GtkSourceMark -> Gsv::Mark
_CONVERSION(`GtkSourceMark*',`Glib::RefPtr<Gsv::Mark>',`Glib::wrap($3)')


# Gsv::Mark -> GtkSourceMark
_CONVERSION(`const Glib::RefPtr<Mark>&',`GtkSourceMark*',`Glib::unwrap($3)')


# GtkSourceMarkAttributes -> Gsv::MarkAttributes
_CONVERSION(`'GtkSourceMarkAttributes*,`Glib::RefPtr<MarkAttributes>',`Glib::wrap($3)')


# Gsv::MarkAttributes -> GtkSourceMarkAttributes
_CONVERSION(`const Glib::RefPtr<MarkAttributes>&',`GtkSourceMarkAttributes*',`Glib::unwrap($3)')


# GtkSourceSearchSettings -> Gsv::SearchSettings
_CONVERSION(`GtkSourceSearchSettings*',`Glib::RefPtr<SearchSettings>',`Glib::wrap($3)')


# Gsv::SearchSettings -> GtkSourceSearchSettings
_CONVERSION(`const Glib::RefPtr<SearchSettings>&',`GtkSourceSearchSettings*',`Glib::unwrap($3)')


# GtkSourceStyle -> Gsv::Style
_CONVERSION(`GtkSourceStyle*',`Glib::RefPtr<Style>',`Glib::wrap($3)')


# Gsv::Style -> GtkSourceStyle
_CONVERSION(`const Glib::RefPtr<Style>&',`GtkSourceStyle*',`Glib::unwrap($3)')


# GtkSourceStyleScheme -> Gsv::StyleScheme
_CONVERSION(`GtkSourceStyleScheme*',`Glib::RefPtr<StyleScheme>',`Glib::wrap($3)')
_CONVERSION(`GtkSourceStyleScheme*',`Glib::RefPtr<const StyleScheme>',`Glib::wrap($3)')


# Gsv::StyleScheme -> GtkSourceStyleScheme
_CONVERSION(`const Glib::RefPtr<StyleScheme>&',`GtkSourceStyleScheme*',`Glib::unwrap($3)')


# GtkSourceStyleSchemeManager -> Gsv::StyleSchemeManager
_CONVERSION(`GtkSourceStyleSchemeManager*',`Glib::RefPtr<StyleSchemeManager>',`Glib::wrap($3)')


# GtkSourceUndoManager -> Gsv::UndoManager
_CONVERSION(`GtkSourceUndoManager*',`Glib::RefPtr<UndoManager>',`Glib::wrap($3)')


# Gsv::UndoManager -> GtkSourceUndoManager
_CONVERSION(`const Glib::RefPtr<const UndoManager>&',`GtkSourceUndoManager*',`const_cast<GtkSourceUndoManager*>(Glib::unwrap($3))')


# GtkSourceView -> Gsv::View
_CONVERSION(`GtkSourceView*',`View*',`Glib::wrap($3)')


#
## ENUMS
#


_CONV_ENUM(GtkSource,SmartHomeEndType)
_CONV_ENUM(GtkSource,DrawSpacesFlags)
_CONV_ENUM(GtkSource,BackgroundPatternType)
_CONV_ENUM(GtkSource,CompletionActivation)
_CONV_ENUM(GtkSource,BracketMatchType)
_CONV_ENUM(GtkSource,GutterRendererState)
_CONV_ENUM(GtkSource,GutterRendererAlignmentMode)
