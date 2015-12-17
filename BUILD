

C_FLAGS = [
    "-Wall",
    "-ansi",
    "-Wno-unused-variable",
    "-pedantic",
    "-Werror",
    "-c",
]

cc_library(
    name="libxstring",
    hdrs=glob(["*.h"]),
    includes=[
        "/usr/lib/",
        "/usr/include"
    ],
    copts= C_FLAGS,
    srcs=glob(["*.c"]),
)
cc_binary(
	name = 'test',
	srcs = [
	       'tests/test.c',
	    ],
        copts= C_FLAGS,
	deps = [
	       ':libxstring',
	    ]
)
