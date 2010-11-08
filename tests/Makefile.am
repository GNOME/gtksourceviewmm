AUTOMAKE_OPTIONS = subdir-objects

check_PROGRAMS =	\
	basic/test	\
	langs/test	\
	search/test	\
	get_buffer/test	\
	mime_types/test	\
	completion/test

basic_test_SOURCES	= basic/main.cc
langs_test_SOURCES	= langs/main.cc
search_test_SOURCES	= search/main.cc
get_buffer_test_SOURCES	= get_buffer/main.cc
mime_types_test_SOURCES	= mime_types/main.cc
completion_test_SOURCES	= completion/main.cc

gtksourceviewmm_includes = -I$(top_builddir)/gtksourceview $(if $(srcdir:.=),-I$(top_srcdir)/gtksourceview)
gtksourceviewmm_ldadd    = $(top_builddir)/gtksourceview/gtksourceviewmm/libgtksourceviewmm-$(GTKSOURCEVIEWMM_API_VERSION).la

local_includes = -I$(top_builddir) $(gtksourceviewmm_includes)
local_ldadd    = $(gtksourceviewmm_ldadd)

AM_CPPFLAGS = $(local_includes) $(GTHREAD_CFLAGS) $(GTKSOURCEVIEWMM_CFLAGS)
AM_CXXFLAGS = $(GTKSOURCEVIEWMM_WXXFLAGS)
LDADD       = $(GTKSOURCEVIEWMM_LIBS) $(local_ldadd)
