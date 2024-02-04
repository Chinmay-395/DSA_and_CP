#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

class Solution
{
public:
    // long long max(long long a,long long b){

    //     return a>b?a:b;
    // }
    vector<vector<long long>> dp;

    long long maxPoints(vector<vector<int>> &points)
    {

        int m = points.size(), n = points[0].size();
        vector<long long> prev(n);
        for (int i = 0; i < n; i++)
        {
            prev[i] = points[0][i];
        }

        for (int i = 0; i < m - 1; i++)
        {

            vector<long long> prefixMax(n, 0), suffixMax(n, 0), curr(n, 0);

            prefixMax[0] = prev[0];

            for (int j = 1; j < n; j++)
            {
                prefixMax[j] = max(prefixMax[j - 1] - 1, prev[j]);
            }

            suffixMax[n - 1] = prev[n - 1];

            for (int j = n - 2; j >= 0; j--)
            {
                suffixMax[j] = max(suffixMax[j + 1] - 1, prev[j]);
            }

            for (int j = 0; j < n; j++)
            {
                curr[j] = points[i + 1][j] + max(prefixMax[j], suffixMax[j]);
            }

            prev = curr;
        }

        long long ans = 0;
        for (auto x : prev)
        {
            ans = max(ans, x);
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> points = {{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};
    Solution sol;
    int ans = sol.maxPoints(points);
    cout << "THE ANS " << ans;
}