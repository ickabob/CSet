// set.h 
// These are the prototypes for CS 454 set library assignment
//

// The folowing two declarations are for a linked list
// data structure for sets. Each element is a C "string"

typedef	char *Element;

struct setElement { 
struct setElement *next;
Element		element;	
};

typedef struct setElement *Set;
/*ADDED Sun Oct 28 20:05:03 EDT 2012
  by Ian Kane. NEED TO ASK DR K IF THIS IS ACCEPTABLE.*/
typedef struct setElement setElement;

int	setInit(Set *set, Element element[]); 
int	setDestroy(Set *set);
int	setSize(Set set); 
int	setGet(Element element[], Set set); // should add n OR ...!

int	setUnion(Set *setuAB, Set setA, Set setB);
int	setIntersection(Set *setiAB, Set setA, Set setB);
int	setIsElement(Element element, Set set2); 
int	setIsEqual(Set set1, Set set2); 
int	setIsSubset(Set set1, Set set2); 
int	setIsEmpty(Set set); 

