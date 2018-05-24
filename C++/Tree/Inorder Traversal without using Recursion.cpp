#include<iostream>
#include<stack>

using namespace std;
 typedef struct node node;
 struct node{
 	int data;
 	node *left,*right;

 };

 node* newnode(int data){
 	node *temp;
 	temp = new node();
 	temp->data = data;
 	temp->left = NULL;
 	temp->right = NULL;
 	return temp;
 }


void inorderUsingStack(node *root){

	stack<node *>st;
	st.push(root);
	while(!st.empty()){
		cout<<"RE"<<endl;
		node *ptr ;
		node *curr;
		ptr = NULL;
		curr = root;
		while(curr != NULL){
			curr = curr->left;
			st.push(curr);
		}
		if(curr == NULL){	
			ptr = st.top();
			st.pop();
			cout<<ptr->data<<" ";
		}
		if(ptr->right != NULL){
			curr = ptr->right;
		}
		else{
			curr = NULL;
		}

	}


}

  int main(){
  	cout<<"HII"<<endl;
 	node *root ;
 	root = newnode(5);
 	root->left = newnode(1);
	root->right = newnode(4);
	root->left->left = newnode(9);
	root->left->right = newnode(6);
	root->right->left =newnode(11);
	inorderUsingStack(root);

 	return 0;
 }
