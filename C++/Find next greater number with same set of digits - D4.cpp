//http://www.geeksforgeeks.org/find-next-greater-number-set-digits/


#include<iostream>

using namespace std;


int getMax(string s ,int d , int len ){
	int flag = 0 ;
	int a  = d;
	for(int i = d ; i<len ;i++ ){
		if(s[i] - s[d-1]  > 0 && flag == 0){
			flag = 1;
			a = i;
		}
		else{
			if(s[i] - s[d-1] > 0 && s[i] - s[a] < 0 )  {
				a = i;
			}
		}
	}
return a;
	
}


int main(){
	
	string s = "4321";
	int len = s.length();
	int d = -1;
	int flag = 0;
	
	for(int i = len-1 ; i>0 ; i-- ){
			if(s[i-1] < s[i]){
				d= i;
				break;
			}		
	}
	
	if(d == -1) {
		cout<<"noo possible"<<endl;
	}
	else{
	 	int next_max = getMax(s , d , len);
	 		char t = s[d-1];
			s[d-1] = s[next_max];
			s[next_max] = t;

		for(int i = d ;i<len-1 ;i++ ){
			int min = i;
			for(int j = i+1; j<len ; j++){
				if(s[min] > s[j]){
					min = j;
				}
			}
			
			char a = s[i];
			s[i] = s[min];
			s[min] =a;
		}
		cout<<s;
	}
	
	return 0;
}

