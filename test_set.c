// test_set.h 
// CS 454 Fall 2012
// This program tests the cs 454 set library
//

#include <stdio.h>
#include <stdlib.h>
#include "set.h"
#include "dbg.h"

int main() {
Element ea[] = { "r", "s", "t", "r", NULL};
Element eb[]  = { "fred", "al", "ben", "s", "t", NULL};
Element ec[]  = { "fred", "al", NULL};
Element ed[]  = { NULL};
Set	a,b,c,d,uab,iab;
Element eiab[10];
int	n;
int	i;

setInit(&a, ea);
setInit(&b, eb);
setInit(&c, ec);
setInit(&d, ed);
setUnion(&uab,a,b);
setIntersection(&iab,a,b);

n = sizeof(eiab)/sizeof(Element);
if( setSize(iab) < n ) {
  setGet(eiab, iab);
  for(i=0; i<n; i++) {
    printf("%d\t%s\n", i, eiab[i]);
  }
} else {
  printf("Set to large for array\n");
}

return 0;
}

