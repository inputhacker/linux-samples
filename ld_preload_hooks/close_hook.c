
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <dlfcn.h>
#include <execinfo.h>
#include <unistd.h>

typedef int (*org_syscall_close)(int fd);
void btrace(void);

int close(int fd)
{
   int res;

   org_syscall_close org_close;
   org_close = (org_syscall_close)dlsym(RTLD_NEXT, "close");

   btrace();

   res = org_close(fd);   

   return res;
}

void btrace(void)
{
   int j, nptrs;
   void *buffer[128];
   char **strings;
   pid_t pid = getpid();

   nptrs = backtrace(buffer, 128);
   //printf("[PID:%d] backtrace() returns %d addresses.\n", pid, nptrs);

   strings = backtrace_symbols(buffer, nptrs);

   if (!strings)
   {
      perror("backtrace_symbols");
      exit(EXIT_FAILURE);
   }

   for(j = 0; j < nptrs ; j++)
   {
      printf("[PID:%d] %s\n", pid, strings[j]);
   }

   free(strings);
}
