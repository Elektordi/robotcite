all: test

VPATH = ..

test: iCreateTest.o iCreateLib.o serialLib.o
	gcc -o test iCreateTest.o iCreateLib.o serialLib.o

iCreateTest.o: iCreateTest.c iCreateLib.h serialLib.h
	gcc -c iCreateTest.c
	
clean:
	rm -f *.o
	rm -f test

