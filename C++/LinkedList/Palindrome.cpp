#include<iostream>

using namespace std;



//using recursion



typedef struct node node;

struct node{
	int data;
	struct node *next;
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


node* reverse(node *a){

	node *curr ;
	curr = a;
	node *next ;
	node *prev ;
	prev = NULL;
	next = NULL;

	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}


void print(node *head){

	node *ptr;
	if(head == NULL)cout<<"No elements present";
	for(ptr = head ; ptr != NULL ; ptr = ptr->next)cout<<ptr->data<<" ";
	cout<<endl;

}



int main(){

	node *head ; 
	head = NULL;

	head = insert(head , 1);
	head = insert(head , 2);
	head = insert(head , 3);
	head = insert(head , 4);
	head = insert(head , 3);
	head = insert(head , 2);
	head = insert(head , 1);

	node *second;
	second = NULL;
	node *temp ;
	temp = NULL;
	node *temp2 ;
	temp2 = NULL;
	node *middle_node;
	middle_node = NULL;
	int n = 7;
	int mid = 7/2;

	for(temp = head ; mid >1 ; mid-- ,temp = temp->next){;}

	
	second = temp->next;
	temp->next = NULL;
	temp = head;

	if(n %2 != 0){
		middle_node = second;
		second = second->next;
	}
	second = reverse(second);
		temp2 = second;
		int i ;
	for( i = 0 ; i< mid ; i++){
		if(temp->data != temp2->data){
			cout<<"Not a palindrome\n";
			break;
		}
		temp2 = temp2->next;
		temp = temp->next;

	}	
	if(i == mid)cout<<"is a paindrome\n";

	print(head);
	print(second);
	return 0;
}