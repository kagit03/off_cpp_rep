#include<iostream>
#include<cstdlib>

using namespace std;

#define MAX 5

class queue{

	private:
		int arr[MAX];
		int head,tail;
	public:
		queue(){
			head=0;
			tail=0;
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
	if(tail==MAX){
		cout<<"Queue full"<<endl;
		exit(1);
	}else{
		//add data to queue
		arr[tail]= data;
		tail++;
	}	
}

int queue::del(){
	int val;
	if (head==tail){
		cout<<"Queue is empty"<<endl;	
		cout<<endl<<"Head="<<head<<endl;
		cout<<"Tail="<<tail<<endl;
		return 0;
	}else{
		//delete data from queue
		val=arr[head];
		arr[head]=0;
		head++;
	}
	
	if (head == MAX){
		//reset when the queue is cleared
		head = 0;
		tail = 0;
		cout<<"Queue reset"<<endl;
	}
	return val;
}

void queue::display(){
	for (int i=0; i<MAX; i++){
		cout<<arr[i]<<endl;
	}
	cout<<endl<<"Head="<<head<<endl;
	cout<<"Tail="<<tail<<endl;
}

int main(){
	queue k;
	k.addto(5);k.addto(10);k.addto(20);
	k.del();k.del();k.del();k.del();
	k.addto(25);k.addto(30);
	k.del();k.del();
	k.display();

	return 0;
}
