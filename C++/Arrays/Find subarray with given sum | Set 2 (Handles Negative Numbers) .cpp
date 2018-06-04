// https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/


#include<iostream>
#include<unordered_map>

using namespace std;

int main(){

	int ar[] = {1 ,2,3,4,5,6,7,8,8};
	int sum = 11;
	int n = sizeof(ar)/sizeof(ar[0]);

	unordered_map<int , int> m;
	int curr = 0;
	for(int i= 0; i< n ; i++){
		curr += ar[i];
		if(sum == curr){
			cout<<"Found : "<<0<<" & "<<i<<endl;
			break;
		}

		if(m.find(curr - sum) != m.end()){
			cout<<"Found : "<<m[curr-sum] + 1<<" & "<<i<<endl;
			break;
		}
		m[curr] = i;
	}

	return 0;
}