//set 1: 
// https://www.geeksforgeeks.org/print-binary-tree-vertical-order/ 


#include<iostream>
#include<vector>
#include<map>

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

void print(node *root){

	if(root == NULL)return ;
	else{
		cout<<root->data<<" ";
		print(root->left);
		print(root->right);
	}
}

void setVerticalValues(node *root , int currVerLevel , map< int , vector< int > > &m){
	if(root == NULL)return ;
	m[currVerLevel].push_back(root->data);
	setVerticalValues(root->left , currVerLevel-1,m);
	setVerticalValues(root->right , currVerLevel+1 ,m);
}
	
void printVerticalOrder(node* root){

	if(root == NULL)return;

	map < int , vector < int > >m;
	setVerticalValues(root, 0 , m);
	cout<<endl;
	map < int , vector < int > >::iterator it;
	for(it = m.begin() ; it != m.end() ; it++){
		int len = it->second.size();
		cout<<it->first<<" : ";
		for(int i = 0  ; i< len ; i++)cout<<it->second[i]<<" ";
		cout<<endl;
	}


}



int main(){
	node *root;
	root = newnode(5);
	root->left = newnode(6);
	root->right = newnode(7);
	root->left->right = newnode(1);
	root->left->left = newnode(2);
	root->right->left = newnode(8);
	root->right->right= newnode(9);

	printVerticalOrder(root);



	return 0;
}