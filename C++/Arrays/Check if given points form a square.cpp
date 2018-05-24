#include<iostream>

using namespace std;

typedef struct{
	int x;
	int y;
}point;

int dist(point a, point b){
	return (a.x - b.x) * (a.x - b.x)  + (a.y - b.y) * (a.y - b.y); 
}

int main(){
	point a = {1,2}, b = {1,0} ,c = {3,0} , d = {3,2};
	int d1 = dist(a,b);
	int d2 = dist(a,c);
	int d3 = dist(a,d);

	if(d1 == d2 && 2*d1 == d3)cout<<"is square\n";

	else if(d2 == d3 && 2*d2 == d1)cout<<"is square\n";

	else if(d1 == d3 && 2*d1 == d2)cout<<"is square\n";

	else{
		cout<<"is not a square\n";
	}

	return 0;
}