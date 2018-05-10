//https://www.geeksforgeeks.org/move-zeroes-end-array/
//
//Input :  arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
//Output : arr[] = {1, 2, 4, 3, 5, 0, 0};
//
//Input : arr[]  = {1, 2, 0, 0, 0, 3, 6};
//Output : arr[] = {1, 2, 3, 6, 0, 0, 0};


#include <iostream>
using namespace std;

int main() {
	int ar[] = {1, 2, 0, 4, 3, 0, 5, 0};
	int n = sizeof(ar)/sizeof(int);
	
	
	int c = 0;
	for(int i  = 0; i<n ;i++){
		if(ar[i] != 0){
			ar[c++] = ar[i];
		}
	}
	while(c<n){
		ar[c++] = 0;
	}
	
	for(int i = 0;i<n ;i++){
		cout<<ar[i]<<" ";
	}
	return 0;
}
