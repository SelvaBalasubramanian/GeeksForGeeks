#include<iostream>

using namespace std;

struct node{
	int data;
	node *left , *right;
};

node* newnode(int data){
	node *temp;
	temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


int diameterOfTree(node *root , int *height){

	if(root == NULL){
		*height = 0;
		return 0;
	}
	int lh , rh;
	int ldia = diameterOfTree(root->left, &lh);
	int rdia = diameterOfTree(root->right , &rh);
	*height = lh > rh ? lh + 1 : rh + 1;
	return max(lh + rh + 1 ,max(ldia , rdia));

}


int heightofsubTree(node *root){

	if(root == NULL)return 0;

	if(root->left == NULL && root->right == NULL){
		// *height = 1;
		return 1; 
	}

	int lh = heightofsubTree(root->left);
	int rh = heightofsubTree(root->right);
	int h = lh > rh ? lh : rh;
	cout<<"Height of "<<root->data<<" is "<<h+1<<endl;
	return h+1;
}


int main(){

	node *root;
	root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
		root->left->left->left = newnode(6);
	root->right->right = newnode(5);
	int h = heightofsubTree(root);
	cout<<diameterOfTree(root , &h);
	cout<<endl<<h;
	return 0;
}