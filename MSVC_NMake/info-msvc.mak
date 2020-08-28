# NMake Makefile portion for displaying config info

all-build-info:
	@echo.
	@echo ----------
	@echo Build info
	@echo ---------
	@echo Build Type: $(CFG)

help:
	@echo.
	@echo ================================
	@echo Building gtksourcemm Using NMake
	@echo ================================
	@echo nmake /f Makefile.vc CFG=[release^|debug] ^<PREFIX=PATH^> ^<option1=xxx option2=xxx^>
	@echo.
	@echo Where:
	@echo ------
	@echo CFG: Required, use CFG=release for an optimized build and CFG=debug
	@echo for a debug build.  PDB files are generated for all builds.
	@echo.
	@echo PREFIX: Optional, the path where dependent libraries and tools may be
	@echo found, default is ^$(srcrootdir)\..\vs^$(short_vs_ver)\^$(platform),
	@echo where ^$(short_vs_ver) is 12 for VS 2013, and 14 for VS 2015~2019
	@echo and so on; and ^$(platform) is Win32 for 32-bit builds and x64 for
	@echo x64 builds.
	@echo.
	@echo USE_MESON_LIBS: Use this if linking to Meson-built
	@echo variants of glibmm, pangomm and libsigc++ is desired.
	@echo By using this option, gtkmm, pangomm, atkmm and cairomm
	@echo should be linked to the Meson-built variants of
	@echo glibmm and libsigc++ as well.
	@echo.
	@echo GMMPROC_DIR, GMMPROC_PANGO_DIR, GMMPROC_ATK_DIR, GMMPROC_GTK_DIR:
	@echo Required if building directly from a GIT checkout,
	@echo or re-generating the source files from the .hg/.ccg
	@echo files.  GMMPROC_GTK_DIR, GMMPROC_PANGO_DIR and GMMPROC_ATK_DIR are by
	@echo default in , ^$(GMMPROC_DIR)/../../gtkmm-$(GTKMM_MAJOR_VERSION).$(GTKMM_MINOR_VERSION)/proc/m4,
	@echo ^$(GMMPROC_DIR)/../../pangomm-$(PANGOMM_MAJOR_VERSION).$(PANGOMM_MINOR_VERSION)/proc/m4
	@echo and ^$(GMMPROC_DIR)/../../atkmm-$(ATKMM_MAJOR_VERSION).$(ATKMM_MINOR_VERSION)/proc/m4 respectively.
	@echo PERL with XML::Parser and some common *nix  commands
	@echo are required, as well as the .m4 and PERL files from
	@echo glibmm, atkmm, pangomm and gtkmm, which will be used by
	@echo gmmproc.
	@echo.
	@echo ======
	@echo A 'clean' target is supported to remove all generated files, intermediate
	@echo object files and binaries for the specified configuration.
	@echo.
	@echo An 'install' target is supported to copy the build (DLLs, utility programs,
	@echo LIBs, along with the introspection files if applicable) to appropriate
	@echo locations under ^$(PREFIX).
	@echo.
	@echo A 'prep-git-build' target is supported for building from GIT checkouts, which
	@echo will generate gtksourceviewmmconfig.h.  Use this target before building
	@echo any other targets when building from GIT checkouts.
	@echo.
	@echo A 'tests' target is supported to build the gtksourceviewmm's test programs.
	@echo ======
	@echo.
