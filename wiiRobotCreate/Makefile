all: wiirobot

VPATH = ../iCreateLib

wiirobot: wiirobot.o iCreateLib.o serialLib.o
	gcc -o wiirobot wiirobot.o iCreateLib.o serialLib.o -lcwiid
	
wiirobot.o: wiirobot.c wiirobot.h iCreateLib.h
	gcc -c wiirobot.c

clean:
	rm -f *.o
	rm -f wiirobot

