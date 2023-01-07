#include <bits/stdc++.h>
using namespace std;

// ------ The code from leetcode ----

// ------ ------------------------ ----
class Solution
{
public:
    // int bfs(vector<int> )
    int countComponents(int n, vector<vector<int>> &edges)
    {
        // create an adj matrix
        vector<vector<int>> adjMat;
        for (int i = 0; i < edges.size(); i++)
        {
            adjMat[edges[i][0]].push_back(edges[i][1]);
            adjMat[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        int ans = 0;
        vector<int> visited(edges.size(), -1);
        for (int i = 0; i < edges.size(); i++)
        {
            q.push(i);
            visited[i] = 0;
            ans++;
            while (!q.empty())
            {
                int node = q.front();

                q.pop();
                for (auto x : adjMat[node])
                {
                    if (visited[x] == -1)
                    {
                        visited[x] = 0;
                        q.push(x);
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    return -1;
}