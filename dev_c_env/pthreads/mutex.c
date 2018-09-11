/*=====================MUTEX IMPLEMENTATION=====================*/

#include<stdio.h>
#include<pthread.h>

#define NO_LOOPS  5000000

long long sum= 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* sum_runner (void* args){
	
	int offset = *(int*)args;
	for (int i=0; i< NO_LOOPS ; i++){
	
		//Start of critical section
		pthread_mutex_lock(&mutex);
		sum += offset;
		pthread_mutex_unlock(&mutex);
		//End of critical section
	}
	
	//2. EXIT THREAD
	pthread_exit(0);

}

int main (int charc, char** argv){
	
	int offset1 = 3;
	int offset2 = -1;	
	//1. SPAWN THREADS
	pthread_t id1, id2;
	pthread_create(&id1, NULL, sum_runner, &offset1);
	pthread_create(&id2, NULL, sum_runner, &offset2);	
	
	//3. WAIT FOR THREAD TO JOIN
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);

	printf("sum =%lld\n", sum);

	return 0;
}
