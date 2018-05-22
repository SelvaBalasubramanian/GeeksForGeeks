

#include<iostream>
#include<unordered_set>

using namespace std;

typedef struct node node;

struct node{
	int data;
	struct node *next;
}; 




void checkIntersection(node *a   , node *b ){

	unordered_set<node *>m;

	while(a!= NULL){
		m.insert(a);
		a = a->next;
	}

	while(b != NULL){
		if(m.find(b) != m.end()){
			cout<<"intersection found\n";
			return;
			}
		b= b->next;
	}

	cout<<"NO intersection\n";

}


int main(){

	node *a , *b;
	a = NULL;
	b = NULL;
	node *temp;

	a = new node();
	a->data = 5;
	a->next = new node();
	a->next->data = 4;
	a->next->next = new node();
	a->next->next->data = 6;

	b = new node();
	b->data = 1;
	b->next= new node();
	b->next->data = 2;

	temp = new node();
	temp->data = 11;
	temp->next = NULL;

	a->next->next->next = temp;
	// b->next->next  = temp;     //add to have intersection

	checkIntersection(a , b);

	return 0;
}