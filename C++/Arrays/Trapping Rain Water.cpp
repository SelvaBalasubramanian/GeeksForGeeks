#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	
	int arr[] = {2,4,5,0,0,6,7,0,0};
	int len = sizeof(arr)/ sizeof(arr[0]);
	int start = 0 ; 
	int end = len -1;
	int left_max = 0;
	int right_max = 0;
	int water = 0;

	while(start < end){

		if(arr[start] < arr[end]){
			if(arr[start] > left_max) left_max = arr[start];
			else{
				water += left_max - arr[start];
			}
			start++;
		}
		else{
			if(arr[end] > right_max )right_max = arr[end];
			else water += right_max - arr[end];
			end--;
		}

	}
	cout<<water;


 	return 0;
}