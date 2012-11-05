#include <stdlib.h>

#include "set.h"
#include "dbg.h"

int
setDestroy(Set *set){
  /* Ian write a doc string dummy.
   */
  Set setp, prev_setp;
  #ifdef DEBUG
  int nchars;
  #endif

#ifdef DEBUG
  debug("Destorying set at address: %p.\n",(void*)*set);
  setDisplay(*set);
#endif
  if(set == NULL)
    return -1;
  for (setp = *set; setp != NULL; free(prev_setp) ){
    #ifdef DEBUG
    nchars = strlen(setp->element) + 1;
    debug("Freeing struct setElement %p:\n\t", (void*)setp);
      debug("%p.element %d bytes at address %p.\n\t", (void*)setp, nchars, (void*)&(setp->element));
      //debug("%p (allocated structure) %l bytes.\n", (void*)setp, sizeof(setElement));
    #endif
    free(setp->element);
    prev_setp = setp;
    setp = setp->next;
  }
  return 0;
}

