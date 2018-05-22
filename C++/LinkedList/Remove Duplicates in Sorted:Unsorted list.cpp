#include<iostream>
#include<unordered_set>

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


void sortedListRemoveDuplicates(node *a){

	node *ptr , *n , *dup;
	ptr = a;
	while(ptr->next != NULL){

		if(ptr->data ==  ptr->next->data){
				dup = ptr->next;
				ptr->next = ptr->next->next;
				delete(dup);
		}
		else {
			ptr = ptr->next;
		}
	}


}

void RemoveDuplicates(node *a){

		node *ptr , *prev ;
		ptr =  NULL;
		prev = NULL;
		ptr  = a;
		unordered_set<int> s;


		for(; ptr != NULL ;){

			if(s.find(ptr->data) == s.end()){
				s.insert(ptr->data);
				prev = ptr;
				ptr = ptr->next;
			}
			else{
				prev->next = ptr->next;
				ptr->next = NULL;
				// delete(ptr);
				ptr = prev->next;
			}

		}


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
	RemoveDuplicates(head);
	print(head);




	return 0 ;
}






