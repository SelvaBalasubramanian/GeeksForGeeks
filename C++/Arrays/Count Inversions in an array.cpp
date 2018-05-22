#include<iostream>

using namespace std;


int merge(int *ar , int start , int mid , int end){
	
	int size = end - start + 1;
	int count = 0 , j = 0 , c = 0;
	int arr[size];
	int i = 0 ;
	int p = start , q = mid+1;
	while(i < size){
		if(p > mid){
			arr[i++] = ar[q++];
		}
		else if(q > end){
			arr[i++] = ar[p++];
			count += c;
		}
		else if(ar[p] > ar[q]){
			arr[i++] = ar[q++];
			c++;
		}
		else{
			arr[i++] = ar[p++];
			count += c;
		}
	}

	for(int i = 0 ;i<size ;i++,start++){
		ar[start] = arr[i];
	}

	return count;
}


int MergeSort(int *ar , int start ,int end){
	int count = 0;
	if(start < end){
		int mid = (end + start)/2;
		count += MergeSort(ar , start , mid);
		count += MergeSort(ar ,mid+1 , end);
		count += merge(ar, start , mid , end);
	}

	return count;
}





int main(){

	int ar[] = {2,4,1,3,5};
	int len = sizeof(ar)/sizeof(int);

	int k = MergeSort(ar,0,len-1);
	for(int i = 0 ;i< len; i++){
		cout<<ar[i]<<" ";
	}
	cout<<endl<<k;
	return 0;
}