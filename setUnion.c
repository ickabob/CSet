#include <stdlib.h>
#include <string.h>

#include "set.h"
#include "dbg.h"

int
setUnion(Set *setuAB, Set setA, Set setB){
  int i;
  Set setp, prev_setp, union_setp;
  size_t nchars;
  Element e;

  /*DONT TURN THIS IN WITHOUT CHECKING EDGE CASES
   1. both setA and setB could be invalid.
   2. one of the two could be invalid.
  */
  if((setA == NULL) || (setB == NULL)){
    return -1;
  }
  
  union_setp = malloc(sizeof(setElement));
  /*for saftey clear the allocated memory.*/
  memset((void*)union_setp, 0 , sizeof(setElement));
  *setuAB = union_setp;
  i = 0;
  for (setp = setA; setp->next != NULL; setp = setp->next){
    e = setp->element;
#ifdef DEBUG
    debug("Add \"%s\" to Set %p.",e,(void*)(*setuAB));    
#endif
    ++i;
    nchars = strlen(e) + 1;
    union_setp->element = malloc(nchars);
    strncpy(union_setp->element, e, nchars);
    prev_setp = union_setp;
    union_setp = malloc(sizeof(setElement));
    prev_setp->next = union_setp;
  }
  for (setp = setB; setp->next != NULL; setp = setp->next){
    e = setp->element;
    if(setIsElement(e,setA))
      continue;
#ifdef DEBUG
    debug("Add \"%s\" to Set %p.",e,(void*)(*setuAB));
#endif
    ++i;
    nchars = strlen(e) + 1;
    union_setp->element = malloc(nchars);
    strncpy(union_setp->element, e, nchars);
    prev_setp = union_setp;
    union_setp = malloc(sizeof(setElement));
    prev_setp->next = union_setp;
  }
#ifdef DEBUG
  setDisplay(*setuAB);
#endif
  return 0;
}
