# NMake Makefile portion for enabling features for Windows builds

# These are the base minimum libraries required for building gtkmm.
BASE_INCLUDES =	/I$(PREFIX)\include

# Please do not change anything beneath this line unless maintaining the NMake Makefiles

# NMake Options
SAVED_OPTIONS = CFG^=$(CFG)

!ifdef DISABLE_DEPRECATED
SAVED_OPTIONS = $(SAVED_OPTIONS) DISABLE_DEPRECATED^=$(DISABLE_DEPRECATED)
!endif

# Debug/Release builds
!if "$(CFG)" == "debug" || "$(CFG)" == "Debug"
DEBUG_SUFFIX = -d
!else
DEBUG_SUFFIX =
!endif

!ifndef GMMPROC_DIR
GMMPROC_DIR=$(PREFIX)\share\glibmm-$(GLIBMM_MAJOR_VERSION).$(GLIBMM_MINOR_VERSION)\proc
!endif

!ifndef GMMPROC_PANGO_DIR
GMMPROC_PANGO_DIR=$(GMMPROC_DIR)\..\..\pangomm-$(PANGOMM_MAJOR_VERSION).$(PANGOMM_MINOR_VERSION)\proc\m4
!endif

!ifndef GMMPROC_ATK_DIR
GMMPROC_ATK_DIR=$(GMMPROC_DIR)\..\..\atkmm-$(ATKMM_MAJOR_VERSION).$(ATKMM_MINOR_VERSION)\proc\m4
!endif

!ifndef GMMPROC_GTK_DIR
GMMPROC_GTK_DIR=$(GMMPROC_DIR)\..\..\gtkmm-$(GTKMM_MAJOR_VERSION).$(GTKMM_MINOR_VERSION)\proc\m4
!endif

# Dependencies

GLIB_API_VERSION = 2.0
ATK_API_VERSION = 1.0
PANGO_API_VERSION = 1.0
GDK_PIXBUF_API_VERSION = 2.0
GTK_API_VERSION = 3
GTKSOURCEVIEW_API_VERSION = 3

LIBSIGC_MAJOR_VERSION = 2
LIBSIGC_MINOR_VERSION = 0
CAIROMM_MAJOR_VERSION = 1
CAIROMM_MINOR_VERSION = 0
GLIBMM_MAJOR_VERSION = 2
GLIBMM_MINOR_VERSION = 4
ATKMM_MAJOR_VERSION = 1
ATKMM_MINOR_VERSION = 6
PANGOMM_MAJOR_VERSION = 1
PANGOMM_MINOR_VERSION = 4
GTKMM_MAJOR_VERSION = 3
GTKMM_MINOR_VERSION = 0
GTKSOURCEVIEWMM_MAJOR_VERSION = 3
GTKSOURCEVIEWMM_MINOR_VERSION = 0

