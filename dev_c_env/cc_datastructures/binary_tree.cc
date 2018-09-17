#include<iostream>

#define TRUE  1
#define FALSE 0

using namespace std;

class btree{
	private:
	struct node{
		int data;
		node *left;
		node *right;
	}*p;
	public:
		btree(){//constructor
			p=NULL;
		}
		void insert (int data);
		void search (int n,int &found, node* &parent);
		void traverse();
};

void btree::search(int n,int &found, node* &parent){
	node *q;
	found = FALSE;
	parent= NULL;
	
	if (p == NULL){
		return;
	}
	q=p;
	while(p!=NULL){
		if(q->data == n){
			found=TRUE;
			return;
		}
		if(p->data >n){
			parent = q;
			q=q->left;
		}else{
			parent = q;
			q=q->right;
		}
	}
	
}

void btree::insert(int num){
	int found;
	node*t, *parent;
	
	search(num, found, parent);
	
	if(found == TRUE){
		cout<<"Node already found"<<endl;
	}else{
		t=new node;
		t->data=num;
		t->left=NULL;
		t->right=NULL;
	}
	
	if (parent == NULL){
		p=t;
	}else{
		(parent->data>num?parent->right=t:parent->left=t);
	}
}

int main (){

	return 0;
}
