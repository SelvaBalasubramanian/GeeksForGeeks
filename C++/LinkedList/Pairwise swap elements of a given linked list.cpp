
// https://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list/


#include<iostream>

using namespace std;


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

 void pairwiseSwapNode(node *head){

 	if(head->next == NULL){
 		return ;
 	}

 	int temp = head->data;
 	head->data = head->next->data;
 	head->next->data  = temp;

 	pairwiseSwapNode(head->next->next);

 	return;
 }



int main(){

	node *head;
	head = NULL;

	head = insert(head , 1);
	head = insert(head , 2);
	head = insert(head , 2);
	head = insert(head , 4);
	head = insert(head , 5);

	print(head);
	pairwiseSwapNode(head);
	print(head);




	return 0 ;
}



