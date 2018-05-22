#include<iostream>


using namespace std;

typedef struct node node;
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


node* mergeSortedList(node *a ,node *b){
	node *result ;
	node *ptr , *temp;
	result = NULL;
	temp = NULL;
	ptr = NULL;

	while(a != NULL || b != NULL){
		if(a == NULL){
			insertAtLast(&result , b->data);
			b = b->next;
		}
		else if( b == NULL){
			insertAtLast(&result , a->data);
			a = a->next;
		}
		else if( a->data < b->data)
		{
			insertAtLast(&result , a->data);
			a = a->next;
		}
		else
		{
			insertAtLast(&result , b->data);
			b = b->next;
		}

	}

	return result;

}


//using recursion 

// node* merge(node *a , node *b){

// 	node *result = NULL;
// 	if(a == NULL){
// 		return b;
// 	}
// 	else if(b == NULL){
// 		return a ;
// 	}

// 	print(a);
// 	print(b);
// 	cout<<"----"<<endl;
// 	if(a->data <=  b->data){
// 		result = a;
// 		result->next = merge(a->next , b);
// 	}
// 	else{
// 		result = b;
// 		result->next = merge(a , b->next);
// 	}

// 	return (result);
// }

//using local refrence ;
void move(node **dest , node **source){

	node *newnode  = *source;
	if(newnode == NULL)return;

	*source = (*source)->next;

	newnode->next = NULL;
	*dest = newnode;
}



node* merge2(node *a , node *b){

	node *result;
	result = NULL;

	node **ref ;
	ref = &result;

	while(1){

		if( a == NULL){
			*ref = b;
			break; 
		}
		else if(b == NULL){
			*ref = a;
			break;
		}

		if(a->data >=  b->data){
			move(ref , &b);
		}
		else{
			move(ref , &a);
		}

		ref  = &((*ref)->next);
	}//while

	return result;
}



int main(){

	node *a, *b , *result; 
	result = NULL;
	a = NULL;
	b= NULL;
	a = insert(a,1);
	a = insert(a,3);
	a = insert(a,5);
	a = insert(a,7);
	a = insert(a,9);

	b = insert(b,2);
	b = insert(b,4);
	b = insert(b,5);
	b = insert(b,6);
	b = insert(b,8);
	result = merge2(a , b);
	// result = a;
	print(a);
	print(b);
	print(result);

	return 0;
}