#include <stdlib.h>
#include "set.h"


int
setIsEqual(Set set1, Set set2){
  /*Two sets X,Y are equal iff X is a proper subset of Y
     and Y is a proper subset of X.*/
  
  /* Need two valid references to type Set to test containment.*/
  if ((set1 == NULL) || (set2 == NULL))
    return -1;
#ifdef DEBUG
  debug();
#endif
  return ((setIsSubset(set1,set2)) && (setIsSubset(set2,set1)));
 
} 
