all: envirobot_test

VPATH = ../../iCreateLib:../EnviRobotC

envirobot_test: envirobot_test.o
	gcc -o envirobot_test envirobot_test.c -lcurses
	
envirobot_test.o: envirobot_test.c envirobot_test.h envirobot_shm.h
	gcc -c envirobot_test.c

clean:
	rm -f *.o
	rm -f envirobot_test

