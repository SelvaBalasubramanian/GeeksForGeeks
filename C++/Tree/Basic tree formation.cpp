#include<iostream>

using namespace std;

typedef struct node node;

struct node {
	int data ; 
	node *left  , *right ;
};

node* newnode(int data){
	node *a  = new node();
	a->data = data;
	a->left = NULL;
	a->right = NULL;

	return a;
}

void preorderTraversal(node *root){

	if(root == NULL)return ;
	cout<<root->data<<" ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void inorderTraversal(node *root){
	if(root == NULL)return;
	inorderTraversal(root->left);
	cout<<root->data<<" ";
	inorderTraversal(root->right);
}


void postorderTraversal(node *root){
	if(root == NULL)return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout<<root->data<<" ";
}


int main(){
	node *root ;
	root = newnode(5);
	// cout<<root->data;
	root->left = newnode(1);
	root->right = newnode(4);
	root->left->right = newnode(6);
	root->right->left =newnode(11);

	preorderTraversal(root);
	cout<<endl;
	inorderTraversal(root);
	cout<<endl;
	postorderTraversal(root);
	return 0;
}