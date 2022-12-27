#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        int sum = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            // sort every array
            sort(grid[i].begin(), grid[i].end());
        }
        // int z;
        int maxm;
        for (int i = 0; i < grid[0].size(); i++)
        {
            maxm = INT_MIN;
            grid[0][i];
            // Run the inner loop for rows
            for (int j = 0; j < grid.size(); j++)
            {
                // check if any element is greater
                // than the maximum element
                // of the column and replace it
                // if (grid[j][i] > maxm)
                // maxm = grid[j][i];
                maxm = max(maxm, grid[j][i]);
            }

            // print the largest element of the column
            sum = sum + maxm;
        }
        return sum;
    }
};
int main()
{
    Solution sol;
    // vector<vector<int>> grid{{1, 2, 4}, {3, 3, 1}, {7, 8, 9}};
    vector<vector<int>> grid{{10}};
    cout << " " << sol.deleteGreatestValue(grid) << endl;
    return -1;
}