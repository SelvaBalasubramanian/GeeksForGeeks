//https://www.geeksforgeeks.org/sort-an-almost-sorted-array-where-only-two-elements-are-swapped/



#include<iostream>

using namespace std;

int main(){
	
	int ar[] = { 10,20,30,40,30,50};
	int len = sizeof(ar)/sizeof(int);
	int max = -1 ;
	int i;
	
	for( i = 0 ;i< len ;i++){
		if(max == -1 && ar[i] > ar[i+1]){
			max = i;
			cout<<ar[max]<<endl;
			i++;
		}
		if(max != -1 && ar[max] < ar[i] ){
			int temp = ar[i-1];
			ar[i-1] = ar[max];
			ar[max] = temp;
			break;
		}
	}
	
	if(i == len){
			int temp = ar[i-1];
			ar[i-1] = ar[max];
			ar[max] = temp;
	}
	
	for(int i = 0; i<len ; i++){
		cout<<ar[i] <<" ";
	}
	
	return 0;
}
