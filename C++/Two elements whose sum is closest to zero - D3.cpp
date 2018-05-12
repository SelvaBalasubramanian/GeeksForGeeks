//https://www.geeksforgeeks.org/two-elements-whose-sum-is-closest-to-zero/


#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int ar[] = {1, 60, -10, 70, -80, 85};
	int len = sizeof(ar)/ sizeof(int);
	sort(ar,ar+len);
	for(int i = 0 ;i< len ; i++)cout<<ar[i]<<" ";
	cout<<endl;
	int start = 0; 
	int end = len -1 ;
	int min = INT_MAX;
	cout<<min<<endl;
	int m , n;
	while(start < end){
		if(min > abs(ar[end] + ar[start] )){
			min = abs(ar[end] + ar[start]);
			m = ar[start];
			n = ar[end];
		}
		if(ar[end] + ar[start] < 0){
			start++;
		}
		else
			end--;
	}
	
	cout<<m<<" "<<n;
	return 0;
}
