//http://www.geeksforgeeks.org/count-substrings-with-same-first-and-last-characters/


#include<iostream>

using namespace std;

int main(){
	string s ;
	cin>>s;
	int ar[26] = {0};
	int len = s.length();
	for(int i = 0;i< len ; i++){
		ar[s[i] - 'a']++;
	}
	
	
	int result =0 ;
	
	for(int i = 0;i< 26 ;i++){
		result += (ar[i] * (ar[i]+1) /2);
	}
	cout<<result;
	
}
