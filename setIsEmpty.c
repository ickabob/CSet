#include "set.h"
#include "dbg.h"

int
setIsEmpty(Set set){
  Set setp;
  Element e;

  if (set == NULL)
    return -1;
  setp = set;
  e = setp->element;
  if (e == NULL && setp->next == NULL)
    return 1;
  else
    return 0;
}
