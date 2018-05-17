//http://www.geeksforgeeks.org/find-the-row-with-maximum-number-1s/

//Example
//Input matrix
//0 1 1 1
//0 0 1 1
//1 1 1 1  // this row has maximum 1s
//0 0 0 0
//
//Output: 2

#include<iostream>

using namespace std;

int main(){
	
	int r = 4 , c = 4;
	int  mat[r][c] = { {0, 0, 0, 1},
                       {0, 1, 1, 1},
                       {0, 1, 1, 1},
                       {0, 0, 0, 0}};
	
	
	//get first 1 in 0th row 
	int j = -1;
	for(int i = 0 ;i< c; i++){
		if(mat[0][i] == 1){
			j = i;
			break;
		}
	}
	if(j == -1){
		j = c-1;
	}
	int max_row = 0;
	for(int i = 0 ;i< r ;i++){
		
		while( j >= 0  && mat[i][j] == 1 ){
			 j--;
			 max_row = i;
			 
		}
		if(j == -1){
			break;
		}
		
	}
	cout<<max_row;
	
	
	return 0 ;
}
