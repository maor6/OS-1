#include<stdio.h>
#include <unistd.h>

 
//subtask1

int main() { 

	pid_t pid = fork(); //create  childe
	
	if(pid == 0) {
		pid_t pid = fork();
		
		if(pid == 0) {
			printf("grand child\n");	
		}
		else {
			printf("child\n");
		}	
	}
	else {
		printf("parent\n");
	}
usleep(10000000);
return 0;
}
