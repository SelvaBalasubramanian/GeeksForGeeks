// https://www.geeksforgeeks.org/check-whether-binary-tree-full-binary-tree-not/

#include<iostream>

using namespace std;



struct node {	
	int data;
	node *left , *right ;	
};

node* newnode(int data){
	node *temp ;
	temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void print(node *root){

	if(root == NULL)return ;
	else{
		cout<<root->data<<" ";
		print(root->left);
		print(root->right);
	}
}

bool isfullBinaryTree(node *root){

	if(root == NULL){
		return true;
	}

	if(root->left  == NULL && root->right == NULL){
		return true;
	}
	else if(root->left && root->right){
		return(isfullBinaryTree(root->left) && isfullBinaryTree(root->right));
	}

	return false;
}


int main(){

	node *root;
	root = newnode(5);
	root->left = newnode(6);
	root->right = newnode(7);
	root->left->right = newnode(1);
	root->left->left = newnode(2);
	root->right->left = newnode(8);
	root->right->right= newnode(9);
	print(root);
	cout<<endl;

	if(isfullBinaryTree(root)){
		cout<<"YES\n";
	}
	else cout<<"NO\n";

	return 0;
}