dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(catseek, 0.1)

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE()

AC_PROG_CXX
AC_PROG_CC

AC_CHECK_HEADER_STDBOOL
AC_CHECK_HEADERS([stdlib.h string.h unistd.h])
AC_CHECK_FUNCS([memset pow sqrt])
AC_FUNC_MALLOC

AC_CONFIG_FILES(Makefile src/Makefile)
AC_OUTPUT

