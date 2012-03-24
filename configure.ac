AC_INIT([mdns-resolver], [0.1], [sean@seanmadden.net], [mdns], [http://www.seanmadden.net])
AC_PREREQ([2.59])
AM_INIT_AUTOMAKE([1.10 no-define])

AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_INSTALL

# Checks for libraries.

AC_ARG_WITH([boost-include-path],
	[AS_HELP_STRING([--boost-include-path],
		[location of the boost include headers, defaults to /usr/include])],
	[BOOST_CFLAGS="-I$withval"],
	[BOOST_CFLAGS="-I/usr/include"])
AC_SUBST([BOOST_CFLAGS])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

