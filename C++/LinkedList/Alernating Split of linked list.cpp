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

//using recursion
void AlernatingSplit(node *head , node **a , node **b){

	static int count = 0;
	if(head == NULL)return;

	if(count % 2 == 0){
		*a = head;
		head = head->next;
				(*a)->next = NULL;
				count++;
		AlernatingSplit(head ,&(*a)->next , b);
	}
	else{
		*b = head;
		head = head->next;
		(*b)->next = NULL;
		count++;
		AlernatingSplit(head , a , &(*b)->next);  
	}
	return ;
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
	print(head);
	AlernatingSplit(head , &a  , &b);
	print(a);
	print(b);
	return 0;
}




