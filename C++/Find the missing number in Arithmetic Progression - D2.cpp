//https://www.geeksforgeeks.org/find-missing-number-arithmetic-progression/
//
//Input: arr[]  = {2, 4, 8, 10, 12, 14}
//Output: 6
//
//Input: arr[]  = {1, 6, 11, 16, 21, 31};
//Output: 26

#include<iostream>

using namespace std;

int main(){
	
	int ar[] = {1, 6, 11, 16, 21, 31};
	int n = sizeof(ar)/sizeof(int);
	int start = 0; 
	int end = n -1;
	int diff = (ar[end] - ar[start])/n;
	
	cout<<diff<<endl;
	
	if(ar[start] + (end + 1) * diff == ar[end] ){
		while(start < end){
//					cout<<" between "<<ar[start]<<" "<<ar[end]<<endl;
			int mid = (start + end)/2;
			if(ar[mid] + diff !=  ar[mid + 1 ]){
				cout<< ar[mid] + diff;
				break;
			}
			else if(ar[mid] - diff != ar[mid - 1]){
				cout<< ar[mid] - diff;
				break;
			}
			if(ar[start] + (mid) * diff == ar[mid]){
				start = mid + 1;
			}
			else{
				end = mid - 1;
			}
			
		}
	}
	else{
		cout<<"no num is missing"; // no number is missing 
	}

	
	
	
	
}
