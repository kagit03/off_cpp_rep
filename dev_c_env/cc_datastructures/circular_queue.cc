#include<iostream>
#include<cstdlib>

using namespace std;

#define MAX 5

class queue{

	private:
		int arr[MAX];
		int head,tail,que_full;
	public:
		queue(){
			head=0;
			tail=0;
			que_full=0;
			for(int i=0; i<MAX; i++){
				arr[i]=777;
			}
		}
		void addto(int data);
		int del();
		void display();
};

void queue::addto(int data){
	
	char next;
	if(que_full == 1){
		cout<<"Queue full"<<endl;
	}else{
		//detect if the queue will full again after this push
		if(tail+1 == head){
			que_full=1;
			cout<<"Head meets tail queue full"<<endl;
		}
		//add data to queue
		arr[tail]= data;
		tail++;
		//Queue is full as no elements popedout
		if((tail==MAX)&&(head==0)){
			que_full=1;
			tail = 0;
		}else if(tail==MAX){
			//tail reset for refill
			tail = 0;
			cout<<"Queue tail reset"<<endl;
		}
	}

}

int queue::del(){
	int val;
	if ((head==tail) && (que_full!=1)){
		cout<<"Queue is empty"<<endl;	
		cout<<endl<<"Head="<<head<<endl;
		cout<<"Tail="<<tail<<endl;
		return 0;
	}else{
		//delete data from queue
		val=arr[head];
		arr[head]=0;
		head++;
		que_full=0;
	}
	
	if (head == MAX){
		//reset when the queue limit reached
		head = 0;
		cout<<"Queue head reset"<<endl;
	}	
	return val;
}

void queue::display(){
	for (int i=0; i<MAX; i++){
		cout<<arr[i]<<endl;
	}
	cout<<"Head="<<head<<endl;
	cout<<"Tail="<<tail<<endl;
}

int main(){
	queue k;
	k.addto(25);k.addto(30);k.addto(35);k.addto(40);k.addto(45);
	//test queue full
	//k.addto(50);
	//k.del();k.del();
	//test circular buffer
	//k.addto(50);
	//k.addto(55);
	
	
	
	//k.del();k.del();
	k.display();

	return 0;
}
