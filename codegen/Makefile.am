AUTOMAKE_OPTIONS = subdir-objects

include $(srcdir)/m4/filelist.am

dist_noinst_DATA = $(addprefix m4/,$(files_codegen_m4))
noinst_PROGRAMS = extradefs/generate_extra_defs

extradefs_generate_extra_defs_SOURCES = extradefs/generate_extra_defs_gtksourceview.cc
extradefs_generate_extra_defs_LDADD   = $(GTKSOURCEVIEWMM_LIBS) -lglibmm_generate_extra_defs-2.64

AM_CPPFLAGS = -I$(top_builddir) $(GTHREAD_CFLAGS) $(GTKSOURCEVIEWMM_CFLAGS)
AM_CXXFLAGS = $(GTKSOURCEVIEWMM_WXXFLAGS)

.DELETE_ON_ERROR:

