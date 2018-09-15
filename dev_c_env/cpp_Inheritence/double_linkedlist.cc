#include<iostream>

using namespace std;

class doublell{
	public:
		struct node {
			int num;
			node *flink;
			node *blink;
		}*head;
	//public:
		//constructor
		doublell(){
			head=NULL;
		}
		//destructor
		~doublell(){
			node *t;
			while(head!=NULL){
				t=head;
				head=head->flink;
				delete t;
			}
		}
		//member functions
		void add (int num);
		void* disp_front();
		void disp_reverse();
};

void doublell::add(int num){
	node *q,*t,*r;
	
	if(head==NULL){
		head=new node;
		head->num=num;
		head->flink=NULL;
		head->blink=NULL;
	}else{
		q=head;
		while(q != NULL){
			r=q;
			q=q->flink;
		}

		t=new node;
		t->num=num;
		t->flink=NULL;
		if(head->flink==NULL){
			t->blink=head;//only one node in list
		}else{
			t->blink=r;
		}
		r->flink=t;
	}
}

void* doublell::disp_front(){
	node *ptr=head;
	node *t;
	while(ptr != NULL){
		t=ptr;
		cout<<ptr->num<<endl;
		ptr=ptr->flink;
	}
	return t;
}

void doublell::disp_reverse(){
	node *tail;
	tail=(node*)disp_front();
	while (tail !=NULL){
		cout<<tail->num<<endl;	
		tail=tail->blink;
	}
}

int main (){
	
	doublell a;
	a.add(10);
	a.add(20);
	a.add(30);
	a.disp_front();
	a.disp_reverse();
	return 0;
}
