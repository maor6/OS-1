CC = gcc
FLAGS = -g -Wall


all: main main2 main3

main: main1_1.o hello_Ariel.o
	$(CC) $(FLAGS) -o main main1_1.o hello_Ariel.o

main2: main1_2.o lib_hello_Arield
	$(CC) $(FLAGS) -o main2 main1_2.o ./libhelloAriel.so

main3: lib_hello_Arield
	$(CC) $(FLAGS) -o main3 main1_3.c -ldl

lib_hello_Arield: hello_Ariel.o
	$(CC) -shared -o libhelloAriel.so hello_Ariel.o

main1_1.o: main1_1.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_1.c

main1_2.o: main1_2.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_2.c

hello_Ariel.o: hello_Ariel.c hello_Ariel.h
	$(CC) $(FLAGS) -c hello_Ariel.c



.PHONY: clean all 

clean: 
	rm -f *.o *.so main main2 main3