GTKSOURCEVIEWMM_CXX_INCLUDES =	\
	/I$(PREFIX)\include\gtkmm-$(GTKMM_MAJOR_VERSION).$(GTKMM_MINOR_VERSION)	\
	/I$(PREFIX)\lib\gtkmm-$(GTKMM_MAJOR_VERSION).$(GTKMM_MINOR_VERSION)\include	\
	/I$(PREFIX)\include\gdkmm-$(GDKMM_MAJOR_VERSION).$(GDKMM_MINOR_VERSION)	\
	/I$(PREFIX)\lib\gdkmm-$(GDKMM_MAJOR_VERSION).$(GDKMM_MINOR_VERSION)\include	\
	/I$(PREFIX)\include\pangomm-$(PANGOMM_MAJOR_VERSION).$(PANGOMM_MINOR_VERSION)	\
	/I$(PREFIX)\lib\pangomm-$(PANGOMM_MAJOR_VERSION).$(PANGOMM_MINOR_VERSION)\include	\
	/I$(PREFIX)\include\atkmm-$(ATKMM_MAJOR_VERSION).$(ATKMM_MINOR_VERSION)	\
	/I$(PREFIX)\lib\atkmm-$(ATKMM_MAJOR_VERSION).$(ATKMM_MINOR_VERSION)\include	\
	/I$(PREFIX)\include\giomm-$(GLIBMM_MAJOR_VERSION).$(GLIBMM_MINOR_VERSION)	\
	/I$(PREFIX)\lib\giomm-$(GLIBMM_MAJOR_VERSION).$(GLIBMM_MINOR_VERSION)\include	\
	/I$(PREFIX)\include\glibmm-$(GLIBMM_MAJOR_VERSION).$(GLIBMM_MINOR_VERSION)	\
	/I$(PREFIX)\lib\glibmm-$(GLIBMM_MAJOR_VERSION).$(GLIBMM_MINOR_VERSION)\include	\
	/I$(PREFIX)\include\cairomm-$(CAIROMM_MAJOR_VERSION).$(CAIROMM_MINOR_VERSION)	\
	/I$(PREFIX)\lib\cairomm-$(CAIROMM_MAJOR_VERSION).$(CAIROMM_MINOR_VERSION)\include	\
	/I$(PREFIX)\include\sigc++-$(LIBSIGC_MAJOR_VERSION).$(LIBSIGC_MINOR_VERSION)	\
	/I$(PREFIX)\lib\sigc++-$(LIBSIGC_MAJOR_VERSION).$(LIBSIGC_MINOR_VERSION)\include

GTKSOURCEVIEWMM_C_INCLUDES =	\
	/I$(PREFIX)\include\gtksourceview-$(GTK_API_VERSION).0	\
	/I$(PREFIX)\include\gtk-$(GTK_API_VERSION).0	\
	/I$(PREFIX)\include\gdk-pixbuf-$(GDK_PIXBUF_API_VERSION)	\
	/I$(PREFIX)\include\atk-$(ATK_API_VERSION)	\
	/I$(PREFIX)\include\pango-$(PANGO_API_VERSION)	\
	/I$(PREFIX)\include\glib-$(GLIB_API_VERSION)	\
	/I$(PREFIX)\lib\glib-$(GLIB_API_VERSION)\include	\
	/I$(PREFIX)\include\harfbuzz	\
	/I$(PREFIX)\include

GTKSOURCEVIEWMM_INCLUDES =	\
	$(GTKSOURCEVIEWMM_CXX_INCLUDES)	\
	$(GTKSOURCEVIEWMM_C_INCLUDES)

GOBJECT_LIBS = gobject-$(GLIB_API_VERSION).lib gmodule-$(GLIB_API_VERSION).lib glib-$(GLIB_API_VERSION).lib
GIO_LIBS = gio-$(GLIB_API_VERSION).lib $(GOBJECT_LIBS)

ATK_LIB = atk-$(ATK_API_VERSION).lib
CAIRO_LIBS = cairo-gobject.lib cairo.lib
GDK_PIXBUF_LIB = gdk_pixbuf-$(GDK_PIXBUF_API_VERSION).lib
GTK_LIBS = gtk-$(GTK_API_VERSION).0.lib gdk-$(GTK_API_VERSION).0.lib
PANGO_LIBS = pangocairo-$(PANGO_API_VERSION).lib pango-$(PANGO_API_VERSION).lib

GTKSOURCEVIEW_LIB = gtksourceview-$(GTKSOURCEVIEW_API_VERSION).0.lib

GTKSOURCEVIEWMM_LIBS_C_BASE =	\
	$(GTK_LIBS)	\
	$(GDK_PIXBUF_LIB)	\
	$(GIO_LIBS)	\
	$(CAIRO_LIBS)

GTKSOURCEVIEWMM_LIBS_C = \
	$(GTK_LIBS)	\
	$(GTKSOURCEVIEWMM_LIBS_C_BASE)

GTKSOURCEVIEWMM_LIBS_CXX =	\
	$(GTKMM_LIB)	\
	$(GDKMM_LIB)	\
	$(PANGOMM_LIB)	\
	$(ATKMM_LIB)	\
	$(GIOMM_LIB)	\
	$(GLIBMM_LIB)	\
	$(CAIROMM_LIB)	\
	$(LIBSIGC_LIB)

