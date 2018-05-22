#include<iostream>

using namespace std;

typedef struct node node;

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

int isIdentical(node *root1 , node *root2){

	if(root1 == NULL && root2 == NULL)return 1;
	else if(root1 != NULL && root2 != NULL){
		return root2->data == root1->data && isIdentical(root1->left , root2->left) && isIdentical(root1->right ,root2->right);
	}

	return 0;
}

int main(){
	node *root , *root2;
	root2 = root = NULL;
	root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);

	root->left->left = newnode(4);
	root->left->right  = newnode(5);

	root->right->left = newnode(6);
	root->right->right = newnode(7);

	root2 = newnode(1);
	root2->left = newnode(2);
	root2->right = newnode(3);

	root2->left->left = newnode(4);
	root2->left->right  = newnode(5);

	root2->right->left = newnode(6);
	// root2->right->right = newnode(7);

	preorderTraversal(root);
	cout<<endl;
	preorderTraversal(root2);
	cout<<endl;

	if(isIdentical(root, root2))cout<<"Is Identical \n";
	else cout<<"Not Identical\n";

	return 0;
}