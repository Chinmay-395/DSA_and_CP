#include <bits/stdc++.h>
using namespace std;

vector <int> adj[5];
vector<int> visited;
vector<int> result;

class Solution
{
protected:
public:
	// vector<int> visited(V,-1);

	void dfs(int V)
	{
		visited[V] = 0;
		result.push_back(V);
		for (auto x : adj[V])
		{
			if (visited[x] == -1)
				dfs(x);
		}
	}
	void addEdges(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void printEdges()
	{
		for (auto x : result)
		{
			cout << x << " ";
		}
		cout << endl;
	}
};

int main()
{
	Solution Sol;
	Sol.addEdges(0, 1);
	Sol.addEdges(0, 2);
	Sol.addEdges(0, 3);
	Sol.addEdges(2, 4);
	int x = 5;
	while (x >= 0)
	{
		visited.push_back(-1);
		x--;
	}
	Sol.dfs(0);
	Sol.printEdges();
	return 0;
}
