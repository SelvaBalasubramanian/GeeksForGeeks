//https://www.geeksforgeeks.org/majority-element/
//
//Input : {3, 3, 4, 2, 4, 4, 2, 4, 4}
//Output : 4 
//
//Input : {3, 3, 4, 2, 4, 4, 2, 4}
//Output : No Majority Element

//array no whos count is greater than n/2


#include<iostream>

using namespace std;

int main(){
	
	int ar[] =  {3, 3, 4, 3, 4, 4, 3, 4, 3};
	int len = sizeof(ar)/sizeof(int);
	
	//Moore majority voting 
	
	int m_index = 0 , count = 1;
	//loop in search for majority element 
	for(int i = 1;i< len ; i++){
		if(ar[m_index] == ar[i]){
			count++;
		}
		else{
			count--;
		}
		if(count == 0){
			m_index = i;
			count = 1;
		}
				
	}
	 
	//isMajority??
	count = 0;
	for(int i =  0 ; i<len ;i++){
		if(ar[i] == ar[m_index]){
			count++;
		}
	}
	if(count > len/2){
		cout<<ar[m_index];
	}else{
		cout<<"No majority element";
	}
	
	return 0;
}
