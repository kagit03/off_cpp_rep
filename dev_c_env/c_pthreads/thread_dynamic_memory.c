#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

//command to compile 
//gcc -g -std=c99 -pthread -o sumup threads.c
//-g is to add sybolics for gdb to fetch our source code


int sum;


//Thread for sum calculator
void* summer(void* args){
	int val_limit=*(int*)args;
	//free memory
	free(args);

	for (int i=1;i<= val_limit ; i++){
		sum += i;
	}
	int *answer = malloc(sizeof(*answer));
	*answer = sum;
	//3. EXIT THE THREAD
	pthread_exit(answer);
	
}


int main (int argc, char** argv){
        
	if (argc < 2){
		printf("Usage sumup <num1>\n");
	 	exit (-1);
	}
	int num_args = argc-1;

	//assign value from cmd to appropriate
	int *limit = malloc(sizeof(*limit));
	*limit= atoi(argv[1]);
	
	//1.CREATE ANS INITIALIZE THREAD ATTRIBUTES	
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	//2.SPAWN THREAD
	pthread_create(&tid, &attr, summer, limit);

	//4.WAIT FOR THREAD TO JOIN
	int *sum;
	pthread_join(tid, (void**)&sum);
	//print output
	printf("sum is %d\n", *sum);
	free(sum);
	
	return 0;
}
