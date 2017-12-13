#!/bin/sh

if [ "$1" = "clean" ]; then
	rm -f ./callstack-`uname -m` ./close_hook-`uname -m`.so
	exit 1
fi

gcc -o ./callstack-`uname -m` ./callstack.c -rdynamic
gcc --shared -fPIC -o ./close_hook-`uname -m`.so ld_preload_hooks/close_hook.c -ldl

