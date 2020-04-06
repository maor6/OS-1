#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>
#include <signal.h>


#define SIZE 12000
#define SIZE2 6000

// subtask 2
void do_something(char *s){
    if(s == NULL) s = "clone process";
    for(int i =0; i < 20; i++) {
    	printf("pid: %d ,HELLO from %s\n",getpid(),s);
	usleep(1000000);
    }
}

int main() {
    void *stack = malloc(SIZE);

    /*CLONE_VM (since Linux 2.0)
      If CLONE_VM is set, the calling process and  the  child  process
      run in the same memory space. (from 'man clone') */
    //int c = clone(&do_something,stack + SIZE, CLONE_VM, 0);

    int c = clone(&do_something,stack + SIZE, CLONE_PARENT, 0);
    if ( c < 0 ) {
        printf("ERROR: Unable to create the child process.\n");
        exit(EXIT_FAILURE);
    }
    //second clone
    int d = clone(&do_something,stack + SIZE2, CLONE_PARENT, 0);
     // int d = clone(&do_something,stack + SIZE, CLONE_VM, 0);
    if ( d < 0 ) {
        printf("ERROR: Unable to create the child process.\n");
        exit(EXIT_FAILURE);
    }

    do_something("main process");
    usleep(10000000);
    free(stack);
    return 0;
}
