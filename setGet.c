#include <stdlib.h>

#include "set.h"
#include "dbg.h"

int
setGet(Element elements[], Set set){
  /*extracts all elements of set into array of elements.
    Assumes the elements array is large enough to hold all
    elements in the set.
  */
  int i,nchars;
  Element e;
  Set setp;

  if (set == NULL)
    return -1;
  i = 0;
  for (setp = set; setp->next != NULL; setp = setp->next){
    nchars = strlen(setp->element) + 1;
    e = malloc(nchars);
    strncpy(e, setp->element, nchars);
#ifdef DEBUG
    debug("extracting %s to element[%d]", e, i);
#endif
    elements[i++] = e;
  }
  return 0;
}
