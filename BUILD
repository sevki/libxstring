cc_lib(
	name = "libxstring",
	hdrs = glob(["*.h"]),
	includes = [
		 "/usr/lib/",
		 "/usr/include"
	     ],
	copts = [
	      "Wall",
	      "ansi",
	      "Wno-unused-variable",
	      "pedantic",
	      "Werror"
	      "c"
	],
	srcs = glob(["*.c"]),
)
cc_bin(
	name = "test",
	srcs = [
	       "tests/test.c",
	    ],
	deps = [
	       "libxstring",
	    ]
)	
