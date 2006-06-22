## Copyright (c) 2001
## The gtkmm development team.

SUBDIRS                 = private

sublib_name             = gtksourceviewmm
sublib_libname          = gtksourceviewmm-1.0
sublib_libversion       = $(LIBGTKSOURCEVIEWMM_SO_VERSION)
sublib_namespace        = Gtk
sublib_cflags           = $(GTKSOURCEVIEWMM_CFLAGS)
sublib_topdir           = gtksourceview
sublib_win32_dlls_libs	=

sublib_files_extra_posix_cc = 
sublib_files_extra_win32_cc =
sublib_files_extra_general_cc =  init.cc
sublib_files_extra_general_deprecated_cc = 

sublib_files_extra_posix_h = 
sublib_files_extra_win32_h =
sublib_files_extra_general_h = init.h
sublib_files_extra_general_deprecated_h = 

include $(top_srcdir)/build_shared/Makefile_build.am_fragment

lib_LTLIBRARIES	                  = libgtksourceviewmm-1.0.la
libgtksourceviewmm_1_0_la_SOURCES = $(files_built_cc) $(files_extra_cc)
libgtksourceviewmm_1_0_la_LDFLAGS = $(common_ldflags)
libgtksourceviewmm_1_0_la_LIBADD  = $(GTKSOURCEVIEWMM_LIBS)

