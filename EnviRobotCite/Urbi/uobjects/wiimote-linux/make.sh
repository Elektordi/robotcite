#!/bin/sh

umake -C remote -o uwiimote wiimote.cc EXTRA_LDFLAGS=-lcwiid
#g++ wiimote.cc -lcwiid -lliburbi -Iinc -Llib

cp uwiimote uobjects/
