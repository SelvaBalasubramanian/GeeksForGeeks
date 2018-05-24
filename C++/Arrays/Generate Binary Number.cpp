// http://www.geeksforgeeks.org/interesting-method-generate-binary-numbers-1-n/

#include<iostream>
#include<queue>

using namespace std;

 int main(){

 	int n;
 	cin>>n;

 	queue<string> q;
 	q.push("1");
 	while(n--){
 		cout<<q.front()<<" ";
 		string s1 = q.front();
 		q.pop();

 		string s2 = s1;
 		s1.append("0");
 		q.push(s1);
 		s2.append("1");
 		q.push(s2);

 	}

 	return 0;
 }