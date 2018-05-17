//http://www.geeksforgeeks.org/leaders-in-an-array/

// input ar = {16,17,4,5,6,3,2}
// output  17 , 6,  3  , 2


#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	int ar[] = {16,17,4,5,6,3,2};
	int len = sizeof(ar)/sizeof(int);
	int max = INT_MIN;
	vector<int> a;
	for(int i = len-1; i>=0 ;i--){
		if(ar[i] >  max){
			max = ar[i];
			a.push_back(max);
		}
	}
	
	len = a.size();
	for(int i = len-1 ; i >= 0; i-- ){
		cout<<a[i] <<" ";
	}
	
}
