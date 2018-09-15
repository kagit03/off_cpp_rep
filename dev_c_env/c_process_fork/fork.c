#include<stdio.h>
#include<unistd.h>

//compile with gcc -Wall -Werror -o fork fork.c
//fork returns child PID to parnet PID
//fork=0 returns 0 to child processs om success
//fork<0 returns -ve on system call error

int main(){
	int x = 1;
	int retval = fork();//ret val is the PID of the child process
	if (retval == 0){
		// This is executed by the child process
		printf ("I am the child process %d\n", ++x);
	}else{
		// This is executed bythe parent process
		printf ("I am the parent process %d\n", --x);
	}
	return 0;
}
	
