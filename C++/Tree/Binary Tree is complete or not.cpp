#include<iostream>
#include<queue>
using namespace std;


struct node 
{
	int data;
	struct node *left, *right;	
};


node* newnode(int data){
	node* temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}


bool iscomplete(node* root){
	queue<node *> q;
	q.push(root);
	bool leftRule  = true;
	while(!q.empty()){
		node *temp = q.front();
		q.pop();
		if(leftRule){
			if(temp->left && temp->right){
				q.push(temp->left);
				q.push(temp->right);
			}
			else if(temp->left){
				q.push(temp->left);
				leftRule = false;
			}

			else if(temp->right){
				q.push(temp->right);
				return false;
			}
			else{
				leftRule = false;
			}
		}
		else if(temp->left != NULL || temp->right != NULL){
			return false;
		}
	
	}
	return true;
}



int main(){

	node *root ;
	root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
		root->right->left = newnode(6);
	root->right->right = newnode(6);
	if(iscomplete(root)){
		cout<<"IS COMPLETE BINARY TREE \n";
	}
	else
		cout<<"is not a binary tree \n";

	return 0 ;
}