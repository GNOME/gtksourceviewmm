doxyfile=Doxyfile
doxygenprog=@DOXYGEN@

EXTRA_DIST=$(doxyfile)

html/index.html:
	rm -rf html
	$(doxygenprog) $(doxyfile)

all-local: html/index.html

clean-local:
	rm -rf html

