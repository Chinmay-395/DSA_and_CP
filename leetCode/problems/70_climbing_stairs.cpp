#include <bits/stdc++.h>
using namespace std;
/* notes

n=2
1. 1  + 1
2. 2
---------------------
n=3
1. 1  + 1  + 1
2. 1  + 2
3. 2  + 1
---------------------
n=7
1. 1 + 1 + 1 + 1 + 1 + 1 + 1
2. 1 + 1 + 1 + 1 + 1 + 2
3. 1 + 1 + 1 + 2 + 2
4. 1 + 2 + 2 + 2
5. 2 + 2 + 2 + 1
6. 2 + 2 + 1 + 1 + 1
7. 2 + 1 + 1 + 1 + 1 + 1

the solution can either end in 1 step or 2 steps
if there are less than two steps then only 1 step can be climbed
if the remaining steps get to zero then return the count the total ways
---*******************************************************************---
memoization method

previousStep is a vector which will store whatever the step that have been accounted.

n=4

      4
    /   \
    3   2
   / \
  2  1
 /\
1 0

n=3
dp=[-1,-1,-1]

iteration 0:
dp[3-1] =





*/
class Solution
{
public:
    int climbStairsHelper(int n, vector<int> &dp)
    {

        if (n == 0 || n == 1)
            dp[n - 1] = 1;
        if (dp[n - 1] != -1)
            return dp[n - 1];
        return dp[n - 1] = climbStairsHelper(n - 1, dp) + climbStairsHelper(n - 2, dp);
    }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
        // return previousStep[n - 1];
    }
};
int main()
{
    Solution sol;
    cout << "The OP " << sol.climbStairs(45) << endl;
    return -1;
}
// 1836311903