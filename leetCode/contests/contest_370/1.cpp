/*
[
  0 1
0[0,1],
1[0,0]
]

[
  0 1 2
0 [0,0,1], -> 1
1 [1,0,1], -> 2
2 [0,0,0]  -> 0

]
  0  1  2
0 [1,0,1],
1 [1,0,1],
2 [0,0,0]


*/
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// /*
// [
// [0,0,1],[1,0,1],[0,0,0]]
// */
// class Solution
// {
// public:
//     int up_r_tri, lo_l_tri = 0;
//     int findChampion(vector<vector<int>> &grid)
//     {
//         // for(int i=0; i<grid.size(); i++){
//         //     for(int j=0; j<grid[0].size(); j++){
//         //         if(i == j) continue;
//         //         if(j>i && grid[i][j]==1) up_r_tri++;
//         //         if(i>j && grid[i][j]==1) lo_l_tri++;
//         //     }
//         // }

//         int curr = -1, maxVal = INT_MIN;
//         int i;
//         for (i = 0; i < grid.size(); i++)
//         {
//             int total = accumulate(grid[i].begin(), grid[i].end(), 0);
//             if (total > maxVal)
//             {
//                 maxVal = total;
//                 curr = i;
//             }
//         }
//         return curr;
//     }
// };
class Solution
{
public:
    void dfs(unordered_map<int, vector<int>> &graph,
             int node,
             vector<bool> &visited,
             int &count,
             set<int> &winners,
             int parent,
             int n)
    {

        visited[node] = true;
        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                count++;
                dfs(graph, neighbor, visited, count, winners, parent, n);
            }
        }
    }
    int findChampion(int n, vector<vector<int>> &edges)
    {
        set<int> winner_ans;
        unordered_map<int, vector<int>> hmap;
        for (int i = 0; i < edges.size(); i++)
        {
            hmap[edges[i][0]].push_back(edges[i][1]);
        }
        vector<bool> vis(n, 0);
        int x = 0;
        for (int i = 0; i < n; i++)
        {

            if (!vis[i])
            {
                dfs(hmap, i, vis, x, winner_ans, i, n);
                cout << "THE count " << x << " the parent " << i << " THE n " << n << endl;

                if (x == n - 1)
                {

                    winner_ans.insert(edges[i][0]);
                }
            }
        }

        if (winner_ans.size() != 1)
            return -1;
        else
            return *winner_ans.begin();
    }
};
int main()
{
    Solution sol;
    vector<std::vector<int>> some_val = {{0, 1},
                                         {1, 2}};

    vector<std::vector<int>> some_val2 = {{0, 2},
                                          {1, 3},
                                          {1, 2}};
    vector<vector<int>> some3 = {{1, 0}};
    int x = sol.findChampion(3, some_val);
    cout << "THE ROUND 2 \n \n";
    int y = sol.findChampion(4, some_val2);
    cout << "THE ROUND 2 \n \n";
    int z = sol.findChampion(2, some3);
    cout << "w " << x << endl;
    cout << "w " << y << endl;
    cout << "w " << z << endl;
}