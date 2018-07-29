#include<iostream>

using namespace std;


struct node
{
	int data;
	struct node *next;
	
};


void insert(node **head , int data){
	node *ptr , *newnode;
	ptr = *head;
	newnode = new node();
	newnode->data = data;
	newnode->next = NULL;

	if(ptr == NULL){
		*head = newnode;
	}
	else{
		for(;ptr->next != NULL; ptr = ptr->next){;}
		ptr->next = newnode;
	}
}

void print(node *head){
	for(; head != NULL; head = head->next)printf("%d => ",head->data);
}


int getCarry(node *head){

	if(head == NULL)return  1;

	int result = head->data + getCarry(head->next);
	head->data = result % 10;
	return result / 10;
}

void AddNumber(node **head , int no){

	int carry = getCarry(*head);

	if(carry!= 0){
		node *n = new node();
		n->data = carry;
		n->next = *head;
		*head = n;
	}

}

int main(){
	node *head ;
	head = NULL;
	insert(&head , 9);
	insert(&head , 9);
	insert(&head , 9);
	insert(&head , 9);
	insert(&head , 9);
	insert(&head , 9);
 	AddNumber(&head , 3);
	print(head);
	return 0;
}

