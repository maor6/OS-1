#include<stdio.h>
#include <unistd.h>


int main() {

	pid_t pid1 = fork(); //creat process

	if(pid1 == 0) {
		//printf("START SUB1");
		char *c[2] = {"./sub1",NULL};	
		execvp(c[0],c);
		
	}

	pid_t pid2 = fork();

	if(pid2 == 0) {
		//printf("START SUB2");
		char *c[2] = {"./sub2",NULL};	
		execvp(c[0],c);
		
	}

	pid_t pid3 = fork();

	if(pid1 == 0) {
		//printf("START SUB3");
		char *c[2] = {"./sub3",NULL};	
		execvp(c[0],c);
		
	}

	else printf("root\n");		
		
	
usleep(10000000);
return 0;
}
