#include <iostream>
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


void rearrange(struct node **head){

	struct node *odd, *even, *even_first ;

	odd = *head;
	even = odd->next;
	even_first = even;

	while(1){
		if(!odd || !even || !(even->next)){
			break;
		}
		odd->next = even->next;
		odd = odd->next;

		even->next = odd->next;
		even = even->next;
	}
	odd->next = even_first;
}


int main(){
   
	node *head ;
	head = NULL;
	insert(&head , 1);
	insert(&head , 2);
	insert(&head , 3);
	insert(&head , 4);
	insert(&head , 5);
	insert(&head , 6);
	insert(&head , 7);

	rearrange(&head);
	print(head);

	return 0;
}