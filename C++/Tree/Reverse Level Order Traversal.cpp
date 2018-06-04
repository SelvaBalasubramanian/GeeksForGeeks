#include<iostream>
#include<stack>
#include<queue>

using namespace std;

 typedef struct node node;

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

 //using recursion

 int height(node *root){
 	int lh = 1 ,rh = 1;
 	if(root == NULL)return 0;

 	lh += height(root->left);
 	rh += height(root->right);
 	if(lh > rh)return lh;
 	else return rh;
 }

 void printLevelNodes(node *root , int level){

 	if(root == NULL)return;
 	if(level == 1 ){
 		cout<<root->data<<" ";
 	}
 	else{
 		printLevelNodes(root->left , level-1);
 		printLevelNodes(root->right , level-1);
 	}
 }


 void reverseLevelOrderTraversal(node *root){

 	int h = height(root);
 	cout<<"Height : "<<h<<endl;
 	for(int i = h; i>= 1; i--){
 		printLevelNodes(root , i);
 	}

 }

//using stack


 void reverseLevelOrderStackQueue(node *root){
 	stack<node *> st;
 	queue<node *> q;

 	q.push(root);
 	while(!q.empty()){
 		node *temp;
 		 temp = q.front();
 		 q.pop();
 		 st.push(temp);

 		 if(temp->right != NULL)q.push(temp->right);
 		 if(temp->left != NULL)q.push(temp->left);
 	}

 	while(!st.empty()){
 		node *temp ;
 		temp = st.top();
 		st.pop();
 		cout<<temp->data<<" ";
 	}
 }


 int main(){

 	node *root ; 
 	root = newnode(1);
 	root->left = newnode(2);
 	root->right = newnode(3);
 	root->left->left = newnode(4);
 	root->left->right = newnode(5);
 	root->right->left = newnode(6);
 	root->right->right = newnode(7);
 	 	root->right->left->right = newnode(8);

 	
 	reverseLevelOrderTraversal(root);
 	cout<<endl;
 	reverseLevelOrderStackQueue(root);
 	cout<<endl;

 	return 0;
 }