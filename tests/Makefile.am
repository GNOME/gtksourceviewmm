noinst_PROGRAMS=runtestbasic runtestlangs

runtestbasic_SOURCES=test-basic.cpp
runtestbasic_LDFLAGS=@GTKSOURCEVIEWMM_LIBS@

runtestlangs_SOURCES=test-langs.cpp
runtestlangs_LDFLAGS=@GTKSOURCEVIEWMM_LIBS@

INCLUDES=-I$(top_srcdir)/gtksourceview \
@GTKSOURCEVIEWMM_CFLAGS@

LDADD=$(top_builddir)/gtksourceview/gtksourceviewmm/libgtksourceviewmm-1.0.la

