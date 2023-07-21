#include <bits/stdc++.h>
using namespace std;
/*

*/
int uniquePathsHelper2(
    int m,
    int n,
    vector<vector<int>> &grid,
    vector<vector<int>> &dp)
{
    // Write your code here.
    if (dp[m][n] != -1)
        return dp[m][n];
    if (m == 0 && n == 0)
    {
        return dp[m][n] = grid[m][n];
    }
    if (m == 0 && n > 0)
    {
        return dp[m][n] = grid[m][n] + uniquePathsHelper2(m, n - 1, grid, dp);
    }
    if (n == 0 && m > 0)
    {
        return dp[m][n] = grid[m][n] + uniquePathsHelper2(m - 1, n, grid, dp);
    }
    int up = grid[m][n] + uniquePathsHelper2(m - 1, n, grid, dp);
    int left = grid[m][n] + uniquePathsHelper2(m, n - 1, grid, dp);
    return dp[m][n] = min(up, left);
}
int main()
{
    vector<vector<int>> vect{
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};

    vector<vector<int>> vect2{
        {1, 2, 3},
        {4, 5, 6},
    };
    // cout << "Row's Length: " << vect.size() << endl;
    // cout << "Column's Length: " << vect[0].size() << endl;
    // cout << "The value " << uniquePathsHelper2(vect.size() - 1, vect[0].size() - 1, vect, INT_MAX) << endl;
    vector<vector<int>> dp(vect2.size(), vector<int>(vect2[0].size(), -1));
    cout << "The value " << uniquePathsHelper2(vect2.size() - 1, vect2[0].size() - 1, vect2, dp) << endl;
}
/*
                1
            /       \
            1
        /       \
        1       5
        |
        3
        |
        1
=       7
*/