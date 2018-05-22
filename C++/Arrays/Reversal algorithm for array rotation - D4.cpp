//https://www.geeksforgeeks.org/?p=2838

#include<iostream>

using namespace std;


void reverse(int *ar , int start , int end){
	while(start< end){
		int temp = ar[start];
		ar[start] = ar[end];
		ar[end] = temp;
		start++;
		end--;
	}
}


// int main(){
	
// 	int ar[]  = {3,5,4,6,7,8,9,1} ; 
// 	int len = sizeof(ar)/sizeof(int);
	
// 	int rotate = 4;
	
// 	reverse(ar, 0 , rotate-1);
// 	reverse(ar , rotate, len -1);
// 	reverse(ar , 0 , len-1);
	
	
// 	for(int i = 0 ; i< len ; i++){
// 		cout<<ar[i]<<" ";
// 	}
	
// 	return 0 ;
// }

//another optimal solution 
// if no of rotations is greater than length of array;
int main(){
	int ar[]  = {3,5,4,6,7,8,9,1} ; 
	int len = sizeof(ar)/sizeof(ar[0]);
	int temp[len];

	int d = 10; //no of rotations 

	for(int i = 0 ; i< len ; i++){
		temp[(i+n-d)%n] == ar[i];
	}	
	for(int i = 0 ; i<len ; i++){
		cout<<temp[i]<<" ";
	}

}