
xstring: xstring.c bm.c
	gcc -Wall -ansi -Wno-unused-variable -pedantic -Werror -c  xstring.c bm.c 
	ar cr libxstring.a xstring.o bm.o
install: xstring
	cp -i xstring.h /usr/local/include/xstring.h
	cp -i libxstring.a /usr/local/lib/libxstring.a
install-ow: xstring
	yes | cp -i xstring.h /usr/local/include/xstring.h
	yes | cp -i libxstring.a /usr/local/lib/libxstring.a
test: xstring
	gcc  tests/test.c xstring.o bm.o  -Wno-unused-variable -o test 
	./test
