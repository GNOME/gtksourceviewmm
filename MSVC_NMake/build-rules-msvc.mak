# NMake Makefile portion for compilation rules
# Items in here should not need to be edited unless
# one is maintaining the NMake build files.  The format
# of NMake Makefiles here are different from the GNU
# Makefiles.  Please see the comments about these formats.

# Inference rules for compiling the .obj files.
# Used for libs and programs with more than a single source file.
# Format is as follows
# (all dirs must have a trailing '\'):
#
# {$(srcdir)}.$(srcext){$(destdir)}.obj::
# 	$(CC)|$(CXX) $(cflags) /Fo$(destdir) /c @<<
# $<
# <<

{vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\}.cc{vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\}.obj::
	$(CXX) $(LIBGTKSOURCEVIEWMM_CFLAGS) $(CFLAGS_NOGL) /Fovs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\ /Fdvs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\ /c @<<
$<
<<

{..\gtksourceview\gtksourceviewmm\}.cc{vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\}.obj::
	$(CXX) $(LIBGTKSOURCEVIEWMM_CFLAGS) $(CFLAGS_NOGL) /Fovs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\ /Fdvs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\ /c @<<
$<
<<

{..\untracked\gtksourceview\gtksourceviewmm\}.cc{vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\}.obj::
	$(CXX) $(LIBGTKSOURCEVIEWMM_CFLAGS) $(CFLAGS_NOGL) /Fovs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\ /Fdvs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\ /c @<<
$<
<<

{..\gtksourceview\src\}.ccg{vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\}.obj:
	@if not exist $(@D)\private\ md $(@D)\private
	@for %%s in ($(<D)\*.ccg) do @if not exist ..\gtksourceview\gtksourceviewmm\%%~ns.cc if not exist ..\untracked\gtksourceview\gtksourceviewmm\%%~ns.cc if not exist $(@D)\%%~ns.cc $(PERL) -- $(GMMPROC_DIR)/gmmproc -I ../codegen/m4 -I $(GMMPROC_GTK_DIR) -I $(GMMPROC_PANGO_DIR) -I $(GMMPROC_ATK_DIR) --defs $(<D:\=/) %%~ns $(<D:\=/) $(@D)
	@if exist $(@D)\$(<B).cc $(CXX) $(LIBGTKSOURCEVIEWMM_CFLAGS) $(CFLAGS_NOGL) /Fo$(@D)\ /Fd$(@D)\ /c $(@D)\$(<B).cc
	@if exist ..\untracked\gtksourceview\gtksourceviewmm\$(<B).cc if not exist ..\gtksourceview\gtksourceviewmm\$(<B).cc if not exist $(@D)\$(<B).cc $(CXX) $(LIBGTKSOURCEVIEWMM_CFLAGS) $(CFLAGS_NOGL) /Fo$(@D)\ /Fd$(@D)\ /c ..\gtksourceview\gtksourceviewmm\$(<B).cc
	@if exist ..\gtksourceview\gtksourceviewmm\$(<B).cc if not exist ..\untracked\gtksourceview\gtksourceviewmm\$(<B).cc if not exist $(@D)\$(<B).cc $(CXX) $(LIBGTKSOURCEVIEWMM_CFLAGS) $(CFLAGS_NOGL) /Fo$(@D)\ /Fd$(@D)\ /c ..\gtksourceview\gtksourceviewmm\$(<B).cc

{.\gtksourceviewmm\}.rc{vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\}.res:
	rc /fo$@ $<

# Rules for building .lib files
$(GTKSOURCEVIEWMM_LIB): $(GTKSOURCEVIEWMM_DLL)

# Rules for linking DLLs
# Format is as follows (the mt command is needed for MSVC 2005/2008 builds):
# $(dll_name_with_path): $(dependent_libs_files_objects_and_items)
#	link /DLL [$(linker_flags)] [$(dependent_libs)] [/def:$(def_file_if_used)] [/implib:$(lib_name_if_needed)] -out:$@ @<<
# $(dependent_objects)
# <<
# 	@-if exist $@.manifest mt /manifest $@.manifest /outputresource:$@;2
$(GTKSOURCEVIEWMM_DLL): ..\gtksourceview\gtksourceviewmmconfig.h $(GTKSOURCEVIEWMM_INT_TARGET) $(gtksourceviewmm_OBJS)
	link /DLL $(LDFLAGS_NOLTCG) $(GTKSOURCEVIEWMM_DEP_LIBS) /implib:$(GTKSOURCEVIEWMM_LIB) $(GTKSOURCEVIEWMM_DEF_LDFLAG) -out:$@ @<<
$(gtksourceviewmm_OBJS)
<<
	@-if exist $@.manifest mt /manifest $@.manifest /outputresource:$@;2

# Rules for linking Executables
# Format is as follows (the mt command is needed for MSVC 2005/2008 builds):
# $(dll_name_with_path): $(dependent_libs_files_objects_and_items)
#	link [$(linker_flags)] [$(dependent_libs)] -out:$@ @<<
# $(dependent_objects)
# <<
# 	@-if exist $@.manifest mt /manifest $@.manifest /outputresource:$@;1

# For the gendef tool
{.\gendef\}.cc{vs$(VSVER)\$(CFG)\$(PLAT)\}.exe:
	@if not exist vs$(VSVER)\$(CFG)\$(PLAT)\gendef\ md vs$(VSVER)\$(CFG)\$(PLAT)\$(@B)
	$(CXX) $(GTKSOURCEVIEWMM_BASE_CFLAGS) $(CFLAGS) /Fo$(@D)\gendef\ /Fd$(@D)\gendef\ $< /link $(LDFLAGS) /out:$@
	@-if exist $@.manifest mt /manifest $@.manifest /outputresource:$@;1

clean:
	@-del /f /q vs$(VSVER)\$(CFG)\$(PLAT)\*.exe
	@-del /f /q vs$(VSVER)\$(CFG)\$(PLAT)\*.dll
	@-del /f /q vs$(VSVER)\$(CFG)\$(PLAT)\*.pdb
	@-del /f /q vs$(VSVER)\$(CFG)\$(PLAT)\*.ilk
	@-del /f /q vs$(VSVER)\$(CFG)\$(PLAT)\*.exp
	@-del /f /q vs$(VSVER)\$(CFG)\$(PLAT)\*.lib
	@-del /f /q vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm-tests\*.pdb
	@-del /f /q vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm-tests\*.obj
	@-del /f /q vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\private\*.h
	@-del /f /q vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\*.def
	@-del /f /q vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\*.res
	@-del /f /q vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\*.pdb
	@-del /f /q vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\*.obj
	@-del /f /q vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\*.h
	@-del /f /q vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\*.cc
	@-del /f /q vs$(VSVER)\$(CFG)\$(PLAT)\gendef\*.pdb
	@-del /f /q vs$(VSVER)\$(CFG)\$(PLAT)\gendef\*.obj
	@-rd vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm-tests
	@-rd vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\private
	@-rd vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm
	@-rd vs$(VSVER)\$(CFG)\$(PLAT)\gendef

.SUFFIXES: .cc .ccg .h .hg .obj
