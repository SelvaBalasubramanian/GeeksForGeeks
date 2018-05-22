//https://www.geeksforgeeks.org/reverse-a-linked-list/



#include<iostream>

using namespace std;

typedef struct node node;

struct  node{
	int data ; 
	node* next; 
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

void reverse(node **head){
	if(*head == NULL){
		cout<<"List is empty\n";
		return ;
	}
	else if((*head)->next == NULL)return;
	else{

		node *temp , *temp2 , *ptr; 
		temp = *head;
		temp2 = (*head)->next;
		ptr = temp2->next;
		if(ptr == NULL){
			temp2->next = temp;
			temp->next = NULL;
			*head = temp2;
		}
		else{
			for(; ptr->next != NULL ; ptr = ptr->next){
				temp2->next = temp;
				temp = temp2;
				temp2 = ptr;
			}
			(*head)->next = NULL;
			temp2->next = temp;
			ptr->next = temp2;
			*head = ptr;

		}
	}

}


void reverse2(node **head){

	if(*head == NULL)cout<<"List is empty\n";
	else{
		node *prev , *curr ,*next ;
		prev = NULL;
		curr = *head;
		next = NULL;
		while(curr != NULL){
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		*head = prev; 
	}

}

node* recursiveReverse(node *head){

	if(head->next == NULL){
		return head;
	}
	node *q;
	q = recursiveReverse(head->next);
	head->next->next = head;
	head->next = NULL;

	return q;

}

int main(){

	node *head ;
	head = NULL;
	head = insert(head , 5);
	head = insert(head , 6);
	head = insert(head , 7);
	head = insert(head , 8);
	head = insert(head , 9);
	print(head);
	reverse2(&head);
		print(head);
	head = recursiveReverse(head);
	print(head);


	return 0;
}