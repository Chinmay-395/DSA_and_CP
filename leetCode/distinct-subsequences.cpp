// The problem link - https://leetcode.com/problems/distinct-subsequences/
#include<stdio.h>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int recurFunc(string &s1, string &s2, int i, int j){
	if(j<0) return 1;
	if(i<0) return 0;
	

	if(s1[i] == s2[j])
		return recurFunc(s1,s2,i-1,j-1) 
			+ recurFunc(s1,s2,i-1,j);
	
	else
		recurFunc(s1,s2,i-1,j);
	
}

int main(){
	
	string s1 = "babgbag";
	string s2 = "bag";
	cout<< "The distinct subsequences "<<endl;
	std::cout << recurFunc(s1,s2,s1.size(),s2.size()); 
	return 0;

}