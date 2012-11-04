#include <stdlib.h>
#include <string.h>

#include "set.h"

int
main(int argc, char *argv[]){
  Set a,b,c,uab,iab;
  Element ea[] = { "r", "s", "t", "r", NULL};
  Element eb[] = { "fred", "al", "ben", "s", "t", NULL};
  Element ec[] = { "fred", "al", NULL};
  Element eiab[10];
  int n;
  setInit(&a, ea);
  setinit(&b, eb);
  setinit(&c, ec);
  //setUnion(&uab,a,b);
  //setIntersection(&iab,a,b);

  n = sizeof(eiab)/sizeof(Element);
  setDestroy(&a);
  setDestroy(&b);
  setDestroy(&c);
  setDestroy(&uab);
  setDestroy(&iab);
  exit(0);
}
