#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

class Solution
{
public:
	int maxNonDecreasingLength(vector<int> nums1,vector<int>nums2)

	{
		int n = nums1.size();
		vector<vector<int>> dp(n,vector<int>(2,1));
		int ans=1;
		for(int i=1;i<n; i++){
    		if(nums1[i]>=nums1[i-1]){
    			dp[i][0]=max(dp[i][0],1+dp[i-1][0]);            
    		}
            if(nums1[i]>=nums2[i-1]){
                dp[i][0]=max(dp[i][0],1+dp[i-1][1]);            
            }
            if(nums2[i]>=nums1[i-1]){
                dp[i][1]=max(dp[i][1],1+dp[i-1][0]);            
            }
            if(nums2[i]>=nums2[i-1]){
                dp[i][1]=max(dp[i][1],1+dp[i-1][1]);            
            }
            ans = max(ans, dp[i][0]);
            ans = max(ans,dp[i][1]);
		}
		return ans;
	}
    int LongestIncreasingSubseq(int ind, int prev_index, vector<int> arr)
    {

        if (ind == arr.size())
            return 0;

        int pick = 0, notPick;
        if (arr[ind] >= arr[prev_index] || prev_index == -1)
        {
            pick = 1 + LongestIncreasingSubseq(ind + 1, ind, arr);
        }
        notPick = LongestIncreasingSubseq(ind + 1, prev_index, arr);
        return max(pick, notPick);
    }
    int maxNonDecreasingLength1(vector<int> &nums1, vector<int> &nums2, int ind, int prev, vector<vector<int>> &dp)
    {
        if (ind == nums1.size())
            return 0;

        if (dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1];

        int pick = 0, notPick = 0;
        if (nums1[ind] >= nums1[prev] || prev == -1)
        {
            pick = 1 + maxNonDecreasingLength1(nums1, nums2, ind + 1, ind, dp);
        }
        if (nums1[ind] >= nums2[prev] || prev == -1)
        {
            notPick = 1 + maxNonDecreasingLength1(nums1, nums2, ind + 1, ind, dp);
        }
        else
        {
            notPick = 0 + maxNonDecreasingLength1(nums1, nums2, ind + 1, prev, dp);
        }
        return dp[ind][prev + 1] = max(pick, notPick);
    }
    int maxNonDecreasingLength2(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev = ind - 1; prev >= -1; prev--)
            {

                int take = 0, notTake;

                if (nums1[ind] >= nums1[prev] || prev == -1)
                {

                    take = 1 + dp[ind + 1][ind + 1];
                }
                if (nums1[ind] >= nums2[prev] || prev == -1)
                {
                    notTake = 1 + dp[ind + 1][ind + 1];
                }
                else
                {
                    notTake = 0 + dp[ind + 1][prev + 1];
                }

                dp[ind][prev + 1] = max(notTake, take);
            }
        }

        return dp[0][0];
    }
};

int main()
{

    Solution obj;

    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums1 = {2, 3, 1}, nums2 = {1, 2, 1}, nums3 = {1, 3, 2, 1}, nums4 = {2, 2, 3, 4};
    // cout << "The length of the longest increasing subsequence is " << obj.LongestIncreasingSubseq(0, -1, arr);
    int n = nums1.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    int x = obj.maxNonDecreasingLength1(nums1, nums2, 0, -1, dp);
    vector<vector<int>> dp_(n, vector<int>(n + 1, -1));
    int y = obj.maxNonDecreasingLength1(nums2, nums1, 0, -1, dp_);

    cout << "The x and y\t " << x << "\t" << y << " The max of non-decreasing length 1st ans " << obj.maxNonDecreasingLength2(nums1, nums2) << endl;
    // int n1 = nums3.size();
    // vector<vector<int>> dp1(n1, vector<int>(n1 + 1, -1));
    // int x1 = obj.maxNonDecreasingLength1(nums3, nums4, 0, -1, dp1);
    // vector<vector<int>> dp1_(n1, vector<int>(n1 + 1, -1));
    // int y1 = obj.maxNonDecreasingLength1(nums4, nums3, 0, -1, dp1_);
    // cout << "The max of non-decreasing length 2st ans " << max(x1, y1) << endl;

    return 0;
}
