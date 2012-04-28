AC_INIT([mdns-resolver], [0.1], [sean@seanmadden.net], [mdns], [http://www.seanmadden.net])
AC_PREREQ([2.59])
AC_CONFIG_AUX_DIR([autoconf-boost/build-aux])

AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.10 no-define])

# Checks for programs.
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LIBTOOL

# Checks for libraries.
BOOST_REQUIRE([1.47.0])
BOOST_PROGRAM_OPTIONS

AC_ARG_WITH([gtest-include-path],
  [AS_HELP_STRING([--with-gtest-include-path],
    [location of the GTEST headers, defaults to /usr/include/])],
  [GTEST_CFLAGS="-I$withval"],
  [GTEST_CFLAGS='-I/usr/include/'])
AC_SUBST([GTEST_CFLAGS])

AC_ARG_WITH([gtest-lib-path],
  [AS_HELP_STRING([--with-gtest-lib-path], [location of the GTEST libraries])],
  [GTEST_LIBS="-L$withval -lgtest"],
  [GTEST_LIBS='-lgtest'])
AC_SUBST([GTEST_LIBS])

AC_LANG([C++])
CPPFLAGS=-I$GTEST_CFLAGS

# Checks for header files.
AC_CHECK_HEADER([gtest/gtest.h], , 
	[AC_MSG_ERROR([Cannot find gtest.h])])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

