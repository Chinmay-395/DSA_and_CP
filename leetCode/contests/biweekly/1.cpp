#include <bits/stdc++.h>
using namespace std;

// ------ The code from leetcode ----
class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        for (int i = 0, j = 0; i < nums1.size() || j < nums2.size();)
        {
            if (nums1[i] == nums2[j])
                return nums1[i];

            if (nums1[i] < nums2[j])
            {
                ++i;
                continue;
            }
            else
            {
                ++j;
                continue;
            }
        }
        return -1;
    }
};
// ------ ------------------------ ----
int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 3}, nums2 = {2, 4};
    // cout << "The ans " << sol.getCommon(nums1, nums2) << endl;
    cout << "ans " << 1 / 2 << endl;
    return -1;
}