
// Unique path 3

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> grid, int x, int y, int zero)
{
    // Base Condition
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1)
    {
        return 0;
    }
    if (grid[x][y] == 2)
    {
        return zero == -1 ? 1 : 0; // Why zero = -1, because in above example we have 9 zero's. So, when we reach the final cell we are covering one cell extra then the zero count.
                                   // If that's the case we find the path and return '1' otherwise return '0';
    }
    grid[x][y] = -1; // mark the visited cells as -1;
    zero--;          // and reduce the zero by 1

    int totalPaths = dfs(grid, x + 1, y, zero) + // calculating all the paths available in 4 directions
                     dfs(grid, x - 1, y, zero) +
                     dfs(grid, x, y + 1, zero) +
                     dfs(grid, x, y - 1, zero);

    // Let's say if we are not able to count all the paths. Now we use Backtracking over here
    grid[x][y] = 0;
    zero++;

    return totalPaths; // if we get all the paths, simply return it.
}

int dfsMemoized(vector<vector<int>> grid, int x, int y, int zero, vector<vector<int>> &dp)
{
    // Base Condition
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1)
    {
        return 0;
    }
    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    if (grid[x][y] == 2)
    {
        return zero == -1 ? 1 : 0; // Why zero = -1, because in above example we have 9 zero's. So, when we reach the final cell we are covering one cell extra then the zero count.
                                   // If that's the case we find the path and return '1' otherwise return '0';
    }
    grid[x][y] = -1; // mark the visited cells as -1;
    zero--;          // and reduce the zero by 1

    int totalPaths = dfsMemoized(grid, x + 1, y, zero, dp) + // calculating all the paths available in 4 directions
                     dfsMemoized(grid, x - 1, y, zero, dp) +
                     dfsMemoized(grid, x, y + 1, zero, dp) +
                     dfsMemoized(grid, x, y - 1, zero, dp);

    // Let's say if we are not able to count all the paths. Now we use Backtracking over here
    grid[x][y] = 0;
    zero++;

    return dp[x][y] = totalPaths; // if we get all the paths, simply return it.
}
int uniquePathsIII(vector<vector<int>> &grid)
{
    int numberOfFreeWalk = 0, startX = 0, startY = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 0)
            {
                numberOfFreeWalk++;
            }
            else if (grid[i][j] == 1)
            {
                startX = i;
                startY = j;
            }
        }
    }
    int m = 0, n = 0;
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    // int x = uniquePathsHelperMemoized(startX, startY, 0, grid, dp);
    // int x = uniquePathsHelperMemoized(0, 0, 0, grid, dp);
    // int x = dfs(grid, startX, startY, numberOfFreeWalk);
    int x = dfsMemoized(grid, startX, startY, numberOfFreeWalk, dp);
    return x;
}
int main()
{
    vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
    cout << "The Answer: " << uniquePathsIII(grid) << endl;
    return -1;
}