GTKSOURCEVIEWMM_LIBS_C =	\
	$(GTKSOURCEVIEW_LIB)	\
	$(GTKSOURCEVIEWMM_LIBS_C_BASE)

GTKSOURCEVIEWMM_DEP_LIBS =	\
	$(GTKSOURCEVIEWMM_LIBS_CXX)	\
	$(GTKSOURCEVIEWMM_LIBS_C)

# CXXFLAGS
GTKSOURCEVIEWMM_BASE_CXXFLAGS =		\
	/EHsc	\
	/Ivs$(VSVER)\$(CFG)\$(PLAT)	\
	/I..\untracked\gtksourceview	\
	/I..\gtksourceview	\
	/wd4530 /wd4250	\
	/FImsvc_recommended_pragmas.h

!if $(VSVER) >= 14
GTKSOURCEVIEWMM_BASE_CXXFLAGS =		\
	$(GTKSOURCEVIEWMM_BASE_CXXFLAGS)	\
	/utf-8 /wd4828	\
!endif

LIBGTKSOURCEVIEWMM_CFLAGS =	\
	/DGTKSOURCEVIEWMM_BUILD	\
	$(GTKSOURCEVIEWMM_BASE_CXXFLAGS)	\
	$(GTKSOURCEVIEWMM_INCLUDES)

# We build gtksourceviewmm-vc$(VSVER_LIB)-$(GTKMM_MAJOR_VERSION)_$(GTKMM_MINOR_VERSION).dll or
#          gtksourceviewmm-vc$(VSVER_LIB)-d-$(GTKMM_MAJOR_VERSION)_$(GTKMM_MINOR_VERSION).dll at least=

!if "$(USE_COMPAT_LIBS)" != ""
VSVER_LIB = $(PDBVER)0
MESON_VERVER_LIB =
!else
VSVER_LIB = $(PDBVER)$(VSVER_SUFFIX)
MESON_VERVER_LIB = -vc$(VSVER_LIB)
!endif

!ifdef USE_MESON_LIBS
LIBSIGC_LIBNAME = sigc-$(LIBSIGC_MAJOR_VERSION).$(LIBSIGC_MINOR_VERSION)
GLIBMM_LIBNAME = glibmm$(MESON_VERVER_LIB)-$(GLIBMM_MAJOR_VERSION).$(GLIBMM_MINOR_VERSION)
GIOMM_LIBNAME = giomm$(MESON_VERVER_LIB)-$(GLIBMM_MAJOR_VERSION).$(GLIBMM_MINOR_VERSION)
CAIROMM_LIBNAME = cairomm$(MESON_VERVER_LIB)-$(CAIROMM_MAJOR_VERSION).$(CAIROMM_MINOR_VERSION)
PANGOMM_LIBNAME = pangomm$(MESON_VERVER_LIB)-$(PANGOMM_MAJOR_VERSION).$(PANGOMM_MINOR_VERSION)
ATKMM_LIBNAME = atkmm$(MESON_VERVER_LIB)-$(ATKMM_MAJOR_VERSION).$(ATKMM_MINOR_VERSION)
GDKMM_LIBNAME = gdkmm$(MESON_VERVER_LIB)-$(GTKMM_MAJOR_VERSION).$(GTKMM_MINOR_VERSION)
GTKMM_LIBNAME = gtkmm$(MESON_VERVER_LIB)-$(GTKMM_MAJOR_VERSION).$(GTKMM_MINOR_VERSION)
GTKSOURCEVIEWMM_LIBNAME = gtksourceviewmm$(MESON_VERVER_LIB)-$(GTKSOURCEVIEWMM_MAJOR_VERSION).$(GTKSOURCEVIEWMM_MINOR_VERSION)

