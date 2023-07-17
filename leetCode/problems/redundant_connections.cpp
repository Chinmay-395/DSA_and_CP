#include <bits/stdc++.h>
using namespace std;

unordered_set<int> cycle; // will store all nodes of cycle
int cycleStart = -1;      // used to mark start node of cycle
void dfs(vector<vector<int>> &graph, vector<bool> &vis, int cur, int par = -1)
{
    if (vis[cur])
    {
        cycleStart = cur;
        return;
    }                // reached an visited node - mark it as start of cycle and return
    vis[cur] = true; // not visited earlier - mark it as visited
    for (auto child : graph[cur])
    { // iterate over child / adjacents of current node
        if (child == par)
            continue; // dont visit parent again - avoids back-and-forth loop
        if (cycle.empty())
            dfs(graph, vis, child, cur); // cycle not yet detected - explore graph further with dfs
        if (cycleStart != -1)
            cycle.insert(cur); // cycle detected - keep pushing nodes till we reach start of the cycle
        if (cur == cycleStart)
        {
            cycleStart = -1;
            return;
        } // all nodes of cycle taken - now just return
    }
}
vector<int> findRedundantConnection(vector<vector<int>> &e)
{
    int n = e.size();
    vector<vector<int>> graph(n + 1);
    vector<bool> vis(n + 1);
    // constructing the graph from the edges
    for (auto &edge : e)
        graph[edge[0]].push_back(edge[1]), graph[edge[1]].push_back(edge[0]);
    dfs(graph, vis, 1, -1); // dfs traveral to detect cycle and fill the those nodes in cycle set.
    for (int i = n - 1; ~i; i--)
        if (cycle.count(e[i][0]) && cycle.count(e[i][1]))
            return e[i]; // last edge of input having both nodes in cycle
    return {};           // un-reachable
}

int main()
{
    vector<vector<int>> grid = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    vector<int> ans = findRedundantConnection(grid);
    cout << "The Answer: " << ans[0] << " " << ans[1] << endl;
    return -1;
}