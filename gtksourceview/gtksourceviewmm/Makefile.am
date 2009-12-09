lib_LTLIBRARIES = libgtksourceviewmm-@GTKSOURCEVIEWMM_API_VERSION@.la

include $(srcdir)/../src/filelist.am
include $(srcdir)/filelist.am
include $(top_srcdir)/build/compile-binding.am

AM_CPPFLAGS = $(binding_includes) $(binding_cppflags) $(GTHREAD_CFLAGS) $(GTKSOURCEVIEWMM_CFLAGS)
AM_CXXFLAGS = $(GTKSOURCEVIEWMM_WXXFLAGS)

libgtksourceviewmm_@GTKSOURCEVIEWMM_API_VERSION@_la_SOURCES = $(binding_sources)
libgtksourceviewmm_@GTKSOURCEVIEWMM_API_VERSION@_la_LDFLAGS = -no-undefined -version-info $(GTKSOURCEVIEWMM_SO_VERSION)
libgtksourceviewmm_@GTKSOURCEVIEWMM_API_VERSION@_la_LIBADD  = $(GTKSOURCEVIEWMM_LIBS)
