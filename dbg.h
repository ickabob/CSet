#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define DEBUG 0
#define debug(M, ...) fprintf(stderr, "[DEBUG] %s: %d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

int setDisplay(Set set);

#endif