GTKSOURCEVIEWMM_DLLNAME = $(GTKSOURCEVIEWMM_LIBNAME)-1
!else
LIBSIGC_LIBNAME = sigc-vc$(PDBVER)0$(DEBUG_SUFFIX)-$(LIBSIGC_MAJOR_VERSION)_$(LIBSIGC_MINOR_VERSION)
GLIBMM_LIBNAME = glibmm-vc$(VSVER_LIB)$(DEBUG_SUFFIX)-$(GLIBMM_MAJOR_VERSION)_$(GLIBMM_MINOR_VERSION)
GIOMM_LIBNAME = giomm-vc$(VSVER_LIB)$(DEBUG_SUFFIX)-$(GLIBMM_MAJOR_VERSION)_$(GLIBMM_MINOR_VERSION)
CAIROMM_LIBNAME = cairomm-vc$(VSVER_LIB)$(DEBUG_SUFFIX)-$(CAIROMM_MAJOR_VERSION)_$(CAIROMM_MINOR_VERSION)
PANGOMM_LIBNAME = pangomm-vc$(VSVER_LIB)$(DEBUG_SUFFIX)-$(PANGOMM_MAJOR_VERSION)_$(PANGOMM_MINOR_VERSION)
ATKMM_LIBNAME = atkmm-vc$(VSVER_LIB)$(DEBUG_SUFFIX)-$(ATKMM_MAJOR_VERSION)_$(ATKMM_MINOR_VERSION)
GDKMM_LIBNAME = gdkmm-vc$(VSVER_LIB)$(DEBUG_SUFFIX)-$(GTKMM_MAJOR_VERSION)_$(GTKMM_MINOR_VERSION)
GTKMM_LIBNAME = gtkmm-vc$(VSVER_LIB)$(DEBUG_SUFFIX)-$(GTKMM_MAJOR_VERSION)_$(GTKMM_MINOR_VERSION)
GTKSOURCEVIEWMM_LIBNAME = gtksourceviewmm-vc$(VSVER_LIB)$(DEBUG_SUFFIX)-$(GTKSOURCEVIEWMM_MAJOR_VERSION)_$(GTKSOURCEVIEWMM_MINOR_VERSION)

GTKSOURCEVIEWMM_DLLNAME = $(GTKSOURCEVIEWMM_LIBNAME)
!endif

LIBSIGC_LIB = $(LIBSIGC_LIBNAME).lib
GLIBMM_LIB = $(GLIBMM_LIBNAME).lib
GIOMM_LIB = $(GIOMM_LIBNAME).lib
CAIROMM_LIB = $(CAIROMM_LIBNAME).lib
PANGOMM_LIB = $(PANGOMM_LIBNAME).lib
ATKMM_LIB = $(ATKMM_LIBNAME).lib
GDKMM_LIB = $(GDKMM_LIBNAME).lib
GTKMM_LIB = $(GTKMM_LIBNAME).lib

GTKSOURCEVIEWMM_DLL = vs$(VSVER)\$(CFG)\$(PLAT)\$(GTKSOURCEVIEWMM_DLLNAME).dll
GTKSOURCEVIEWMM_LIB = vs$(VSVER)\$(CFG)\$(PLAT)\$(GTKSOURCEVIEWMM_LIBNAME).lib

TARGETS = $(GTKSOURCEVIEWMM_LIB)

GENDEF = vs$(VSVER)\$(CFG)\$(PLAT)\gendef.exe

GTKSOURCEVIEWMM_HG_FILES = $(files_hg)
GTKSOURCEVIEWMM_INT_EXTRA_SOURCES = $(files_extra_cc)
GTKSOURCEVIEWMM_INT_EXTRA_HEADERS = $(files_extra_h)
GTKSOURCEVIEWMM_INT_GENERATED_HEADERS = $(files_built_h)
GTKSOURCEVIEWMM_INT_GENERATED_SOURCES = $(files_built_cc)

# Path to glib-compile-resources.exe
!ifndef GLIB_COMPILE_RESOURCES
GLIB_COMPILE_RESOURCES = $(PREFIX)\bin\glib-compile-resources.exe
!endif
