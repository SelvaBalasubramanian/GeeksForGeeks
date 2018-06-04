// http://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/

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


bool ispathAvailable(node *root , int curr , int sum){

	curr += root->data;
	bool ret = 0;
	if(root == NULL) return 0;

	if(root->left == NULL && root->right == NULL && curr == sum){
		return 1;
	}

	if(root->left){
		ret = ret || ispathAvailable(root->left , curr , sum);
	}
	if(root->right){
		ret = ret || ispathAvailable(root->right , curr , sum);
	}

	return ret;
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

	if(ispathAvailable(root , 0 , 13))cout<<"YES\n";
	else cout<<"NO\n";

 	return 0;
 }




