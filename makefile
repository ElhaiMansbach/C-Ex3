CC=gcc
FLAGS = -Wall -g -fPIC
OBJECTS_MAIN1 = main1.o
OBJECTS_MAIN2= main2.o

all: isort txtfind

isort: main1.c isort.c isort.h
	$(CC) $(FLAGS) isort.c main1.c -o isort

txtfind: main2.c txtfind.c txtfind.h
	$(CC) $(FLAGS) txtfind.c main2.c -o txtfind


.PHONY: clean all 

clean:
	rm -f *.o isort txtfind