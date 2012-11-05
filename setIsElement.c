#include <string.h>

#include "set.h"
#include "dbg.h"

int
setIsElement(Element element, Set set2){
  /* Ian write a doc string dummy.
   */
  int i;
  size_t nchars;
  Element e;
  Set setp;

  i = 0;
  nchars = strlen(element) + 1;
  
  for (setp = set2; setp->next != NULL; setp = setp->next){
    ++i;
    e = setp->element;
    if ((strncmp(e,element,nchars)) == 0){
#ifdef DEBUG
      debug("matched %s in position %d.",e,i);
#endif
      return 1;  //they match and element exists in set2.
    }
  }
  return 0;
}
