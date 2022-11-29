#include <bits/stdc++.h>
using namespace std;
/*
        4
       /  \

*/
// ------ The code from leetcode ----
class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;
        int prev1, prev2, prev3;
        int sum = 0;
        prev1 = 0;
        prev2 = 1;
        prev3 = 1;

        for (int i = 3; i <= n; i++)
        {
            sum = prev1 + prev2 + prev3;
            prev1 = prev2;
            prev2 = prev3;
            prev3 = sum;
        }
        return sum;
    }
};
// ------ ------------------------ ----
int main()
{
    Solution sol;
    cout << "The OP " << sol.tribonacci(0) << endl;
    cout << "The OP " << sol.tribonacci(2) << endl;
    cout << "The OP " << sol.tribonacci(1) << endl;
    cout << "The OP " << sol.tribonacci(25) << endl;
    return -1;
}