#!/bin/sh

# *********************************
# * Guillaume Genty, Octobre 2008 *
# *     Projet  EnviRobotCité     *
# * Association  Planète Sciences *
# *********************************
#
# Based on URBI (gostai.com)
# License GNU-GPL
# guillaume.genty@planete-sciences.org
#

echo "*********************************"
echo "* Guillaume Genty, Octobre 2008 *"
echo "*     Projet  EnviRobotCité     *"
echo "* Association  Planète Sciences *"
echo "*********************************"
echo
sleep 1
cd ../../bin

echo "Stopping any running URBI engine..."
echo "shutdown;" | nc localhost 54000
echo "Done. Starting 'EnviRobotCité' URBI engine!"
echo
sleep 2

XTERM="gnome-terminal -x"

# command1 2>&1 command2 = sends both the standard output and standard error of command1 to the standard input of command2.
LD_LIBRARY_PATH=../lib:$LD_LIBRARY_PATH $XTERM sh -c "./create -P 30  -I ../gostai/EnviRobotCite 2>&1 | tee ../gostai/EnviRobotCite/urbi.log" &

# WARNING: Set the number of uobjects to load in URBI.INI !!!

#sleep 1
#echo 3s delay before uobjects to attach...
#sleep 2
#LD_LIBRARY_PATH=../lib:$LD_LIBRARY_PATH $XTERM ../uobjects/uwiimote &

sleep 1
echo 5s delay before starting client...
sleep 1
echo
echo "*** NOTE: ***"
echo "For exiting the engine, DON'T USE CTRL+C HERE! Use \"^]q\" (telnet exit sequence)."
echo "(Or simply close the 'urbi server' terminal.)"
echo
sleep 3
telnet localhost 54000

sleep 1
echo "shutdown;" | nc localhost 54000
sleep 1
echo "*** ENGINE TERMINATED ***"
