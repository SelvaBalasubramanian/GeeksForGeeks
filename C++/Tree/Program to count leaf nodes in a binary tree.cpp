// http://www.geeksforgeeks.org/write-a-c-program-to-get-count-of-leaf-nodes-in-a-binary-tree/

#include<iostream>
using namespace std;

 typedef struct node node;
 struct node{
 	int data;
 	node *left,*right;

 };

 node* newnode(int data){
 	node *temp;
 	temp = new node();
 	temp->data = data;
 	temp->left = NULL;
 	temp->right = NULL;
 	return temp;
 }

 int leafCount(node *root){

 	int count = 0;
 	if(root == NULL){
 		return 0;
 	}
 	if(root->left == 0 && root->right == 0){
 		return 1;
 	}

 	else{
 		count += leafCount(root->left);
 		count += leafCount(root->right);
 	}
 	return count;
 }

 int main(){

 	node *root ;
 	root = newnode(5);
 	root->left = newnode(1);
	root->right = newnode(4);
	root->left->left = newnode(9);
	root->left->right = newnode(6);
	root->right->left =newnode(11);
	cout<<leafCount(root);

 	return 0;
 }