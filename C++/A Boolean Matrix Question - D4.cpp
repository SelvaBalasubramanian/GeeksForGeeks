//https://www.geeksforgeeks.org/a-boolean-matrix-question/
//	
//	
//	Example 1
//	The matrix
//	0 0 0
//	0 0 1
//	should be changed to following
//	0 0 1
//	1 1 1
//	
//	Example 2
//	The matrix
//	1 0 0 1
//	0 0 1 0
//	0 0 0 0
//	should be changed to following
//	1 1 1 1
//	1 1 1 1
//	1 0 1 1

#include<iostream>

using namespace std;

int main(){
		
	int row = 3, col = 4;
	int m[][col] = { 
				 	{ 0, 1, 0,1},
					{ 0, 0, 0,1},
					{ 0, 0, 0,0}
				};
	
	
	int r_flag = 0 , c_flag = 0;
	
	for(int i = 0 ; i< row ; i++){
	for(int j = 0 ; j< col ; j++){
		if(i == 0 && m[i][j] == 1) r_flag = 1;
		if(j == 0 && m[i][j] == 1) c_flag = 1;
		if(m[i][j] == 1){
			m[i][0] = 1;
			m[0][j] = 1;
		}
	}
	}
	
	for(int i = 1 ; i< row ;i++){
		for(int j =1 ; j< col; j++){
			if(m[0][j] == 1 || m[i][0] == 1){
				m[i][j] = 1;
			}
		}
	}
	if(c_flag == 1){	
	for(int i = 0 ;i< row ; i++){
		m[i][0] = 1;		
		}	
	}
	
	if(r_flag == 1){	
	for(int i = 0 ;i< col ; i++){
		m[0][i] = 1;		
		}	
	}
	
	for(int i = 0;i< row ; i++){
		for(int j = 0; j< col ; j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
