#include<string.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>

#define SMSIZE 100

typedef struct mystruct{
	char name[20];
	int height;
	int age;

}data;
int main(){

        int schmid;
        key_t key;
        char* addr;
	data* stct_ptr;
	data* shm_addr;
	char* m;

	key = 555;

        //create shared memory
        schmid = shmget(key,SMSIZE,IPC_CREAT | 0666);

	if (schmid < 0){
		perror ("schmget error");
		exit (-1);
	}

	//attach calling process to shared memory
	//addr = (char*) shmat (schmid, NULL,0);
	shm_addr = (data*) shmat (schmid, NULL,0);
	
	if(shm_addr == (data*) -1){
		perror("shmat error");
	}
	
	//memcpy(shm_addr, stct_ptr, sizeof(local_struct));
	shm_addr->age=32;
	shm_addr->height=180;
	//Use strncpy to assign string to a char array[]
	strncpy(shm_addr->name, "Mangal", 20);
	/*printf("enter name\n");
	scanf("%s\n", shm_addr->name);
	printf("entered name\n");*/
	
	/*============================
	if (addr == (char*) -1)
	{
		perror("shmat error");
	}
	//write data into shared-memory
	memcpy(addr, "Hello World", 11);
        m = addr;
	m += 11;
        //*m = 0;
	
	while (*addr != '*'){
		sleep(1);
	}
	================================*/

        return 0;
}

