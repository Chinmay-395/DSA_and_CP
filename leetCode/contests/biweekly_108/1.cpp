#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
class Solution
{
public:
    int alternatingSubarray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> cheArr;
        for (int i = 0; i < n - 1; i++)
        {
            cheArr.push_back(nums[i + 1] - nums[i]);
        }
        int curr = 0, next = 1;
        while ((cheArr[curr] == cheArr[next]) && cheArr.size() != curr)
        {
            curr++;
            next++;
        }
        if (curr == cheArr.size())
            return -1;
        int maxCount = INT_MIN, cnt = 1;
        for (int i = curr; i < cheArr.size(); i++)
        {
            if (cheArr[curr] + cheArr[next] == 0)
            {
                cnt++;
            }
            else
            {
                cnt = max(maxCount, cnt);
            }
        }
        if (cnt == 1)
            return 2;
        return cnt;
    }
};

int main()
{
    vector<int> nums = {4, 5, 6};
    vector<int> nums2 = {2, 3, 4, 3, 4};
    Solution obj;
    cout << "The ans " << obj.alternatingSubarray(nums) << endl;
    cout << "The ans " << obj.alternatingSubarray(nums2) << endl;
    return 0;
}