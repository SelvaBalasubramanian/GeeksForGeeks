// http://www.geeksforgeeks.org/get-level-of-a-node-in-a-binary-tree/


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


void inorderTraversal(node *root){
	if(root == NULL)return ;
	inorderTraversal(root->left);
	cout<<root->data<<" ";
	inorderTraversal(root->right);
}

int getLevelofNode(node *root , int level , int data){

	int k = 0 ;
	if(root == NULL)return 0;

	if(root->data == data){
		return level;
	}

	k = getLevelofNode(root->left , level+1,data);
	if(k == 0)
		k = getLevelofNode(root->right , level+1,data);

	return k;
}

int main(){

	node *root;
	root = newnode(5);
	root->left = newnode(6);
	root->right = newnode(1);
	root->left->left = newnode(2);
	root->left->right = newnode(4);

	inorderTraversal(root);
	cout<<endl;
	cout<<getLevelofNode(root , 1 , 5)<<endl;
	cout<<getLevelofNode(root , 1 , 6)<<endl;
	cout<<getLevelofNode(root , 1 , 1)<<endl;
	cout<<getLevelofNode(root , 1 , 2)<<endl;
	cout<<getLevelofNode(root , 1 , 4)<<endl;

	return 0;
}