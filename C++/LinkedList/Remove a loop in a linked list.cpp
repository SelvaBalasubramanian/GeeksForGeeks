// http://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/


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

void detectRemoveLoop(node *head){
	if(head == NULL || head->next == NULL)return;

	node *slow , *fast ;
	slow = head;
	fast = head;
	int flag = 1;
	while(slow && fast && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			cout<<"Loop detected\n";
			flag = 0;
			break;
		}
	}
	if(flag){
		return;
	}

	node *loopNode;
	loopNode = slow ;

	slow = head;
	while(slow->next != fast->next){
		slow = slow->next;
		fast = fast->next;
	}
	fast->next = NULL;
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
	head->next->next->next->next->next->next->next->next->next->next = head->next->next->next;
	detectRemoveLoop(head);
	print(head);

	return 0;
}


