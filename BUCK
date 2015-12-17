C_FLAGS = [
    "-Wall",
    "-ansi",
    "-Wno-unused-variable",
    "-pedantic",
    "-Werror",
    "-c",
]

cxx_library(
    name="libxstring",
    headers=glob(["*.h"]),
    platform_headers=[
        "/usr/lib/",
        "/usr/include"
    ],
    compiler_flags= C_FLAGS,
    srcs=glob(["*.c"]),
)
	