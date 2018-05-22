#include<iostream>

using namespace std;


int isMultiple(int n){

	if (n<0) n = abs(n);
	if(n == 0) return 1;
	if(n == 1) return 0;
	int evenCount = 0;
	int oddCount = 0;

	while(n){
		if(n & 1){
			oddCount++;
		}
		n = n>>1;
		if(n&1)evenCount++;
		n= n>>1;
	}

	return isMultiple(abs(oddCount - evenCount));

}


int main(){

	int no = 6;
	if(isMultiple(no)){
		cout<<"is a Multiple\n";
	}
	else{
		cout<<"Not a multiple of 3"<<endl;
	}

	return 0;
}