include $(top_srcdir)/gtksourceview/src/filelist.am
include $(top_srcdir)/gtksourceview/gtksourceviewmm/filelist.am

gtksourceviewmm_files_h = $(files_built_h) $(filter-out wrap_init.h,$(files_extra_h))

book_name = $(GTKSOURCEVIEWMM_MODULE_NAME)
doc_input = $(addprefix $(top_srcdir)/gtksourceview/gtksourceviewmm/,$(gtksourceviewmm_files_h)) $(top_srcdir)/gtksourceview/gtksourceviewmm.h

include $(top_srcdir)/build/doc-reference.am
