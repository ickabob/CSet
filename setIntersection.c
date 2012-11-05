#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "dbg.h"

int
setIntersection(Set *setiAB, Set setA, Set setB){
  /*A intersect B is {x | x exists in A && x exists in B}.*/
  int i;
  Set setp, prev_setp, intersect_setp;
  size_t nchars;
  Element e;
  
  /*want valid references*/
  if((setA == NULL) || (setB == NULL))
    return -1;

  intersect_setp = malloc(sizeof(setElement));
  //so we know what the memory block contains.
  memset((void*)intersect_setp, 0, sizeof(setElement));
  *setiAB = intersect_setp;
  i = 0;
  for (setp = setA; setp->next != NULL; setp = setp->next){
    e = setp->element;
    //if not exist in setB we dont want to add it.
    if(!setIsElement(e,setB))
      continue;
    //else add it
#ifdef DEBUG
    debug("Add \"%s\" to Set %p.",e,(void*)(*setiAB));
#endif
    ++i;
    nchars = strlen(e) + 1;
    intersect_setp->element = malloc(nchars);
    strncpy(intersect_setp->element, e, nchars);
    prev_setp = intersect_setp;
    intersect_setp = malloc(sizeof(setElement));
    prev_setp->next = intersect_setp;
  }
#ifdef DEBUG
  setDisplay(*setiAB);
#endif
  return 0;
}
