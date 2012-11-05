#include <string.h>
#include <stdlib.h>
#include "set.h"
#include "dbg.h"
#define MAXLINE 1000
#ifdef DEBUG
int
setDisplay(Set set){
  char *setAsString;
  Set setp;
  Element e;


  if(set == NULL){
    return -1;
  }
  setp = set;
  setAsString = (char*)malloc(MAXLINE);
  strcat(setAsString, "\t");
  for (e = setp->element; (e = setp->element) != NULL; setp = setp->next){
    strcat(setAsString, "{");
    strcat(setAsString, e);
    strcat(setAsString, "} --> ");
  }
  strcat(setAsString, "{NULL}\0");

  debug("Displaying set at address: %p.\n\t%s", (void*)set, setAsString);

  free(setAsString);
  return 0;
}

#endif
