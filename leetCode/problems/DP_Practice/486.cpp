#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int log2(int n)
{
    return (n == 1) ? 0 : 1 + log2(n / 2);
}

class Solution
{
public:
    int p1Cnt = 0, p2Cnt = 0;
    int rec(vector<int> nums, int p1Total, int p2Total, bool choice, int i)
    {
        if (nums.size() == 0)
        {
            return p1Total return nums[0];
        }
        // pick & not-pick
        // if choice is true then its p1 turn else it is p2 turn

        if (choice)
        {
            // player1
            p1Cnt = max(rec(nums[]))
        }
        else
        {
        }
    }
    bool predictTheWinner(vector<int> &nums)
    {
    }
};