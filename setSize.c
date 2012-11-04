
#include "set.h"
#include "dbg.h"

int
setSize(Set set){
  int count;
  Set setp;
  Element e;
  /*QUESTION SHOULD THE NULLSET COUNT AS AN ELEMENT?*/
  count = 0;
  for (setp = set; setp->next != NULL; setp = setp->next){
    e = setp->element;
    //question:
    //what is a Set structure with a valid next but a null element?
    if(e != NULL)
      count++;
  }
  return count;
}
