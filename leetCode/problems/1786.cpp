#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> dijkstra(int V, vector<pair<int, int>> adj[], int S)
    {
        // Create a set ds for storing the nodes as a pair {dist,node}
        // where dist is the distance from source to the node.
        // set stores the nodes in ascending order of the distances
        set<pair<int, int>> st;

        // Initialising dist list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> dist(V, 1e9);

        st.insert({0, S});

        // Source initialised with dist=0
        dist[S] = 0;

        // Now, erase the minimum distance node first from the set
        // and traverse for all its adjacent nodes.
        while (!st.empty())
        {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            // Check for all adjacent nodes of the erased
            // element whether the prev dist is larger than current or not.
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edgW = it.second;

                if (dis + edgW < dist[adjNode])
                {
                    // erase if it was visited previously at
                    // a greater cost.
                    if (dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});

                    // If current distance is smaller,
                    // push it into the queue
                    dist[adjNode] = dis + edgW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        // Return the list containing shortest distances
        // from source to all the nodes.
        return dist;
    }
    vector<int> bfsOfGraph(int V, vector<pair<int, int>> adj[], vector<int> res, int count)
    {
        // int vis[V] = {0};
        vector<int> vis(V, 0);
        vis[0] = 1;
        queue<pair<int, int>> q;
        // push the initial starting node
        q.push({0, 0});
        vector<int> bfs;
        // iterate till the queue is empty
        while (!q.empty())
        {
            // get the topmost element in the queue
            auto node = q.front();
            q.pop();
            bfs.push_back(node.first);
            // traverse for all its neighbours
            for (auto it : adj[node.first])
            {
                // if the neighbour has previously not been visited,
                // store in Q and mark as visited
                if (!vis[it.first] && res[node.first] > res[it.first])
                {
                    vis[it.first] = 1;
                    count++;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
    int countRestrictedPaths(int n, vector<vector<int>> &edges)
    {
        /*
        get shortest path to nth node from all nodes
        then arrange store the pair of (node,shortest_distance)
        [1,4]
        [2,2]
        [3,1]
        [4,6]
        [5,0]

        perform BFS from 1st node to Nth node
            criteria for next bfs node should be the shortest_distance of node i > shortest_distance of node i+1

        count the number of BFSs performed and return it.

        TC: O(V) x O( E log(V) ) + O(V)
        */
        vector<pair<int, int>> adj[n];
        for (auto edge : edges)
        {
            // Assuming edge[0] is the source, edge[1] is the destination, and edge[2] is the weight
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<int> res = dijkstra(n, adj, 0);

        // BFS
        int bfs_count = 0;
        vector<int> ans = bfsOfGraph(0, adj, res, bfs_count);
        return bfs_count;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {
        {1, 2, 3},
        {1, 3, 3},
        {2, 3, 1},
        {1, 4, 2},
        {5, 2, 2},
        {3, 5, 1},
        {5, 4, 10}};
    int ans = sol.countRestrictedPaths(n, edges);
    cout << "\n THE ANS \t" << ans;
}