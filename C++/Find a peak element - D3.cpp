//https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/

#include<iostream>

using namespace std;

int main(){
		
	int ar[] = {10, 20, 15, 2, 23, 90, 67};
	int len = sizeof(ar)/sizeof(int);
	int start = 0;
	int end = len -1 ;
	
	while(start <= end){
		
		int mid = (start + end) / 2;
		
		if((mid == 0 || ar[mid - 1] <= ar[mid]) && (mid ==  len-1 || ar[mid+1] <= ar[mid]) ){
			cout<<mid;
			break;
		}
		else if(ar[mid+1] >= ar[mid]){
			start = mid+1;
		}
		else{
			end = mid-1;
		}
		
	}

	return 0;
}
