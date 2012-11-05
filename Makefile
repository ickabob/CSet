CFLAGS= -Wall -pedantic -std=gnu99 -g
CC= gcc

SRCS = setNew.c setInit.c setDestroy.c setSize.c setGet.c \
  setUnion.c setIntersection.c setIsElement.c setIsEqual.c \
  setIsSubset.c setIsEmpty.c 

OBJS = setNew.o setInit.o setDestroy.o setSize.o setGet.o \
  setUnion.o setIntersection.o setIsElement.o setIsEqual.o \
  setIsSubset.o setIsEmpty.o 

all: test_set libset.a

${OBJS}: set.h dbg.h

test_set: test_set.c set.h libset.a
	${CC} ${CFLAGS} -o test_set test_set.c libset.a

sandbox: sandbox.c set.h libset.a
	${CC} ${CFLAGS} -o sandbox sandbox.c libset.a

libset.a: ${OBJS} set.h
	ar -r libset.a $?
	ranlib libset.a

tar:
	tar cvf as1.tar  Makefile README set.h test_set.c

clean:
	rm -f libset.a *.o test_set
