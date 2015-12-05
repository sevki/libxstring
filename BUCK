cxx_library(
	name = 'libxstring',
	headers = glob(['*.h']),
	compiler_flags = [
	      '-ansi',
	      '-Wno-unused-variable',
          '-Wno-system-headers',
	      '-pedantic',
	      '-c',
	],
	srcs = glob(['*.c']),
)

cxx_binary(
	name = 'test',
	srcs = [
	       'tests/test.c',
	    ],
	deps = [
	       ':libxstring',
	    ]
)
