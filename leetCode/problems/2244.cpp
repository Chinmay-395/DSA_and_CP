#include <bits/stdc++.h>
using namespace std;
/*
Hash Table
-------------------------------------
[2,2,3,3,2,4,4,4,4,4]

{2:3,3:2,4:5,5:10}

 2 2 3 3

since the hashmap has a value that cannot be divisible 2/3/5
*/
// ------ The code from leetcode ----
class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        map<int, int> hm;
        for (int i = 0; i < tasks.size(); i++)
        {
            hm[tasks[i]]++;
        }
        int num, freq, ans = 0;
        for (auto i : hm)
        {
            freq = i.second;
            if (freq == 1)
                return -1;
            if (freq % 3 == 0)
            {
                ans += freq / 3;
            }
            else
            {
                ans += freq / 3 + 1;
            }
        }
        return ans;
    }
};
// ------ ------------------------ ----
int main()
{
    Solution sol;
    vector<int> input = {69, 65, 62, 64, 70, 68, 69, 67, 60, 65, 69, 62, 65, 65, 61, 66, 68, 61, 65, 63, 60, 66, 68, 66, 67, 65, 63, 65, 70, 69, 70, 62, 68, 70, 60, 68, 65, 61, 64, 65, 63, 62, 62, 62, 67, 62, 62, 61, 66, 69};
    // vector<int> input2 = {2, 3, 3};
    // vector<int> input3 = {2, 2, 3, 3, 2, 4, 4, 4, 4, 4};
    // vector<int> input4 = {2, 2, 3, 3, 2, 4, 4, 4, 4, 4, 5};
    vector<int> input5 = {2, 2, 3, 3, 2, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    std::cout << "\n The OP \t " << sol.minimumRounds(input) << endl;
    // std::cout << "\n The OP \t " << sol.minimumRounds(input2) << endl;
    // std::cout << "\n The OP \t " << sol.minimumRounds(input3) << endl;
    // std::cout << "\n The OP \t " << sol.minimumRounds(input4) << endl;
    std::cout << "\n The OP \t " << sol.minimumRounds(input5) << endl;
    return -1;
}