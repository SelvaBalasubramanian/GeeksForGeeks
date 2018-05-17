//https://www.geeksforgeeks.org/check-number-fibonacci-number/

#include<iostream>
#include<math.h>

using namespace std;
int isFibonacci(int n){
	int t = 5*n*n - 4;
	int t2 = 5*n*n +4;
	int s1,s2;
	s1 = sqrt(t);
	s2 = sqrt(t2);
	if(s1*s1 == t || s2*s2 == t2){
		return 1;
	}
	
	return 0;
}


int main(){
	int n;
	cin>>n;
	for(int i = 0;i< n;i++){
		if(isFibonacci(i)){
			cout<<i<<" isFibonacci"<<endl;
		}
		else{
			cout<<i<<" is not Fibonacci"<<endl;
		}
	}
	
	
	return 0;
}



