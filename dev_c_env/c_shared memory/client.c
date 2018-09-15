
//command to list shm #ipcs
//command to delete shm #ipcrm -M key

#include<string.h>
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
	data client_struct;
	data* client_data_ptr;
	data* shm_client_addr;
	char* i;
	client_data_ptr =&client_struct;
	
	key = 555;

        //create shared memory
        schmid = shmget(key,SMSIZE, 0666);
	if (schmid < 0){
		perror ("schmget error");
		exit (-1);
	}
	//attach calling process to shared memory
	//addr = shmat (schmid, NULL,0);
	shm_client_addr = (data*) shmat (schmid, NULL,0);
	
	if (shm_client_addr == (data*)-1){
		perror("shmat error\n");
	}
	//memcpy(desitnation_ptr, source_ptr; sizeof(strcut));
	//memcpy(client_data_ptr,shm_client_addr, sizeof(client_struct));
	//memcpy not need as we get the pointer to the shm
	printf("%d\n",  shm_client_addr->age);
	printf("%d\n",  shm_client_addr->height);
	printf("%s\n",  shm_client_addr->name);
	
	
	/*==================================
	if (addr == (char*) -1)
	{
		perror("shmat error");
	}
	//read data into shared-memory
	for(i=addr; *i != 0; i++){
		printf("%c",*i);
	}
	
	printf("\n");
	
	//clear memory by writing # at first location
	*addr = '*';
	=======================================*/ 

        return 0;
}
