#include<iostream>
using namespace std;

class linkedlist{
	protected:
	struct node{
		int num;
		node *link;
	}*p;
	public:
		linkedlist(){
			p=NULL;
		}
		~linkedlist(){
			node *m;
			while (p != NULL){
				m = p;
				p= p->link;
				delete m;
			}
		}
		void add(int num);
		void addatbeg(int num);
		int count();
		void display();
};

void linkedlist::add(int num){
	node *q,*t;
	
	if(p==NULL){
		p=new node;
		p->num=num;
		p->link=NULL;
	}else{
		q=p;
		while(q->link !=NULL){
			q=q->link;
		}
		t = new node;
		t->num=num;
		t->link=NULL;
		q->link=t;
	}	
}

void linkedlist::addatbeg(int num){
	node *k;
	if (p==NULL){
		p=new node;
		p->num = num;
		p->link=NULL;
	}else{
		k=new node;
		k->num=num;
		k->link=p;
		p=k;
	}
}
void linkedlist::display(){
	node *q;
	q=p;
	while(q!=NULL){
		cout<<q->num<<endl;
		q=q->link;

	}
}

int linkedlist::count(){
	int c;
	node *r;
	r=p;
	while(r!=NULL){
		r=r->link;
		c++;
	}
	return c;
}

/*=======================================*/
class linkedlistext : public linkedlist{
	public:
	int addat(int post, int num);
};

int linkedlistext::addat(int post, int num){
	int cnt;
	cnt=linkedlist::count();
	if(cnt == post){
		linkedlist::add(num);	
	}else if (cnt < post){
		cout<<"The requested position beyond reach"<<endl;
		return 0;
	}else{
		node *s,*t;
		t=p;
		for(int i=0;i<post;i++){
			t=t->link;
		}
		s=new node;
		s->num=num;
		s->link=t->link;
		t->link=s;		
	}
}

int main(){
	linkedlistext a;
	int cnt;
	a.add(10);
	a.add(15);
	a.add(25);
	
	a.addat(2,20);
	a.addatbeg(5);
	a.display();
	cnt=a.count();
	cout<<endl<<cnt<<endl;
	return 0;
}
