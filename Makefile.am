ACLOCAL_AMFLAGS = -I build ${ACLOCAL_FLAGS}

DISTCHECK_CONFIGURE_FLAGS = --enable-warnings=fatal

if MAINTAINER_MODE
src_subdirs = codegen gtksourceview/src
else
src_subdirs =
endif

if ENABLE_DOCUMENTATION
doc_subdirs = docs
else
doc_subdirs =
endif

SUBDIRS = $(src_subdirs) gtksourceview/gtksourceviewmm $(doc_subdirs) tests

dist_noinst_SCRIPTS = autogen.sh

dist_noinst_DATA = ChangeLog.pre-git

gtksourceviewmm_includedir = $(includedir)/$(GTKSOURCEVIEWMM_MODULE_NAME)
gtksourceviewmm_include_HEADERS = gtksourceview/gtksourceviewmm.h
gtksourceviewmm_libincludedir = $(libdir)/$(GTKSOURCEVIEWMM_MODULE_NAME)/include
nodist_gtksourceviewmm_libinclude_HEADERS = gtksourceview/gtksourceviewmmconfig.h

pkgconfigdir = $(libdir)/pkgconfig
nodist_pkgconfig_DATA = gtksourceview/$(GTKSOURCEVIEWMM_MODULE_NAME).pc

include $(top_srcdir)/build/dist-changelog.am
