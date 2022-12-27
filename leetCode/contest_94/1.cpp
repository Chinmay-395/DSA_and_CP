#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxVal = 0;
    void travelInBothDirect(vector<int> forts, int ind)
    {
        vector<int> vec = forts;
        int countL = 0;
        int localMax = 0;
        // moving from left to right
        for (int i = ind + 1; i < vec.size(); i++)
        {
            if (vec[i] == 0)
            {
                vec[i] = 1;
                countL++;
            }
            else
            {
                break;
            }
        }
        localMax = max(countL, localMax);
        // moving from right to left
        int countR = 0;
        for (int i = ind - 1; i > -1; i--)
        {
            if (vec[i] == 0)
            {
                vec[i] = 1;
                countR++;
            }
            else
            {
                break;
            }
        }
        localMax = max(localMax, countR);
        maxVal = max(localMax, maxVal);
    }
    int captureForts(vector<int> &forts)
    {

        for (int i = 0; i < forts.size(); i++)
        {
            if (forts[i] == 1)
            {
                travelInBothDirect(forts, i);
            }
        }
        return maxVal;
    }
};

int main()
{
    Solution sol;
    // vector<vector<int>> grid{{1, 2, 4}, {3, 3, 1}, {7, 8, 9}};
    vector<int> grid{-1, 0, -1, 0, 1, 1, 1, -1, -1, -1};
    cout << " " << sol.captureForts(grid) << endl;
    return -1;
}
/*
[ -1, 0, -1, 0, 1, 1, 1, -1, -1, -1 ]
1
*/