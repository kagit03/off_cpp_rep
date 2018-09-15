#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

//command to compile 
//gcc -g -std=c99 -pthread -o sumup threads.c
//-g is to add sybolics for gdb to fetch our source code

typedef struct sum_args{
	int limit;
	int sum;
}sum_args_st;

sum_args_st data_arr;

//Thread for sum calculator
void* summer(void* arg){
	sum_args_st *ptr_to_str=(sum_args_st*)arg;

	for (int i=1;i<= ptr_to_str->limit ; i++){
		ptr_to_str->sum += i;
	}
	
	//3. EXIT THE THREAD
	pthread_exit(0);
	
}

//function for thread creation
void create_thrs(void){
		
	
	//1.CREATE ANS INITIALIZE THREAD ATTRIBUTES	
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	//2.SPAWN THREAD
	pthread_create(&tid, &attr, summer, &data_arr);

	//4.WAIT FOR THREAD TO JOIN
	pthread_join(tid, NULL);
}

int main (int argc, char** argv){
        
	if (argc < 2){
		printf("Usage sumup <num1>\n");
	 	exit (-1);
	}
	int num_args = argc-1;
	printf("no of arguments %d\n", num_args);
	//assign value from cmd to appropriate
	data_arr.limit= atoi(argv[1]);
	printf("limit is %d\n", data_arr.limit);

	//call function to init and spawn thread/s
	create_thrs();
	
	//print output
	printf("sum is %d\n", data_arr.sum);
	
	return 0;
}
