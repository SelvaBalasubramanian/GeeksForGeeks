 // http://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/

#include<iostream>
#include<stack>

using namespace std;

typedef struct node node;
struct node{
	int data;
	struct node *left , *right;
};

node* newnode(int data){

	node *temp ;
	temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void inorderTraversal(node *root){

	if(root == NULL)return ;
	inorderTraversal(root->left);
	cout<<root->data<<" ";
	inorderTraversal(root->right);

}


void spiralFormTraversal(node *root){
	stack<node*>lr;//left to right stack
	stack<node*>rl;//right to left stack
	rl.push(root);
	bool left = false;

	while(!lr.empty() || !rl.empty()){

		node *r;
		if(!left){
			while(!rl.empty()){
				r = rl.top();
				cout<<r->data<<" ";
				rl.pop();

				if(r->right!= NULL)
				lr.push(r->right);

				if(r->left != NULL)
				lr.push(r->left);
			}
			left = true;
		}
		if(left){
			while(!lr.empty()){
				r = lr.top();
				cout<<r->data<<" ";
				lr.pop();

				if(r->left != NULL)
				rl.push(r->left);

				if(r->right!= NULL)
				rl.push(r->right);
			}
			left = false;
		}

	}//while

}

int main(){

	node *root;
	root =  newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(7);
	root->left->right = newnode(6);
	root->right->left = newnode(5);
	root->right->right = newnode(4);
	inorderTraversal(root);
	cout<<endl;
	spiralFormTraversal(root);
	cout<<endl;

	return 0;
}