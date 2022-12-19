#include <bits/stdc++.h>
using namespace std;
// int pick = 0, notPick = 0;
int func(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int pick = nums[ind] + func(ind - 2, nums, dp);
    int notPick = 0 + func(ind - 1, nums, dp);
    return dp[ind] = max(pick, notPick);
}
int main()
{
    // Creating the array
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    int N = arr.size();
    vector<int> dp(N, -1);
    // 61834
    //  Function call
    cout << func(N - 1, arr, dp) << endl;
    return 0;
}