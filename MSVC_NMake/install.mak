# NMake Makefile snippet for copying the built libraries, utilities and headers to
# a path under $(PREFIX).

install: all
	@if not exist $(PREFIX)\bin\ md $(PREFIX)\bin
	@if not exist $(PREFIX)\lib\gtksourceviewmm-$(GTKSOURCEVIEWMM_MAJOR_VERSION).$(GTKSOURCEVIEWMM_MINOR_VERSION)\include\ md $(PREFIX)\lib\gtksourceviewmm-$(GTKSOURCEVIEWMM_MAJOR_VERSION).$(GTKSOURCEVIEWMM_MINOR_VERSION)\include
	@if not exist $(PREFIX)\include\gtksourceviewmm-$(GTKSOURCEVIEWMM_MAJOR_VERSION).$(GTKSOURCEVIEWMM_MINOR_VERSION)\gtksourceviewmm\private\ @md $(PREFIX)\include\gtksourceviewmm-$(GTKSOURCEVIEWMM_MAJOR_VERSION).$(GTKSOURCEVIEWMM_MINOR_VERSION)\gtksourceviewmm\private
	@copy /b vs$(VSVER)\$(CFG)\$(PLAT)\$(GTKSOURCEVIEWMM_LIBNAME).dll $(PREFIX)\bin
	@copy /b vs$(VSVER)\$(CFG)\$(PLAT)\$(GTKSOURCEVIEWMM_LIBNAME).pdb $(PREFIX)\bin
	@copy /b vs$(VSVER)\$(CFG)\$(PLAT)\$(GTKSOURCEVIEWMM_LIBNAME).lib $(PREFIX)\lib
	@copy ..\gtksourceview\gtksourceviewmm.h "$(PREFIX)\include\gtksourceviewmm-$(GTKSOURCEVIEWMM_MAJOR_VERSION).$(GTKSOURCEVIEWMM_MINOR_VERSION)\"
	@copy "..\gtksourceview\gtksourceviewmmconfig.h" "$(PREFIX)\lib\gtksourceviewmm-$(GTKSOURCEVIEWMM_MAJOR_VERSION).$(GTKSOURCEVIEWMM_MINOR_VERSION)\include\"
	@for %h in ($(GTKSOURCEVIEWMM_INT_EXTRA_HEADERS)) do @copy ..\gtksourceview\gtksourceviewmm\%h "$(PREFIX)\include\gtksourceviewmm-$(GTKSOURCEVIEWMM_MAJOR_VERSION).$(GTKSOURCEVIEWMM_MINOR_VERSION)\gtksourceviewmm\%h"
	@for %h in ($(GTKSOURCEVIEWMM_INT_GENERATED_HEADERS)) do @if exist ..\gtksourceview\gtksourceviewmm\%h copy ..\gtksourceview\gtksourceviewmm\%h "$(PREFIX)\include\gtksourceviewmm-$(GTKSOURCEVIEWMM_MAJOR_VERSION).$(GTKSOURCEVIEWMM_MINOR_VERSION)\gtksourceviewmm\%h"
	@for %h in ($(GTKSOURCEVIEWMM_INT_GENERATED_HEADERS)) do @if exist vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\%h copy vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\%h "$(PREFIX)\include\gtksourceviewmm-$(GTKSOURCEVIEWMM_MAJOR_VERSION).$(GTKSOURCEVIEWMM_MINOR_VERSION)\gtksourceviewmm\%h"
	@for %h in ($(GTKSOURCEVIEWMM_HG_FILES)) do @if exist ..\gtksourceview\gtksourceviewmm\private\%~nh_p.h copy ..\gtksourceview\gtksourceviewmm\private\%~nh_p.h "$(PREFIX)\include\gtksourceviewmm-$(GTKSOURCEVIEWMM_MAJOR_VERSION).$(GTKSOURCEVIEWMM_MINOR_VERSION)\gtksourceviewmm\private\%~nh_p.h"
	@for %h in ($(GTKSOURCEVIEWMM_HG_FILES)) do @if exist vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\private\%~nh_p.h copy vs$(VSVER)\$(CFG)\$(PLAT)\gtksourceviewmm\private\%~nh_p.h "$(PREFIX)\include\gtksourceviewmm-$(GTKSOURCEVIEWMM_MAJOR_VERSION).$(GTKSOURCEVIEWMM_MINOR_VERSION)\gtksourceviewmm\private\%~nh_p.h"
