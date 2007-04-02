noinst_PROGRAMS=\
runtestbasic runtestlangs \
runtestsearch runtestmimetypes \
runtestgetbuffer

runtestbasic_SOURCES=test-basic.cpp
runtestbasic_LDFLAGS=@GTKSOURCEVIEWMM_LIBS@

runtestlangs_SOURCES=test-langs.cpp
runtestlangs_LDFLAGS=@GTKSOURCEVIEWMM_LIBS@

runtestsearch_SOURCES=test-search.cpp
runtestsearch_LDFLAGS=@GTKSOURCEVIEWMM_LIBS@

runtestmimetypes_SOURCES=test-mime-types.cpp
runtestmimetypes_LDFLAGS=@GTKSOURCEVIEWMM_LIBS@

runtestgetbuffer_SOURCES=test-get-buffer.cpp
runtestgetbuffer_LDFLAGS=@GTKSOURCEVIEWMM_LIBS@

INCLUDES=-I$(top_srcdir) -I$(top_srcdir)/gtksourceview \
@GTKSOURCEVIEWMM_CFLAGS@

LDADD=$(top_builddir)/gtksourceview/gtksourceviewmm/libgtksourceviewmm-1.0.la

