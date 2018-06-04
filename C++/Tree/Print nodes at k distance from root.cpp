// http://www.geeksforgeeks.org/print-nodes-at-k-distance-from-root/


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

void nodeAtk(node *root , int k , int level){

	if(root == NULL)return;
	if(level == k){
		cout<<root->data<<" ";
		return;
	}

	nodeAtk(root->left , k , level+1);
	nodeAtk(root->right , k , level+1);

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

	nodeAtk(root , 3 ,1);

	return 0;
}