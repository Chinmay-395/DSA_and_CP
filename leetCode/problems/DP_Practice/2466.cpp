class Solution
{
public:
    int mod = 1e9 + 7;
    int dfs(int length, int low, int high, int zero, int one, vector<int> &dp)
    {
        if (length > high)
            return 0;
        if (dp[length] != -1)
            return dp[length];
        int res = length >= low ? 1 : 0;
        int appending_zeros = dfs(length + zero, low, high, zero, one, dp);
        int appending_ones = dfs(length + one, low, high, zero, one, dp);
        return dp[length] = (res + appending_zeros + appending_ones) % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one)
    {
        /*
            the trick to this problem is that, it is not asking us to compute all the strings
            Check the first attempt of this question wherein the strings are computed.
            NOTE: all the strings generated will be unqiue

            compute the length of the string which will increase by the length of "zero" or "one"

        */
        vector<int> dp(high + 1, -1);
        return dfs(0, low, high, zero, one, dp);
    }
};