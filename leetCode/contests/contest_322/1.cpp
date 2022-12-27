#include<bits/stdc++.h>
#include <iostream>
#include <sstream>
using namespace std;

class Solution{
public:
//
// below is my solution during the contest
	bool f(string s){
		vector<vector<char>> stringList;
		vector<char> word;
		for(int i=0; i<s.size(); i++){
			if(s[i] == ' '){
				stringList.push_back(word);
				word.clear();
				
			}else{
				word.push_back(s[i]);
			}
		}
		if(word.size()>0 && word[0]!=' '){
				stringList.push_back(word);
				word.clear();
		
		}
		// 3
		/*
			i=0 --> i=1
			i=1 --> i=2
			i=2 --> i=0
			i --> (i+1)%3
			
		*/ 
		int totalList = stringList.size();
		cout<<"The total list "<<totalList;
		for(int i=0; i<totalList; i++){
  		vector<char> a = stringList[i];
  		vector<char> b = stringList[(i+1)%totalList];
  		cout<<"Comparin: "<<endl;
  		cout<<"a: "<<a[a.size()-1]<<"\t";
  		cout<<"b: "<<b[0]<<endl;  		
			if(a[a.size()-1] != b[0]){
				return false;
			}
		}
		return true;
	}
};

int main(){
	Solution sol;
	string sentence = "Leetcode is cool";//"eetcode";//"leetcode exercises sound delightful";
	if(sol.f(sentence))
		cout<<"Main func"<<"\n";
	else
		cout<<"Something went wrong";
	return -1;
}
