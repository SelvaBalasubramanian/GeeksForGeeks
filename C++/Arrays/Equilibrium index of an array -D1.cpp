//  https://www.geeksforgeeks.org/equilibrium-index-of-an-array/ 
   
   
   
#include <iostream>
using namespace std;
     
int main() {
    	int ar[] = {-7, 1, 5, 2, -4, 3, 0};
    	int len = sizeof(ar)/sizeof(int);
    	int sum = 0;
    	for(int i =0 ;i< len ; i++){
    		sum += ar[i];
    	}
    	int pre = 0;
    	int flag = 0 ;
    	for(int i = 1; i<len ; i++){
    		pre += ar[i-1];
    		if(pre  == sum - pre - ar[i]){
    			cout<<i;
    			flag  = 1;
    			break;
    		}
    	}
    	if(flag == 0){
    		cout<<"-1";
    	}
    	return 0;
	}
