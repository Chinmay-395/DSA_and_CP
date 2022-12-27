#include<bits/stdc++.h>
using namespace std;
/*
since we know the last city in the entire graph,
and we can travel the every node more than once

---------

the recurssion or loop won't end until
we are able to figure out whether the all nodes are 
traversed and the we have found the Nth node as well.

since we need to traverse all the nodes figure out 
the global minimum then it must be a DP problem
*/
class Solution{
public:
vector<pair<int,int>> adj[100005];
int vis[100005];
int ans = INT_MAX;
	void dfs(int u){
		vis[u]=1;
		for(auto t:adj[u]){
			if(!vis[t.first]){
				dfs(t.first);
			}
		}
	}
	int minScore(int n, vector<vector<int>>&roads){
		for(auto x:roads){
			adj[x[0]].push_back({x[1],x[2]});
			adj[x[1]].push_back({x[0],x[2]});
		}
		dfs(1);
		for(int i=1; i<=n; i++){
			//nodes that are enable to reach 
			//cannot reach
			if(!vis[i]){
				continue;
			}
			//check the adjeceny matrix 
			for(auto x:adj[i]){
				if(vis[x.first]){
					ans = min(ans, x.second);
				}
			}
		}
		return ans;
	}


};

int main(){
	Solution sol;
	int n = 4;
	vector<vector<int>> roads {{1,2,9},{2,3,6},{2,4,5},{1,4,7}};

	cout<<"Main func "<< 	sol.minScore(n,roads) <<"\n";
	return -1;
}
