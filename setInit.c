/* Authors: Ian Kane, Tyler Gravlin, Tim Ham
 * Date: 11112012
 * 
 * Function: setInit
 * 
 * Inputs: Set, Element[]
 * Returns: 0:success, -1: failure
 * Purpose: to create a linked list representing set of strings in the element
 *          element argument
 * Note: set argument is modified
 */
#include <stdlib.h>
#include <string.h>

#include "set.h"
#include "dbg.h"

int
setInit(Set *set, Element elements[]){
  /*
    If there are Elements in elements array then return a
    linked list representing the set of elements.  If there
    is nothing in elements then return the Null Set.
  */
  int i;
  Set setp, prev_setp;
  size_t nchars;
  Element e;
  
  setp = malloc(sizeof(setElement));
  /*initialize allocated memory to 0s.  This will avoid 
    complications when trying to convert to strings.
   */
  memset((void*)setp, 0 , sizeof(setElement));
  *set = setp; 
  i = 0;
  for (e = elements[i]; e != NULL; e = elements[++i]){
    /*next 2 lines are redundent.*/
    setp->next = NULL;
    setp->element = NULL;
    nchars = strlen(e) + 1;
    if (setIsElement(e,*set))
      continue; //element e alreayd exists in set.
#ifdef DEBUG
    debug("(%p,%p,%d,%s)", (void*)setp, (void*)prev_setp, (int)nchars, e);
#endif
    /*get heap memory for string and copy string into new memory*/
    setp->element = malloc(nchars);
    strncpy(setp->element, e, nchars);
    /*point previous to current and ask for a new current.*/
    prev_setp = setp;
    setp = malloc(sizeof(setElement));
    /*hook new element onto next of previous.*/
    prev_setp->next = setp;
  } 
#ifdef DEBUG
  setDisplay(*set);
#endif
  return 0;
}
