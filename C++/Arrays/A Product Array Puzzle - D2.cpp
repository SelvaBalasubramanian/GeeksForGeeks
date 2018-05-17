//https://www.geeksforgeeks.org/a-product-array-puzzle/


//Example:
//arr[] = {10, 3, 5, 6, 2}
//prod[] = {180, 600, 360, 300, 900}
//

#include<iostream>

using namespace std;

int main(){
	
	int n ;
	cin>>n;
	int *ar = new int[n];
	for(int i = 0;i< n ;i++){
		cin>>ar[i];
	}
	
	int prod[n];
	prod[0] = 1;
	for(int i = 0;i<n-1;i++){
		prod[i+1] = prod[i] * ar[i];
	}
	
	int temp = ar[n-1];
	for(int i = n-2; i>=0;i--){
		prod[i] = prod[i] * temp;
		temp *= ar[i];
	}
	
	for(int i = 0;i<n;i++){
		cout<<prod[i]<<" ";
	}
	
	
	
	return 0;
}

