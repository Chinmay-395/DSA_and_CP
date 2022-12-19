// Coding Ninja Problems
#include <bits/stdc++.h>
using namespace std;

/*

    0 1 2
  0 * * *
  1     *
  2     *

    0 1 2
  0 *
  1 *
  2 * * *

    0 1 2
  0 *
  1 * *
  2   * *

                      f(2,2)
        /                       \
      f(1,2)                       f(2,1)
      /      \                /             \
f(0,2)     f(1,1)           f(1,1)         f(2,0)
|           /   \           /    \          |
f(0,1)   f(0,1) f(1,0)    f(0,1) f(1,0)    f(1,0)
|         |       |        |       |        |
f(0,0)   f(0,0)   f(0,0)  f(0,0)   f(0,0)  f(0,0)

*/
int uniquePathsHelper(int m, int n, int count) // m=2 & n=2
{
    // Write your code here.
    if (m == 0 && n == 0)
    {
        return count + 1;
    }
    if (m == 0 && n > 0)
    {
        return uniquePathsHelper(m, n - 1, count);
    }
    if (n == 0 && m > 0)
    {
        return uniquePathsHelper(m - 1, n, count);
    }
    int left = uniquePathsHelper(m - 1, n, count);
    int right = uniquePathsHelper(m, n - 1, count);
    return count = left + right;
}

int uniquePathsHelperMemoized(int m, int n, int count, vector<vector<int>> &dp)
{
    // Write your code here.
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    if (m == 0 && n == 0)
    {
        return count + 1;
    }
    if (m == 0 && n > 0)
    {
        return uniquePathsHelperMemoized(m, n - 1, count, dp);
    }
    if (n == 0 && m > 0)
    {
        return uniquePathsHelperMemoized(m - 1, n, count, dp);
    }
    int left = uniquePathsHelperMemoized(m - 1, n, count, dp);
    int right = uniquePathsHelperMemoized(m, n - 1, count, dp);
    return dp[m][n] = left + right;
}
int main()
{
    int m, n;
    cout << "The Unique path problem" << endl;
    cout << "Enter two digits to get the input for columns and rows" << endl;
    cin >> m >> n;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << "The ouput for unique path: " << uniquePathsHelper(m - 1, n - 1, 0) << endl;
    cout << "The ouput for unique path: " << uniquePathsHelperMemoized(m - 1, n - 1, 0, dp) << endl;
    return -1;
}