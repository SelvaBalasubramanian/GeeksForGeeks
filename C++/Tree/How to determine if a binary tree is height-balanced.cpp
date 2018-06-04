// http://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/

#include<iostream>

using namespace std;


typedef struct node node;

struct node{
	int data;
	node *left ,*right ;
};


node* newnode(int data){

	node *temp ;
	temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;

}

int height(node *root){

	if(root == NULL)return 0;
	if(root->left == NULL && root->right == NULL)return 1;

	int lh = 0 , rh =0 , flag = 1;

	lh = height(root->left);
	rh = height(root->right);

	if(lh != -1 && rh != -1){
		if(abs(lh - rh) > 1){
			return -1;
		}
		else{
			if(lh > rh)return lh+1;
			return rh+1;
		}

	}

	return -1;

}




int isbalanced(node *root){

	if(root == NULL)return 1;

	else{
		return height(root);
	}

}


 int main(){

 	node *root;
	root  = newnode(11);
	root->left = newnode(22);
	root->right = newnode(33);
	root->left->left = newnode(44);
	root->right->left = newnode(55);
	root->left->right = newnode(66);
	root->right->right = newnode(77);

	// root->right->right->left = newnode(88);
	// root->right->right->right = newnode(99);
	// root->right->right->left->right = newnode(10);
	// root->right->right->left->right->left = newnode(222);


	if(isbalanced(root) == -1){
		cout<<"Not Balanced\n";
	}`

	else cout<<"Balanced\n";

 	return 0;
 }