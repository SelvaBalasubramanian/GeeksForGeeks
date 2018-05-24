// https://www.geeksforgeeks.org/union-and-intersection-of-two-linked-lists/

#include<iostream>

using namespace std;


typedef struct node node;

struct node{
	int data;
	struct node *next;
};


void insert(node **head , int data){

	node *ptr ;
	ptr = *head;
	node *temp;
	temp  = new node();
	temp->data = data;
	temp->next = NULL;

	if(*head == NULL){
		*head  = temp;
	}
	else{
		for(ptr = *head; ptr->next != NULL ; ptr = ptr->next){;}
		ptr->next = temp;
	}
}


void print(node *head){

	while(head != NULL){
		cout<<head->data<<" ";head = head->next;
	}
	cout<<endl;
}
int  search(node *head , int d){

	node *ptr;
	int count = 0 ;
	for(ptr = head ; ptr != NULL ; ptr = ptr->next , count++){
		if(ptr->data == d){
			return 1;		
		}
	}
	return 0;
}

node* union1(node *a , node *b){

	node *res;
	res = NULL;
	node *ptr , *temp;
	int count = 0;
	while(a != NULL){
		insert(&res , a->data);
		a = a->next;
	}

	while(b != NULL){
		if(!search(res , b->data)){
			insert(&res , b->data);
			b = b->next;
		}
		else{
			b  = b->next;
		}

	}

	return res;
}




node* intersection(node *a ,node *b){

	node *ptr , **temp , *t;
	ptr = NULL;
	temp = &ptr;
	for(;a != NULL;){

		if(search(b, a->data)){
			t = new node();
			t->next = NULL;
			t->data = a->data;
			*temp = t;
			temp = &((*temp)->next);
		}
		a = a->next;
		
	}
	return ptr;

}



int main(){
	node *a , *b , *res;
	a= NULL;
	b= NULL;
	insert(&a, 5);
	insert(&a, 2);
	insert(&a, 3);
	insert(&a, 6);
	insert(&a, 1);


	insert(&b, 6);
	insert(&b, 7);
	insert(&b, 8);
	insert(&b, 9);
	insert(&b, 1);
	insert(&b, 44);
	insert(&b, 55);
	insert(&b, 96);

	//use either intersection or union one at a time
	
//UNION

	res  = union1(a , b);  
	print(res);
	
//INTERSECTION
	
	// res = intersection(a , b);
	// print(res);

	return 0;
}