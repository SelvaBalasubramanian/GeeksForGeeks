// http://www.geeksforgeeks.org/print-ancestors-of-a-given-node-in-binary-tree/


#include<iostream>


using namespace std;

typedef struct node node;

struct node{
	int data; 
	node *left ,*right;
};
	
node* newnode(int data){

	node *temp;
	temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}


void printAncestors(node *root , int data){

	if(root == NULL) return;

	static int found = 0;
	
	if(root->data == data){
		found = 1;
		return;
	}

	if(!found)printAncestors(root->left ,data);
	if(!found)printAncestors(root->right , data);
	if(found)cout<<root->data<<" ";

}


int main(){


	node *root;
	root  = newnode(5);
	root->left = newnode(1);
	root->right = newnode(2);
	root->left->left = newnode(4);
	root->right->left = newnode(6);
	root->left->right = newnode(8);
	root->right->right = newnode(9);
	printAncestors(root , 8);

	return 0;
}




