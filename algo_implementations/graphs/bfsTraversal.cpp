#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
	//BFS traversal
	/*
	visited array
	answer to store the traversal
	queue data structure 
	adjeceny matrix 
	*/
	
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> visited(V,-1);
        vector<int> ans;
        queue<int> q;
        q.push(0);
        //visited[0]=0;
        while(!q.empty()){
        	int node = q.front();
        	q.pop();
        	ans.push_back(node);
        	for(auto x: adj[node]){
		      	if(visited[x]==-1){
		      		visited[x]=0;
		      		q.push(x);
		      	}
        	}
        	visited[node]=0;

        }
        return ans;
    }
};

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> adj[5];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 4);

    Solution obj;
    vector<int> ans = obj.bfsOfGraph(5, adj);
    printAns(ans);


    return 0;
}
