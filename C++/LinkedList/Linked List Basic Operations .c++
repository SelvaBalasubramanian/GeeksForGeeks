// http://www.geeksforgeeks.org/linked-list-set-3-deleting-node/

#include<iostream>

using namespace std;

typedef struct node node;

struct node{
	int data;
	struct node *next;
}; 

void insertAtLast(node **head , int d){

	if(*head == NULL ){
		*head = new node();
		(*head)->data = d;
		(*head)->next = NULL;
		cout<<"inserted in head \n";
	}

	else{
		node* temp  = new node();
		temp->data = d;
		temp->next = NULL;
		node* ptr ;
			for(ptr = *head ;ptr->next != NULL ; ptr = ptr->next){;}
				ptr->next = temp;
	}
}


void insertAtFront(node **head , int d){

	if(*head == NULL){
		*head = new node();
		(*head)->data = d;
		(*head)->next = NULL;
	}
	else{
		node* temp = new node() ; 
		temp->data = d;
		temp->next = *head;
		*head = temp;
	}

}


void erase(node **head , int d){

	int flag = 0 ;
	node *ptr; 
	node *prev;

	for(ptr = *head ; ptr != NULL ; ptr = ptr->next){
		if(ptr->data ==  d){
			if(ptr == *head){
				*head = (*head)->next;
				break;
			}
			prev->next = ptr->next;
			ptr->next = NULL;
			break;
		}
		prev = ptr;
	}
	if(ptr == NULL){
		cout<<"Element not found \n";
	}

}



void eraseAt(node **head , int d){

	int flag = 0 ;
	node *ptr; 
	node *prev;
	int count = 0;

	for(ptr = *head ; ptr != NULL ; ptr = ptr->next){
		if(count ==  d){
			if(ptr == *head){
				*head = (*head)->next;
				break;
			}
			prev->next = ptr->next;
			ptr->next = NULL;
			break;
		}
		prev = ptr;
		count++;
	}
	if(ptr == NULL){
		cout<<"Element not found \n";
	}

}



void print(node *head){
	if(head == NULL)cout<<"No elements in list\n";
	else{
		for(node* ptr = head ; ptr != NULL ; ptr = ptr->next)cout<<ptr->data<<" ";
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

void swapNodes(node** head , int a , int b){ // swap nodes without using data;

	node *ptra ,*ptrb , *preva , *prevb , *tempa , *tempb;
	preva = NULL;
	prevb = NULL;
	ptra = *head;
	ptrb = *head;
	while(ptra && ptra->data != a){
		preva = ptra;
		ptra = ptra->next;
	}


	while(ptrb && ptrb->data != b){
		prevb = ptrb;
		ptrb = ptrb->next;
	}

	if(ptra == NULL || ptrb == NULL){
		cout<<"Element not present \n";
		return; 
	}

	if(preva != NULL)preva->next = ptrb;
	else (*head) = ptrb;

	if(prevb != NULL)prevb->next = ptra;
	else(*head) = ptra;

	tempa = ptra->next;
	ptra->next = ptrb->next;
	ptrb->next = tempa;
}



int main(){

	node *head ;
	head = NULL; 
	int n ;
	insertAtFront(&head ,  5 );
	insertAtFront(&head ,  4 );
	insertAtLast(&head ,  6 );
	print(head);
	// erase(&head , 4);
	print(head);
	insertAtLast(&head ,  77 );
	// erase(&head , 4);
	print(head);
	swapNodes(&head , 5 , 77);
		print(head);


	return 0;
}