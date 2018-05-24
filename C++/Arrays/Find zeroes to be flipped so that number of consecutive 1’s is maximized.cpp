//  https://www.geeksforgeeks.org/find-zeroes-to-be-flipped-so-that-number-of-consecutive-1s-is-maximized
// Input:   arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1}
//          m = 2
// Output:  5 7

#include<iostream>
#include<queue>
using namespace std;

int main(){

	int ar[] ={1,0,0,1,1,1,0,1,1,1,1,0,0,0,0,0,1};
	int len = sizeof(ar)/sizeof(int);
	int m  = 2;

	int zero_count = 0;
	int wl = 0 , wr=0 , curr=0 , best=0 , bl =0;

	queue<int>q;

	for(; wr< len ; ){

		if(zero_count <= m){
			if(ar[wr] == 0)zero_count++;
			wr++;
		}
		if(zero_count > m){
			if(ar[wl] == 0)zero_count--;
			wl++;
		}

		if(wr - wl > best){
			best = wr- wl;
			bl = wl;
		}





	}
	for(int i = 0 ; i<best ; i++){
		if(ar[i+bl] == 0) cout<<i+bl<<" -- ";
	}


	return 0;
}