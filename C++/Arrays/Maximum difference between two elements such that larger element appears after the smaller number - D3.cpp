//http://www.geeksforgeeks.org/maximum-difference-between-two-elements/


//Input : arr = {2, 3, 10, 6, 4, 8, 1}
//Output : 8
//Explanation : The maximum difference is between 10 and 2.
//
//Input : arr = {7, 9, 5, 6, 3, 2}
//Output : 2
//Explanation : The maximum difference is between 9 and 7.

#include<iostream>

using namespace std;

int main(){
	int ar[] = {2, 3, 10, 6, 4, 8, 1 , 12} ;
	int len = sizeof(ar)/sizeof(int);
	int small = 0 , large  = 0 , cu_sm  = 0 ;//small , large ,currentsmall
	for(int i = 1; i< len;i++){
		
		if(ar[large] < ar[i]){
			large = i;
			small = cu_sm;
		}
		else if(ar[cu_sm] > ar[i]){
			cu_sm = i;
		}
		
	}
	cout<<ar[large] - ar[small];
	
	return 0;
}
