//http://www.geeksforgeeks.org/rearrange-array-maximum-minimum-form-set-2-o1-extra-space/

//Example
//Input  : arr[] = {1, 2, 3, 4, 5, 6, 7} 
//Output : arr[] = {7, 1, 6, 2, 5, 3, 4}
//
//Input  : arr[] = {1, 2, 3, 4, 5, 6} 
//Output : arr[] = {6, 1, 5, 2, 4, 3}
//

// Criteria : space O(1)

#include<iostream>


using namespace std;

int main(){
	int ar[] = {1, 2, 3, 4, 5, 6, 7 ,9,11,23} ;
	int n = sizeof(ar)/sizeof(int);
	int max_ind = n-1;
	int min_ind = 0;
	int max_ele = ar[n-1] + 1;
	
	for(int i = 0 ;i<n ; i++){
		
		if(i%2 == 0){
			ar[i] += (ar[max_ind] % max_ele) * max_ele;
			max_ind--;
		}
		else {
			ar[i] += (ar[min_ind] % max_ele) * max_ele;		
			min_ind++;
		}

	}
	
	for (int i = 0 ; i < n; i++){
        ar[i] = ar[i] / max_ele ;
        cout<<ar[i]<<" ";
    }
	return 0;
}
