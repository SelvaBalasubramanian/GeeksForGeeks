// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

#include<iostream>

using namespace std;

int main(){
	int ar[] = {-1,-2,4,-2,-1,5,6,-8};
	int len = sizeof(ar)/sizeof(int);
	int max=0, max_here=0;
	for(int i = 0 ;i< len;i++){
		max_here += ar[i];
		if(max_here < 0){
			max_here = 0 ;
		}
		if(max < max_here){
			max = max_here;
		}
	}
	
	cout<<max;
	
	
	return 0;
}
