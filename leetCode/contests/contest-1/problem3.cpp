class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        long dp[n + 1];
        long mod = (long)1e9 + 7;
        long noOfPeopleSharingSecret = 0;
        long ans = 0;

        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            long noOfNewPeopleSharingSecret = dp[max(i - delay, 0)];
            long noOfPeopleForgetingSecret = dp[max(i - forget, 0)];
            noOfPeopleSharingSecret += (noOfNewPeopleSharingSecret - noOfPeopleForgetingSecret + mod) % mod;
            dp[i] = noOfPeopleSharingSecret;
        }
        for (int i = n - forget + 1; i <= n; i++)
        {
            ans = (ans + dp[i]) % mod;
        }
        return (int)ans;
    }
};