#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int helper(int i, int j1, int j2, vector<vector<int>> &grid)
    {
        if (j1 < 0 || j2 < 0 || j1 >= grid[0].size() || j2 >= grid[0].size())
        {
            return -1e9;
        }
        if (i == grid.size() - 1)
        {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        int maxi = INT_MIN, ans;
        for (int di = -1; di <= 1; di++)
        {
            for (int dj = -1; dj <= 1; dj++)
            {
                if (j1 == j2)
                {
                    ans = grid[i][j1] + helper(i + 1, j1 + di, j2 + dj, grid);
                }
                else
                {
                    ans = grid[i][j1] + grid[i][j2] + helper(i + 1, j1 + di, j2 + dj, grid);
                }
                maxi = max(maxi, ans);
            }
        }
        return maxi;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        return helper(0, 0, grid[0].size() - 1, grid);
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> grid = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
    cout << "The ANS " << sol.cherryPickup(grid) << endl;
    return -1;
}
