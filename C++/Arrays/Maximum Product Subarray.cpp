
#include<iostream>

using namespace std;

int main(){

	int arr[] = {6,7,-3,4,0,5,0,6,0,10};
	int len = sizeof(arr)/sizeof(int);

	int max_prod = 0, curr= 1 , start , end , s=0;
	for(int i = 0 ; i< len ; i++){
		curr *= arr[i];

		if(curr > max_prod){
			max_prod = curr;
			start = s;
			end = i;
		}
		if(curr == 0){
			curr = 1;
			s = i+1;
		}
	}

	cout<<"maximum product is :"<<max_prod <<" Index : "<<start<<" - "<<end<<endl;
	return 0;
}