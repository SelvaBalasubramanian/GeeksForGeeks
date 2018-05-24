// https://www.geeksforgeeks.org/zigzag-or-diagonal-traversal-of-matrix/

#include<iostream>

using namespace std;

int main(){

	int n , m;
	cin>>n>>m;

	int ar[n][m];

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m ; j++){
			cin>>ar[i][j];
		}
	}
	int i = 0 ,j =0;
	int t_start = n+m-1 ,count = 1;
	while(i<=t_start){
		int k ;
		int j;
		if(i<=n-1){
			k =i;
			j = 0;
		}
		else{
			k = n-1;
			j = count;
		}
		
		while((j >=0 && j<m) && (k>=0 && k < n)){
			cout<<ar[k][j]<<" ";
			k--;
			j++;
		}
		cout<<endl;
		i++;
		count++;
	}

}