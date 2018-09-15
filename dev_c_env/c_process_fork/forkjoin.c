#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>//fexit
#include<sys/wait.h>//wait

//compile with gcc -Wall -Werror -o fork fork.c
//fork>0 returns child PID to parnet PID
//fork=0 returns 0 to child processs om success
//fork<0 returns -ve on system call error

int main(){
	pid_t childPIDorZero = fork();//ret val is the PID of the child process
	if (childPIDorZero < 0){
		perror("fork() error");
		exit (-1);
	}
	if (childPIDorZero != 0){
		// This is executed by the parent process
		printf ("The child PID= %d and parent PID %d\n", childPIDorZero, getpid());
		wait(NULL);//wait for the child process to join
	}else{
		// This is executed bythe child process
		printf ("The child PID=%d and my parent %d\n", getpid(),getppid());
		execl("/bin/echo","echo","Hello from Mangal",NULL);
	}
	return 0;
}
