#include <string.h>
#include <stdlib.h>
#include "set.h"
#include "dbg.h"
#define MAXLINE 1000

int
setDisplay(Set set){
  char *setAsString;
  Set setp;
  Element e;

#ifdef DEBUG
  debug("Displaying set at address: %p.\n",set);
#endif
  if(set == NULL){
    return -1;
  }
  setp = set;
  setAsString = (char*)malloc(MAXLINE);
  for (e = setp->element; (e = setp->element) != NULL; setp = setp->next){
    strcat(setAsString, "{");
    strcat(setAsString, e);
    strcat(setAsString, "} --> ");
  }
  strcat(setAsString, "{NULL}\0");
  fprintf(stderr,"%s\n",setAsString);
  free(setAsString);
  return 0;
}

