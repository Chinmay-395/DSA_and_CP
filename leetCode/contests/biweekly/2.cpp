#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long minOperations(vector<int> &nums1, vector<int> &nums2, int k)
    {
        /*
            4 | 1 | 3%4 --> 1 --> 1
            3 | 3 | 3=3 --> 3 --> 0
            1 | 7 | 7%3 --> 1 --> 2
            4 | 1 | 4%3 --> 1 --> 1

            -------------------------
            4 | 1 | (4-1)/3 --> 1 --> 1
            3 | 3 | (3-3)/3 --> 0 --> 0
            1 | 7 | (7-1)/3 --> 2 --> 2
            4 | 1 | (4-1)/3 --> 1 --> 1
            num,freq
            <1,2>  2
            <2,1>  3/2=0

        */
        long long ans = 0;

        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] == nums2[i])
            {
                // ans.push_back(0);
                ans = ans;
            }
            else if (nums1[i] > nums2[i])
            {
                if (nums1[i] % k == nums2[i])
                {
                    int temp = (nums1[i] - nums2[i]) / k;
                    if (temp > 1 && ans > 0)
                    {
                        ans = ans + temp - 1;
                    }
                    else
                    {
                        ++ans;
                    }
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                if (nums2[i] % k == nums1[i])
                {
                    int temp = nums2[i] / k;
                    if (temp > 1 && ans > 0)
                    {
                        ans = ans + temp - 1;
                    }
                    else
                    {
                        ++ans;
                    }
                }
                else
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> nums1 = {4, 3, 1, 4}, nums2 = {1, 3, 7, 1};
    int k = 3;
    cout << "The ans " << sol.minOperations(nums1, nums2, k) << endl;
    return -1;
}
/*
[15,10,5,20]

[5,10,15,4]

k = 5


[2,]
*/