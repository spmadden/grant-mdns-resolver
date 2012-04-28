AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS} -I autoconf-boost/build-aux
AM_CXXFLAGS = -Wall -g
AM_CPPFLAGS = $(DEPS_CFLAGS)


bin_PROGRAMS = mdns-resolver
mdns_resolver_LDFLAGS = $(BOOST_PROGRAM_OPTIONS_LDFLAGS)
mdns_resolver_LDADD = $(BOOST_PROGRAM_OPTIONS_LIBS) \
				$(GTEST_LIBS)
mdns_resolver_CPPFLAGS = $(BOOST_PROGRAM_OPTIONS_CPPFLAGS) \
				$(GTEST_CFLAGS)
mdns_resolver_SOURCES = src/main.cpp

dist_noinst_SCRIPTS = autogen.sh

