//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool detect(int startNode, vector<int> &visited, vector<int> adj[])
    {
        queue<pair<int, int>> Q;
        Q.push({startNode, -1}); // it's the starting node it has no parent
        visited[startNode] = 1;
        while (!Q.empty())
        {
            int node = Q.front().first;
            int parent = Q.front().second;
            Q.pop();
            for (auto x : adj[node])
            {
                if (visited[x] == 0)
                {
                    visited[x] = 1;

                    Q.push({x, node});
                }
                else if (parent != x)
                {
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                if (detect(i, visited, adj) == true)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool detect(int startNode, vector<int> &visited, vector<int> adj[])
    {
        queue<pair<int, int>> Q;
        Q.push({startNode, -1}); // it's the starting node it has no parent
        visited[startNode] = 1;
        while (!Q.empty())
        {
            int node = Q.front().first;
            int parent = Q.front().second;
            Q.pop();
            for (auto x : adj[node])
            {
                if (visited[x] == 0)
                {
                    visited[x] = 1;

                    Q.push({x, node});
                }
                else if (parent != x)
                {
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                if (detect(i, visited, adj) == true)
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends