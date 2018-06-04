// http://www.geeksforgeeks.org/maximum-width-of-a-binary-tree/

#include<iostream>

using namespace std;


typedef struct node node ;

struct node{
	int data;
	node *left , *right ;
};


node* newnode(int data){

	node *temp;
	temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

int height(node *root){
	int lh = 0 , rh = 0;
	if(root == NULL) return 0;
	if(root->left == NULL && root->right == NULL)return 1;

	lh += height(root->left);
	rh += height(root->right);

	if(lh > rh) return lh+1;

	 return rh+1;

}


void preorderTraversal(node *root , int *count , int level){

	if(root == NULL)return;
	count[level]++;
	preorderTraversal(root->left , count , level+1);
	preorderTraversal(root->right , count , level+1);
}

int maxWidth(node *root){

	int n = height(root);
	int count[n];
	for(int i = 0 ;i< n; i++)count[i] = 0;

	preorderTraversal(root , count , 0);

	int max = -1;
	for(int i = 0 ;i< n; i++){
		if(max < count[i])max = count[i];
	}
	return max;
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
	cout<<maxWidth(root)<<endl;


	return 0;
}