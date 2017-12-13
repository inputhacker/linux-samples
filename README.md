# linux-samples

[Description]
This project is a collection of linux samples.

[Sample description]
- callstack.c
  : sample program to test sample hooks in ld_preload_hooks directory

- ld_preload_hooks/close_hook.c
  : sample implmentation to display backtrace when close() is called in a process

[How to build]
- run ./build.sh

[How to clean up]
- run ./build.sh clean

[How to test]
- callstack
  : LD_PRELOAD=./close_hook-{arch}.so ./callstack-{arch}
    * Note that {arch} is a machine name comes from "uname -m" command.

