// https://www.geeksforgeeks.org/merge-a-linked-list-into-another-linked-list-at-alternate-positions/


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

void MergeAlternate(node *a , node *b){

	node *ptr , *temp;
	int count = 0;
	while(a != NULL || b != NULL){
		if(count%2 == 0){
			if(a->next == NULL){
				a->next = b;
				break;
			}
			if(b == NULL){
				break;
			}
			temp = a->next;
			a->next = b;
			b = b->next;
			a->next->next = temp;
			a =a->next;

		}
		else{
			a = a->next;
		}
		count++;
	}

}



int main(){
	node *a , *b , *res;
	a= NULL;
	b= NULL;
	insert(&a, 5);
	insert(&a, 2);
	insert(&a, 3);
	insert(&a, 6);
	insert(&a, 1);


	insert(&b, 6);
	insert(&b, 7);
	insert(&b, 8);
	insert(&b, 9);
	insert(&b, 1);
	insert(&b, 44);
	insert(&b, 55);
	insert(&b, 96);


	MergeAlternate(a , b);  
	print(a);
	


	return 0;
}