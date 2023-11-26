#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        auto max_element1 = std::max_element(nums1.begin(), nums1.end());
        auto max_element2 = std::max_element(nums2.begin(), nums2.end());
        if (max_element1 != nums1.end() - 1 || max_element2 != nums2.end() - 1)
        {
            return -1;
        }
        else
        {
            int temp = nums1[n1 - 1];
            nums1[n1 - 1] = nums2[n1 - 1];
            nums2[n1 - 1] = temp;
        }

        auto max_element1 = std::max_element(nums1.begin(), nums1.end());
        auto max_element2 = std::max_element(nums2.begin(), nums2.end());
        for (int i = n1 - 2; i > 0; i++)
        {
            if ()
        }
    }
};
