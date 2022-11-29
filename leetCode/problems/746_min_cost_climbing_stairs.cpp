#include <bits/stdc++.h>
using namespace std;
/*
cost = [1,100,1,1,1,100,1,1,100,1]
dp   = [1,    1,  1     1,1,    1]
                        1
                    1/   2\
                    100     1
                    /  \   /  \
                  1    1  1    1
                /  \
                1
              / \
             1
         /    \
        100   dpMin🔴
      /  \
    1🔴     dpMin🟡
    /  \
  1🟡     dpMin🟠
  /  \
100🟠  1
/
1


 */
// ------ The code from leetcode ----
class Solution
{
public:
    int dpHelper(vector<int> &cost, int ind)
    {
        int jumpOne, jumpTwo;
        if (ind == 0)
            return 0;
        jumpOne = dpHelper(cost, ind - 1) + abs(cost[ind] - cost[ind - 1]);
        if (ind > 1)
        {
            jumpTwo = dpHelper(cost, ind - 2) + abs(cost[ind] - cost[ind - 2]);
        }
        return min(jumpOne, jumpTwo);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++)
        {

            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        // cout << "The total cost\t" << dp[n - 1] << endl;
        return min(dp[n - 1], dp[n - 2]);
    }
};
// ------ ------------------------ ----
int main()
{
    Solution sol;
    vector<int> cost{10, 15, 20};
    cout << "The OP " << sol.minCostClimbingStairs(cost);
    return -1;
}