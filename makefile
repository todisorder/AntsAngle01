CC=g++
Version=01
OBJ=AntsAngle$(Version).o
#CFLAGS=-Wall -g -std=c++11
CFLAGS= -g -std=c++11

antsangle$(Version):$(OBJ)
	$(CC) -o antsangle$(Version) $(OBJ) -lm

$(OBJ):AntsAngle$(Version).cpp
	$(CC) $(CFLAGS) -c AntsAngle$(Version).cpp 

clean:
	rm -f *.o;
	rm -f antsangle$(Version);

