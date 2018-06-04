// https://www.geeksforgeeks.org/print-left-view-binary-tree/


#include<iostream>

using namespace std;

typedef struct node node;

struct node{
	int data;
	node *left , *right;

};


node* newnode(int data){

	node *temp ;
	temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;

}

void inorderTraversal(node *root){
	if(root == NULL)return ;
	inorderTraversal(root->left);
	cout<<root->data<<" ";
	inorderTraversal(root->right);
}


void printLeftView(node *root , int level  , int* maxLevel){

	if(root == NULL)return;

	if(*maxLevel < level){
		cout<<root->data<<" ";
		*maxLevel = level;
	}

	printLeftView(root->left, level+1 , maxLevel);
	printLeftView(root->left, level+1 , maxLevel);

}



int main(){

	node *root; 
	root = NULL;
	root = newnode(5);
	root->left = newnode(6);
	root->right = newnode(7);
	root->left->right = newnode(4);
	root->left->left = newnode(1);

	inorderTraversal(root);
	cout<<endl;
	int maxLevel = 0;
	printLeftView(root , 1 , &maxLevel);


	return 0;
}