#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
};

void addtobeg(struct node **q, int num){

	struct node *temp, *r;
	temp = *q;
	
	if (temp != NULL){
		r = malloc(sizeof(struct node));
		r->data = num;
		r->link=*q;
		*q=r;
		
	}else{
		r = malloc(sizeof(struct node));
		r->data = num;
		r->link=*q;
		*q=r;
	}
}

int count (struct node*q){
	struct node *temp;
	int c;
	temp=q;
	
	while (temp != NULL){
		temp=temp->link;		
		c++;
	}
	return c;	
}

void append (struct node **q, int num){
	
	struct node* temp, *r, *foot;
	temp = *q;
	
	//empty linked list
	if (temp == NULL){
		temp = malloc(sizeof(struct node));
		temp->data=num;
		temp->link=NULL;
		*q=temp;
	}else{
		//temp = *q;
		while (temp->link != NULL){
			temp = temp->link;
		}
		r = malloc(sizeof(struct node));
		r->data = num;
		r->link=NULL;
		temp->link=r;
	}
}

int main() {

	struct node *nxt_ptr, *header, *footer;
	header=NULL;
	append(&header,50);
	append(&header,60);
	append(&header,70);
	append(&header,80);
	append(&header,90);
	addtobeg(&header,40);
	nxt_ptr = header;
	
	while(nxt_ptr != NULL){
		printf("%d\n", nxt_ptr->data);
		nxt_ptr = nxt_ptr->link;
	}
	
	printf("Length of linkedlist=%d\n", count(header));

	return 0;
}
