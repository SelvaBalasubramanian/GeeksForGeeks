// https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/

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

void print(node *head){
	if(head == NULL)cout<<"No elements in list\n";
	else{
		for(node* ptr = head ; ptr != NULL ; ptr = ptr->next)cout<<ptr->data<<" ";
	}
	cout<<endl;
}

long int getNum(node *head){

	long int n = 0;
	long int tens = 1;

	for(; head != NULL ; head = head->next){
		n +=  (tens * head->data);
		tens *= 10;
	}
	cout<<n<<endl;
	return n;

}

void setNum(node **head , long int val){

	node **ptr;
	ptr = head;

	while(val){
		node *temp;
		temp = new node();
		temp->data = val%10;
		temp->next = NULL;
		val /= 10;
		*ptr = temp;
		 ptr = &((*ptr)->next);
	}

}


int main(){

	node *l1 , *l2 , *sum;
	l1 = NULL;
	l2 = NULL;
	sum = NULL;

	insertAtLast(&l1 , 1);
	insertAtLast(&l1 , 0);
	insertAtLast(&l1 , 0);
	insertAtLast(&l1 , 0);
	insertAtLast(&l1 , 0);


	insertAtLast(&l2 , 8);
	insertAtLast(&l2 , 4);
	// insertAtLast(&l2 , 0);
	// insertAtLast(&l2 , 0);
	// insertAtLast(&l2 , 2);

	long int n = getNum(l1);
	long int m = getNum(l2);

	long int s = n+m;

	cout<<s<<endl;


	setNum(&sum ,s );
	print(sum);


	return 0;
}









