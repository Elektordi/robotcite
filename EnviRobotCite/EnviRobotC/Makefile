all: envirobot

VPATH = ../../iCreateLib

envirobot: envirobot.o iCreateLib.o serialLib.o
	gcc -o envirobot envirobot.o iCreateLib.o serialLib.o
	
envirobot.o: envirobot.c envirobot.h envirobot_shm.h iCreateLib.h
	gcc -c envirobot.c

clean:
	rm -f *.o
	rm -f envirobot

