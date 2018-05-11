//https://www.geeksforgeeks.org/implement-min-heap-using-stl/



#include<bits/stdc++.h>

using namespace std;

struct compare{
	bool operator()(int a , int b ){	
		int t = a > b;
	
		return t ;
	}
};
int main(){
	priority_queue<int ,vector<int>, compare >p;
	int n ; 
	cin>>n;
	for(int i = 0 ;i<n ; i++){
		int t;
		cin>>t;
		p.push(t);
	}
	
	cout<<endl;
	while(!p.empty()){
		cout<<p.top();
		p.pop();
	}
	return 0;
	
}



