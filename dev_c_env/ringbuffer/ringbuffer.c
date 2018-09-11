#include<stdio.h>

int circ_buf[5];
static int head=0;
static int tail=0;
static int buf_empty=1;
int len= 5;

int circ_buf_pus(int val){
	int next;
	

	//Check if head and tail are at same position
	if((head == tail) && (buf_empty != 1)){
		printf("Pop out element to push new ones\n");
		return -1;
	}
	//Buffer is not empty
	if ( buf_empty != 0){
		//Buffer is not empty
		buf_empty = 0;
	}
	//Move the pointer to next location
	next = head +1; 
	// Check if the pointer has crossed the buffer size
	if(next >= len){
		//Reset Pointer to START
		next=0;
	}

	// Assign values pushed in
	circ_buf[head]=val;
	//latest the head location
	head = next;
	return 0;
}

int circ_buf_pop(){
	int next;
	int temp;
	
        //Buffer is empty
	if ( buf_empty != 0){
		printf("Buffer empty:cannot pop\n");
		return -1;
	}
	
	//Move the header to next element
	next = tail+1;	
    	// Check if the pointer has crossed the buffer size
	if(next >= len){
		//Reset Pointer to START
		next=0;
	}
	
	//assign the poped out value
	temp = circ_buf[tail];
	//latest tail location
	tail = next;
	
	if ((tail == head) && (buf_empty != 1)){
		printf("Buffer empty:push before next pop\n");
		//buffer is again empty
		buf_empty = 1;
	}
	return 	temp;
}

int main (){
	int i=0,j= 0,k=0, ret_val=0;
	for(i=0; i<=2; i++)
	{
		ret_val = circ_buf_pus(i+5);
	}

	printf("\n\n");
	
	for(i=0; i<=2; i++)
	{
		ret_val = circ_buf_pop();
	}

	for(j=0; j<len; j++){
		printf("%d\t",circ_buf[j]);
	}
	printf("\nHead=%d Tail=%d\n",head, tail);

	return 0;
}
