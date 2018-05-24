// http://www.geeksforgeeks.org/write-a-c-program-to-get-count-of-leaf-nodes-in-a-binary-tree/



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

void printTree(node *root , int *ar , int len){

	if(root == NULL){
		return;
	}
	ar[len] = root->data;
	len++;
	if(root->left == NULL && root->right == NULL){
		for(int i = 0 ;i< len ; i++){
			cout<<ar[i]<<" -> ";
		}
		cout<<endl;
	}
	else{
		printTree(root->left , ar , len);
		printTree(root->right, ar, len);
	}
}


int main(){
	node *root ;
	root = newnode(5);
	// cout<<root->data;
	root->left = newnode(1);
	root->right = newnode(4);
		root->left->left = newnode(9);
	root->left->right = newnode(6);
	root->right->left =newnode(11);

	int ar[10] = {0};
	printTree(root, ar , 0); 
	return 0;
}

