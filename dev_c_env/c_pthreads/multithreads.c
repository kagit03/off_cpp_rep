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


//Thread for sum calculator
void* summer(void* arg){
	sum_args_st *ptr_to_str=(sum_args_st*)arg;
	ptr_to_str->sum = 0;

	for (int i=1;i<= ptr_to_str->limit ; i++){
		ptr_to_str->sum += i;		
	}
	
	//ptr_to_str->sum= sum;

	//3. EXIT THE THREAD
	pthread_exit(0);
	
}

//function for thread creation
void create_thrs(int cnt, char** argv){
		
	sum_args_st data_arr[cnt];
       //1A.THREAD ID	
	pthread_t tid[cnt];

	for (int i=0;i < cnt ;i++){
		//assign value from cmd to appropriate	
		data_arr[i].limit= atoi(argv[i+1]);
		//1.CREATE ANS INITIALIZE THREAD ATTRIBUTES	
		
		pthread_attr_t attr;
		pthread_attr_init(&attr);

		//2.SPAWN THREAD
		pthread_create(&tid[i], &attr, summer, &data_arr[i]);
	}

	for (int j=0;j < cnt; j++){
		//4.WAIT FOR THREAD TO JOIN
		pthread_join(tid[j], NULL);

		//print output
		printf("sum in thread%d is  %d\n", j+1, data_arr[j].sum);
	}
}

int main (int argc, char** argv){
        
	if (argc < 2){
		printf("Usage sumup <num1>\n");
	 	exit (-1);
	}
	
	int num_args = argc-1;

	//call function to init and spawn thread/s and wait for it
	create_thrs(num_args, argv);
	
	return 0;
}
