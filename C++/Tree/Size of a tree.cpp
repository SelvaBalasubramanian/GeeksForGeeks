#include<iostream>

using namespace std;

struct node
{
	int data; 
	node *left , *right;
	
};


node* newnode(int data){

	node *temp; 
	temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;

}

int sizeofTree(node *root){

	int size = 0;

	if(root == NULL){
		
		return size ;
	}
	else{
		size++;
		size += sizeofTree(root->left);
		size += sizeofTree(root->right);
	}
	return size;
}

int main(){

	node *root ;
	root = NULL;
	root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);

	// root->left->left = newnode(4);
	// root->left->right  = newnode(5);

	root->right->left = newnode(6);
	root->right->right = newnode(7);

	cout<<sizeofTree(root);
	return 0;
}