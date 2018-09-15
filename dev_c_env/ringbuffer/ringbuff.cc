
/* compiling command: g++ -std=c++11 -o ringcc ringbuff.cc*/
#include<iostream>
using namespace std;
class ring_buf
{
	private:
	int circ_buf[5];
	int head=0;
	int tail=0;
	int buf_empty=1;
	int len= 5;

	public:
	ring_buf(){}//Constructor
	//Destructor
	~ring_buf(){
	 
		cout << "The head is! =" << head << endl;
		cout << "The tail is! =" << tail << endl;
		for(int i=0; i<len; i++){
			cout << circ_buf[i] << endl;
		}	
	}
	

	//Function for pushing in data
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
	
	//Function for popping out data	
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
};


int main (){

	ring_buf data_str;
	data_str.circ_buf_pus(5);
	data_str.circ_buf_pus(10);
	data_str.circ_buf_pus(15);
	data_str.circ_buf_pus(20);
	data_str.circ_buf_pus(25);
	data_str.circ_buf_pop();
	data_str.circ_buf_pop();
	data_str.circ_buf_pop();
	data_str.circ_buf_pus(30);
	data_str.circ_buf_pus(35);
	data_str.circ_buf_pus(40);

	return 0;
}
