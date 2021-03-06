#!/bin/sh

UHEXEN2_TOP=../../..
. $UHEXEN2_TOP/scripts/cross_defs.w32

if test "$1" = "strip"; then
	$STRIPPER hwcl.exe glhwcl.exe
	exit 0
fi

HOST_OS=`uname|sed -e s/_.*//|tr '[:upper:]' '[:lower:]'`
case "$HOST_OS" in
freebsd|openbsd|netbsd)
	MAKE_CMD=gmake ;;
linux)	MAKE_CMD=make ;;
*)	MAKE_CMD=make ;;
esac

if test "$1" = "all"; then
	shift
	$MAKE_CMD clean
	$MAKE_CMD glhw USE_X86_ASM=no $* || exit 1
	$MAKE_CMD clean
	$MAKE_CMD hw $* || exit 1
	$MAKE_CMD clean
	exit 0
fi

exec $MAKE_CMD $*

