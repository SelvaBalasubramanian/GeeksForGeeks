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

int getIndex(int *inorder , int *preorder , int preIndex ,int start ,  int end){
	int i = start ;
	for( ; i<= end; i++){
		if(inorder[i] == preorder[preIndex]){break;}
	}

	return i;
}



node* buildTree( int *inorder , int *preorder , int start , int end  ){
	if(start > end)return NULL;
	node *root;
	static int preIndex = 0;
	int inIndex = getIndex(inorder ,preorder , preIndex , start , end);


	root = newnode(inorder[inIndex]);
			preIndex++;


	root->left = buildTree(inorder , preorder , start , inIndex-1 );
	root->right = buildTree(inorder , preorder  , inIndex+1 , end  );
		cout<<root->data<<" "; //will print in post order
	return root;
}
void print(node *root){

	if(root == NULL)return ;
	else{
		cout<<root->data<<" ";
		print(root->left);
		print(root->right);
	}
}
int main(){

	int preorder[] = {1 , 2 , 4 , 5, 7 , 6 , 8 , 3 , 9 , 10 , 12 , 13 , 14 , 11};
	int inorder[] = {7 , 5 , 6 , 4 , 8, 2 , 1 , 3 ,12 , 10 , 14 , 13 , 9 , 11};

	node *root ;
	root = NULL;
	int end = sizeof(inorder)/sizeof(int);
	cout<<"before buildTree\n";
	root = buildTree(inorder , preorder , 0 , end-1  );
	cout<<endl;
	print(root);

	return 0;
}