#include <bits/stdc++.h>
using namespace std;
/*
[4, 3, 6, 16, 8, 2]

sorting
[2,3,4,6,8,16]
initially len=1
when i=0 check nums[i]^2 exists
    if true then len=2 and check whether nums[i]^2 exists in the array
        do this till you reach the end of vector. and store the maximum value of the same.

i=0:
    nums[0] -> 2
    check if 2^2=4 exists in the nums array
        since it does exists len=2
    checking if 4^2=16 exists in the nums array
        since it does exists len=3
    checking if 16^2 exists in the nums array
        since it does not then storing the max as 3

i=1
    nums[1] -> 3
    checking if 3^2=9 exists in the nums array
    since it doesn't moving to the next
i=2
    nums[2] -> 4
    checking if 4^2=16 exists in the nums array
        since it does exists len=2
    checking if 16^2 exists in the nums array
        since it does not then storing the max = max(2,3) -> 3

i=3
    nums[3]->6
    checking if 6^2=36 exits in the nums array
        since it doesn't moving to the next
i=4
    nums[4]->8
    checking if 8^2=64 exits in the nums array
        since it doesn't moving to the next
i=5
    nums[5]->16
    checking if 16^2=256 exits in the nums array
        since it doesn't moving to the next

end of array return max
*/
class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {

        int ans = -1;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            long long x = 1ll * nums[i];
            long long pwr = x * x;

            if (binary_search(nums.begin(), nums.end(), pwr))
            {
                int len = 1;
                while (binary_search(nums.begin(), nums.end(), pwr))
                {
                    len++;
                    pwr = pwr * pwr;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    // vector<vector<int>> grid{{1, 2, 4}, {3, 3, 1}, {7, 8, 9}};
    vector<int> grid{4, 3, 6, 16, 8, 2};
    cout << " " << sol.longestSquareStreak(grid) << endl;
    return -1;
}