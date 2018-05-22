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

node* reverse(node *head , int kk){
	int k = kk;
	node *prev ,*curr ,*next ;
	prev = NULL;
	next = NULL;
	curr = head;

	while(curr != NULL && k > 0){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		k--;
	}
	if(curr != NULL)
		head->next = reverse(curr , kk);
	
	return prev; 

}


int main(){

	node *head;
	node *a , *b;

	a = NULL;
	b = NULL;

	head = NULL;

	insert(&head , 5);
	insert(&head , 3);
	insert(&head , 4);
	insert(&head , 5);
	insert(&head , 88);
	insert(&head , 11);
	insert(&head , 22);
	insert(&head , 33);
	insert(&head , 44);
	insert(&head , 77);

	print(head);
	head = reverse(head , 3);
	print(head);

	return 0;
}



