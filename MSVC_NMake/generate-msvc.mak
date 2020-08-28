# NMake Makefile portion for code generation and
# intermediate build directory creation
# Items in here should not need to be edited unless
# one is maintaining the NMake build files.

# Create the build directories

vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm:
	@-md $@

# Generate .def files
vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\gtksourceviewmm.def: $(GENDEF) vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm $(gtksourceviewmm_OBJS)
	vs$(VSVER)\$(CFG)\$(PLAT)\gendef.exe $@ $(GTKSOURCEVIEWMM_DLLNAME).dll vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\*.obj

# Generate wrap_init.cc files
vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\wrap_init.cc: $(gtksourceviewmm_real_hg)
	@if not exist ..\gdk\gtksourceviewmm\wrap_init.cc $(PERL) -- "$(GMMPROC_DIR)/generate_wrap_init.pl" --namespace=Gsv --parent_dir=gtksourceviewmm $(gtksourceviewmm_real_hg:\=/)>$@

prep-git-build: pkg-ver.mak

#gtksourceviewmm\gtksourceviewmm.rc: ..\configure.ac

# You may change GTKSOURCEVIEWMM_DISABLE_DEPRECATED and GTKSOURCEVIEWMM_STATIC_LIB if you know what you are doing

..\gtksourceview\gtksourceviewmmconfig.h: ..\configure.ac ..\gtksourceview\gtksourceviewmmconfig.h.in
	@if not "$(DO_REAL_GEN)" == "1" if exist pkg-ver.mak del pkg-ver.mak
	@if not exist pkg-ver.mak $(MAKE) /f Makefile.vc CFG=$(CFG) prep-git-build
	@if "$(DO_REAL_GEN)" == "1" echo Generating $@...
	@if "$(DO_REAL_GEN)" == "1" copy ..\gtksourceview\$(@F).in $@
	@if "$(DO_REAL_GEN)" == "1" $(PERL) -pi.bak -e "s/\#undef GTKSOURCEVIEWMM_DISABLE_DEPRECATED/\/\* \#undef GTKSOURCEVIEWMM_DISABLE_DEPRECATED \*\//g" $@
	@if "$(DO_REAL_GEN)" == "1" $(PERL) -pi.bak -e "s/\#undef GTKSOURCEVIEWMM_STATIC_LIB/\/\* \#undef GTKSOURCEVIEWMM_STATIC_LIB \*\//g" $@
	@if "$(DO_REAL_GEN)" == "1" $(PERL) -pi.bak -e "s/\#undef GTKSOURCEVIEWMM_MAJOR_VERSION/\#define GTKSOURCEVIEWMM_MAJOR_VERSION $(PKG_MAJOR_VERSION)/g" $@
	@if "$(DO_REAL_GEN)" == "1" $(PERL) -pi.bak -e "s/\#undef GTKSOURCEVIEWMM_MINOR_VERSION/\#define GTKSOURCEVIEWMM_MINOR_VERSION $(PKG_MINOR_VERSION)/g" $@
	@if "$(DO_REAL_GEN)" == "1" $(PERL) -pi.bak -e "s/\#undef GTKSOURCEVIEWMM_MICRO_VERSION/\#define GTKSOURCEVIEWMM_MICRO_VERSION $(PKG_MICRO_VERSION)/g" $@
	@if "$(DO_REAL_GEN)" == "1" del $@.bak

pkg-ver.mak: ..\configure.ac
	@echo Generating version info Makefile Snippet...
	@$(PERL) -00 -ne "print if /AC_INIT\(/" $** |	\
	$(PERL) -pe "tr/, /\n/s" |	\
	$(PERL) -ne "print if 2 .. 2" |	\
	$(PERL) -ne "print /\[(.*)\]/" > ver.txt
	@echo @echo off>pkg-ver.bat
	@echo.>>pkg-ver.bat
	@echo set /p glibmm_ver=^<ver.txt>>pkg-ver.bat
	@echo for /f "tokens=1,2,3 delims=." %%%%a IN ("%glibmm_ver%") do (echo PKG_MAJOR_VERSION=%%%%a^& echo PKG_MINOR_VERSION=%%%%b^& echo PKG_MICRO_VERSION=%%%%c)^>$@>>pkg-ver.bat
	@pkg-ver.bat
	@del ver.txt pkg-ver.bat
	$(MAKE) /f Makefile.vc CFG=$(CFG) GENERATE_VERSIONED_FILES=1 ..\gtksourceview\gtksourceviewmmconfig.h
