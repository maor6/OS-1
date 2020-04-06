CC = gcc
FLAGS = -g -Wall


all: sub1 sub2 sub3 sub4

sub1: sub1.o
	$(CC) $(FLAGS) -o sub1 sub1.o

sub2: sub2.o
	$(CC) $(FLAGS) -o sub2 sub2.o

sub3: sub3.o
	$(CC) $(FLAGS) -o sub3 sub3.o

sub4: sub4.o sub1 sub2 sub3
	$(CC) $(FLAGS) -o sub4 sub4.o


sub1.o:
	$(CC) $(FLAGS) -c sub1.c

sub2.o:
	$(CC) $(FLAGS) -c sub2.c

sub3.o:
	$(CC) $(FLAGS) -c sub3.c

sub4.o:
	$(CC) $(FLAGS) -c sub4.c


.PHONY: clean all 

clean: 
	rm -f *.o *.so sub1 sub2 sub3 sub4

