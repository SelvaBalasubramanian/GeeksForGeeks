//  https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/

//Input:  arr[] = {1, 2, 3, -4, -1, 4}
//Output: arr[] = {-4, 1, -1, 2, 3, 4}
//
//Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
//output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}



#include<iostream>

using namespace std;

int getPositive(int *ar, int i , int len ){
	for(i;i<len ; i++){
		if(ar[i] >=0 )
			return i;
	}
	return -1;
}

int getNegative(int *ar, int i , int len ){
	for(i;i<len ; i++){
		if(ar[i] < 0 )
			return i;
	}
	return -1;
}




int main(){
	
	int ar[] = {-5, -2, -5, -2, -4, -7, -1, 8, 0, -8};
	int len = sizeof(ar)/sizeof(int);
	for(int i = 0 ;i<len; i++ ){
		if(i%2 != 0 && ar[i] < 0){
			int k = getPositive(ar, i + 1 ,len );
			if(k == -1)break;//rest of elements are negative - no +ve element found
			int temp = ar[k];
			while(k>i){
				ar[k] =  ar[k-1];
				k--;
			}
			ar[i] =  temp;
		}
		else if (i%2 == 0 && ar[i] >=0){
			int k = getNegative(ar, i + 1 ,len );
			if(k == -1)break;//rest of elements are +ve - no -ve element found
			int temp = ar[k];
			while(k>i){
				ar[k] =  ar[k-1];
				k--;
			}
			ar[i] =  temp;
		}
	
	}
	
	for(int i= 0; i<len ;i++){
		cout<<ar[i]<<" ";
	}
	
	return 0;
}
