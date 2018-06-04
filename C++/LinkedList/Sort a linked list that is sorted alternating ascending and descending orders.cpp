// http://www.geeksforgeeks.org/how-to-sort-a-linked-list-that-is-sorted-alternating-ascending-and-descending-orders/	


#include<iostream>

using namespace std;


typedef struct node node;

struct node{
	int data;
	node *next;
};

void insert(node **head, int data){

	node *ptr ;
	ptr = *head;

	if(ptr == NULL){
		*head = new node();
		(*head)->next = NULL;
		(*head)->data = data;
	}
	else{

		for(; ptr->next!= NULL; ptr = ptr->next){;}
		ptr->next = new node();
		ptr->next->data = data;
		ptr->next->next = NULL;	
	}

}


void print(node *head){
	for(; head != NULL ; head = head->next){
		cout<<head->data<<" ";
	}
	cout<<endl;
}


node* reverse(node *head){

	node *curr , *next , *prev;
	prev = NULL;
	curr = head;
	while(curr){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;

}

void merge(node *head , node *head2){
	node *ptr  = head;
	node *list;
	list = NULL;
	while(ptr != NULL || head2 != NULL){
		if(ptr == NULL){
			insert(&list , head2->data);
			head2 = head2->next;
		}
		else if(head2 == NULL){
			insert(&list , ptr->data);
			ptr = ptr->next;
		}
		else if(ptr->data <= head2->data){
			insert(&list, ptr->data);
			ptr = ptr->next;
		}
		else{
			insert(&list, head2->data);
			head2 = head2->next;
		}
	}
	print(list);
}



int main(){

	node *head;
	head = NULL;
	insert(&head , 10);
	insert(&head , 40);
	insert(&head , 53);
	insert(&head , 30);
	insert(&head , 67);	
	insert(&head , 12);
	insert(&head , 89);
	insert(&head , 5);	
	

	print(head);
	node *ptr , *head2;
	ptr = head;
	node *list; 
	list = ptr->next;
	head2 = list;

	if(ptr->next != NULL){ 
		ptr->next = ptr->next->next;
		ptr = ptr->next;
	}

	while(ptr && ptr->next != NULL){
		list->next = ptr->next;
		list = list->next;
		ptr->next = ptr->next->next;
		ptr = ptr->next;
	}

	head2 = reverse(head2);
	merge(head , head2);

	return 0;






}