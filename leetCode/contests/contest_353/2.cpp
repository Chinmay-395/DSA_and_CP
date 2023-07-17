#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
class Solution
{
public:
    int maximumJumps(vector<int> &nums, int target)
    {
    	int ans = 0;
	int n = nums.size();
	vector<int> dp(n,-1);
	dp[0]=0;

	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(abs(nums[i]-nums[j])<=target && dp[j] != -1){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	return dp[n-1];
    }
};

int main()
{
    Solution obj;
    vector<int> arr1 = {1, 3, 6, 4, 1, 2};
    cout << "the OP \t " << obj.maximumJumps(arr1, 2) << endl;
    cout << "the OP \t " << obj.maximumJumps(arr1, 3) << endl;
    cout << "the OP \t " << obj.maximumJumps(arr1, 0) << endl;
    return -1;
}
