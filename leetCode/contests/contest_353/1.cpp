#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
class Solution
{
public:
    int theMaximumAchievableX(int num, int t)
    {
        int theNewNum1 = num + t;
        int theNewNum2 = num - t;
        int theFinal11 = theNewNum1 + t;
        int theFinal12 = theNewNum1 - t;
        int theFinal21 = theNewNum2 + t;
        int theFinal22 = theNewNum2 - t;
        // int theFinalNum = max(max(theNewNum1 + 1, theNewNum1 - 1), max(theNewNum2 + 1, theNewNum2 - 1));
        // return theFinalNum;
        return max(max(theFinal11, theFinal12), max(theFinal21, theFinal22));
    }
};
int main()
{
    Solution obj;
    cout << "the OP \t " << obj.theMaximumAchievableX(4, 1) << endl;
    cout << "the OP \t " << obj.theMaximumAchievableX(3, 2) << endl;
    return -1;
}
