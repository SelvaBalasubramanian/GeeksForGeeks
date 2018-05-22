#include<iostream>

using namespace std;

typedef struct node node;
struct node{

	int data;
	node  *next;
};


node* insert(node* head , int d){	

	if(head == NULL){
		head = new node();
		head->data  = d;
		head->next = NULL;
	}
	else{
		node* ptr , *temp;
		for(ptr = head ; ptr->next != NULL ; ptr = ptr->next){;}
		temp = new node();
		temp->data = d;
		temp->next = NULL;
		ptr->next = temp;
	}
	return head;
}


void print(node *head){

	node *ptr;
	if(head == NULL)cout<<"No elements present";
	for(ptr = head ; ptr != NULL ; ptr = ptr->next)cout<<ptr->data<<" ";
	cout<<endl;

}

void detectloop(node *head){

	node *slow_iterator;
	node *fast_iterator;
	slow_iterator = head;
	fast_iterator = head; 

	while(slow_iterator && fast_iterator && fast_iterator->next){
		slow_iterator = slow_iterator->next;
		fast_iterator = fast_iterator->next->next;
		if(slow_iterator == fast_iterator){
			cout<<"Loop Detected\n";
			return;
		}

	}
	cout<<"No Loop\n";

}


int main(){

	node *head;
	head = NULL;
	head = insert(head , 5);
	head = insert(head , 6);
	head = insert(head , 7);
	head = insert(head , 8);


	head->next->next->next = head;

	detectloop(head);

	return 0;
}