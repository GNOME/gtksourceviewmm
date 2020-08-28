# Convert the source listing to object (.obj) listing in
# another NMake Makefile module, include it, and clean it up.
# This is a "fact-of-life" regarding NMake Makefiles...
# This file does not need to be changed unless one is maintaining the NMake Makefiles

# For those wanting to add things here:
# To add a list, do the following:
# # $(description_of_list)
# if [call create-lists.bat header $(makefile_snippet_file) $(variable_name)]
# endif
#
# if [call create-lists.bat file $(makefile_snippet_file) $(file_name)]
# endif
#
# if [call create-lists.bat footer $(makefile_snippet_file)]
# endif
# ... (repeat the if [call ...] lines in the above order if needed)
# !include $(makefile_snippet_file)
#
# (add the following after checking the entries in $(makefile_snippet_file) is correct)
# (the batch script appends to $(makefile_snippet_file), you will need to clear the file unless the following line is added)
#!if [del /f /q $(makefile_snippet_file)]
#!endif

# In order to obtain the .obj filename that is needed for NMake Makefiles to build DLLs/static LIBs or EXEs, do the following
# instead when doing 'if [call create-lists.bat file $(makefile_snippet_file) $(file_name)]'
# (repeat if there are multiple $(srcext)'s in $(source_list), ignore any headers):
# !if [for %c in ($(source_list)) do @if "%~xc" == ".$(srcext)" @call create-lists.bat file $(makefile_snippet_file) $(intdir)\%~nc.obj]
#
# $(intdir)\%~nc.obj needs to correspond to the rules added in build-rules-msvc.mak
# %~xc gives the file extension of a given file, %c in this case, so if %c is a.cc, %~xc means .cc
# %~nc gives the file name of a given file without extension, %c in this case, so if %c is a.cc, %~nc means a

NULL=

gtksourceviewmm_generated_private_headers = $(GTKSOURCEVIEWMM_HG_FILES:.hg=_p.h)

# For gtksourceviewmm
!if [call create-lists.bat header gtksourceviewmm.mak gtksourceviewmm_OBJS]
!endif

!if [for %c in ($(GTKSOURCEVIEWMM_INT_GENERATED_SOURCES)) do @if "%~xc" == ".cc" @call create-lists.bat file gtksourceviewmm.mak ^vs$(VSVER)\^$(CFG)\^$(PLAT)\gtksourceviewmm\%~nc.obj]
!endif

!if [for %c in ($(GTKSOURCEVIEWMM_INT_EXTRA_SOURCES)) do @if "%~xc" == ".cc" @call create-lists.bat file gtksourceviewmm.mak ^vs$(VSVER)\^$(CFG)\^$(PLAT)\gtksourceviewmm\%~nc.obj]
!endif

#!if [@call create-lists.bat file gtksourceviewmm.mak ^vs$(VSVER)\^$(CFG)\^$(PLAT)\gtksourceviewmm\gtksourceviewmm.res]
#!endif

!if [call create-lists.bat footer gtksourceviewmm.mak]
!endif

!if [call create-lists.bat header gtksourceviewmm.mak gtksourceviewmm_real_hg]
!endif

!if [for %h in ($(GTKSOURCEVIEWMM_HG_FILES)) do @call create-lists.bat file gtksourceviewmm.mak ../gtksourceview/src/%h]
!endif

!if [call create-lists.bat footer gtksourceviewmm.mak]
!endif

!if [call create-lists.bat header gtksourceviewmm.mak gtksourceviewmm_tests]
!endif

!if [for /f %d in ('dir /ad /b ..\tests\') do @call create-lists.bat file gtksourceviewmm.mak ^vs$(VSVER)\^$(CFG)\^$(PLAT)\gtksourceviewmm-test-%d.exe]
!endif

!if [call create-lists.bat footer gtksourceviewmm.mak]
!endif

!if [call create-lists.bat header gtksourceviewmm.mak gtksourceviewmm_tests & @(for /f %t in ('dir /ad /b ..\tests') do @call create-lists.bat file gtksourceviewmm.mak vs$(VSVER)\$(CFG)\$(PLAT)\%t.exe) & @call create-lists.bat footer gtksourceviewmm.mak]
!endif

!if [for /f %t in ('dir /ad /b ..\tests') do @for %s in (..\tests\%t\*.cc) do @echo vs^$(VSVER)\^$(CFG)\^$(PLAT)\gtkmm-tests\%t-%~ns.obj: %s>>gtksourceviewmm.mak & @echo. if not exist ^$(@D)\ md ^$(@D)>>gtksourceviewmm.mak & @echo.	^$(CXX) ^$(GTKSOURCEVIEWMM_BASE_CXXFLAGS) ^$(GTKSOURCEVIEWMM_INCLUDES) ^$(CFLAGS) /Fo^$(@D)\%t-%~ns.obj /Fd^$(@D)\ ^$** /c>>gtksourceviewmm.mak & @echo.>>gtksourceviewmm.mak]
!endif

!if [for /f %t in ('dir /ad /b ..\tests') do @call create-lists.bat header gtksourceviewmm.mak %t_OBJS & @(for %s in (..\tests\%t\*.cc) do @call create-lists.bat file gtksourceviewmm.mak vs$(VSVER)\$(CFG)\$(PLAT)\gtkmm-tests\%t-%~ns.obj) & @call create-lists.bat footer gtksourceviewmm.mak]
!endif

!if [for /f %t in ('dir /ad /b ..\tests') do @echo vs^$(VSVER)\^$(CFG)\^$(PLAT)\%t.exe: ^$(GTKSOURCEVIEWMM_LIB) ^$(%t_OBJS)>>gtksourceviewmm.mak & @echo.	link ^$(LDFLAGS) ^$** ^$(GTKSOURCEVIEWMM_DEP_LIBS) /out:^$@>>gtksourceviewmm.mak & @echo.>>gtksourceviewmm.mak]
!endif

!if [for %f in (gtksourceviewmm\buffer.h) do @if not exist ..\untracked\gtksourceview\%f if not exist ..\gtksourceview\%f if not exist vs$(VSVER)\$(CFG)\$(PLAT)\%f (md vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\private) & ($(PERL) -- $(GMMPROC_DIR)/gmmproc -I ../codegen/m4 -I $(GMMPROC_GTK_DIR) -I $(GMMPROC_PANGO_DIR) -I $(GMMPROC_ATK_DIR) --defs ../gtksourceview/src buffer ../gtksourceview/src vs$(VSVER)/$(CFG)/$(PLAT)/gtksourceviewmm)]
!endif

!if [for %d in (vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm ..\untracked\gtksourceview\gtksourceviewmm ..\gtksourceview\gtksourceviewmm) do @if exist %d\buffer.h call get-gmmproc-ver %d\buffer.h>>gtksourceviewmm.mak]
!endif

!include gtksourceviewmm.mak

!if [del /f /q gtksourceviewmm.mak]
!endif

!if "$(GMMPROC_VER)" >= "2.64.3"
GTKSOURCEVIEWMM_INT_TARGET = vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm
GTKSOURCEVIEWMM_DEF_LDFLAG =
!else
GTKSOURCEVIEWMM_INT_TARGET = vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\gtksourceviewmm.def
GTKSOURCEVIEWMM_DEF_LDFLAG = /def:$(GTKSOURCEVIEWMM_INT_TARGET)
GTKSOURCEVIEWMM_BASE_CXXFLAGS = $(GTKSOURCEVIEWMM_BASE_CXXFLAGS) /DGTKSOURCEVIEWMM_USE_GENDEF
!endif
