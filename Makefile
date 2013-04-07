xstring: xstring.c bm.c
	gcc -Wall -ansi -Wno-unused-variable -pedantic -Werror -c  xstring.c bm.c
archive: xstring
	ar cr libxstring.a xstring.o bm.o
install: archive
	cp -i xstring.h /usr/local/include/xstring.
	cp -i libxstring.a /usr/local/lib/libxstring.a
	rm xstring.o bm.o libxstring.a
install-ow: archive
	yes | cp -i xstring.h /usr/local/include/xstring.h
	yes | cp -i libxstring.a /usr/local/lib/libxstring.a
	rm xstring.o bm.o libxstring.a
test: xstring
	gcc  tests/test.c xstring.o bm.o  -Wno-unused-variable -o test
	./test
	rm xstring.o bm.o test
