// https://www.geeksforgeeks.org/find-two-rectangles-overlap/

#include<iostream>

using namespace std;
typedef struct{
	int x ,y;
}point;

bool isOverlap(point l1 , point r1,point l2 , point r2){
		if(l1.x > r2.x || l2.x > r1.x)return false;
		if(l2.y < r1.y || l1.y < r2.y) return false;
	return true;
}

int main(int argc, char const *argv[])
{
	point l1 = {0, 10}, r1 = {10, 0};
    point l2 = {5, 5}, r2 = {15, 0};

    if(isOverlap(l1,r1,l2,r2))cout<<"isOverlap\n";
    else cout<<"not Overlapping\n";
	
	return 0;
}