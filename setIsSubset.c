
#include "set.h"
#include "dbg.h"

int
setIsSubset(Set set1, Set set2){
  /*Return true if set1 is a proper subset of set2.*/
  Set setp;
  Element e;
  /*obvious edge cases:
   1. when one of set1 or set2 is null.
   2. when both set1 and set2 are null.
   3. when both set1 and set2 are valid datastructures,
      but when one is the set containing the nullset.
   */

  //DO NOT TURN THIS IN WITHOUT IMPLEMENTING EDGE CASE CHECKS.
  //DONT BE A DUMMY IAN!
  setp = set1;
  for (setp = set1; setp->next != NULL; setp = setp->next){
    e = setp->element;
    if(!setIsElement(e,set2))
      return 0;  //an element in set1 does not exist in set2.
  }
  //all elements e in set1 exist in set2.
  return 1;
}  

