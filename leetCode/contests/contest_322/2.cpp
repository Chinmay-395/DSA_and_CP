#include<bits/stdc++.h>
using namespace std;
/*

*/
class Solution{
public:
  long long dividePlayers(vector<int>& skill){
  	long long total = 0;
  	map<long long, int>mp;
  	for(auto i:skill){
  		total+=i;
  		mp[i]++;
  	}
  	long long teams = skill.size()/2;
  	if(total%teams != 0) return -1;
  	int score = total/teams;
  	long long ans = 0;
  	for(int i=0; i<skill.size(); i++){
  		if(mp[skill[i]]>0){
  			mp[skill[i]]--;
  			long long other = score - skill[i];
  			if(mp[other]>0){
  				mp[other]--;
  				ans+=skill[i]*other;
  			}else return -1;
  		}
  	}
  	return ans;
  }    
};

int main(){
	Solution sol;
	cout<<"Main func"<<"\n";
	return -1;
}
