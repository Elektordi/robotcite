all: envirobotgui

VPATH = ../EnviRobotC

GTK-C = `pkg-config --cflags gtk+-2.0`
GTK-L = `pkg-config --libs gtk+-2.0`

envirobotgui: envirobotgui.o
	gcc $(GTK-L) -o envirobotgui envirobotgui.o
	
envirobotgui.o: envirobotgui.c envirobotgui.h envirobot_shm.h
	gcc $(GTK-C) -c envirobotgui.c

clean:
	rm -f *.o
	rm -f envirobotgui

