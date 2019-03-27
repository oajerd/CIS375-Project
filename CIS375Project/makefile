# Author: Machunde S. Tandasi
# Class: CSIS 352
# Assignment 5
# 10/28/2014

CC = g++
CFLAGS = 
LFLAGS = 

OBJECTS = main.o city.o graphmain.o

p:		$(OBJECTS)
		$(CC) -o p $(OBJECTS) $(LFLAGS)

main.o:		main.cpp graph.h city.h
		$(CC) $(CFLAGS) -c main.cpp
		
graphmain.o:	graphmain.cpp graph.h city.h
		$(CC) $(CFLAGS) -c graphmain.cpp
		
city.o: 	city.cpp city.h
		$(CC)  -c city.cpp

clean:		
		rm -rf p $(OBJECTS)
