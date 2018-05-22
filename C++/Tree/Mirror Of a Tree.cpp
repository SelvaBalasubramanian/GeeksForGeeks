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
void preorderTraversal(node *root){

	if(root == NULL)return ;
	cout<<root->data<<" ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);

}


node* mirrorOfTree(node *root){

	if( root == NULL)return NULL;

	node *r = newnode(root->data);
	r->left = mirrorOfTree(root->right);
	r->right = mirrorOfTree(root->left);

	return r;
}





int main(){


	node *root ;
	root = NULL;
	root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);

	root->left->left = newnode(4);
	root->left->right  = newnode(5);

	root->right->left = newnode(6);
	root->right->right = newnode(7);

	node *a ;
	a = mirrorOfTree(root);
	preorderTraversal(root);
	cout<<"\n";
	preorderTraversal(a);
	cout<<endl;

	return 0;
}