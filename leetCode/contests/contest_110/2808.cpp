#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    int minimumSeconds(vector<int> &nums)
    {
        // find unique number an it's respective location in a adjecency matrix

        // create the adjeceny matrix
        unordered_map<int, vector<int>> adj_map;
        int index = 0;
        for (auto num : nums)
        {
            if (adj_map.find(num) == adj_map.end())
            { // didn't found
                // store the location of a new number
                adj_map[num].push_back(index);
            }
            else
            { // the number exists in the hash-map
                adj_map[num].push_back(index);
            }

            index++;
        }
        int ans = INT_MAX;
        // now we check how many elements exists between these numbers
        for (auto each_key_val : adj_map)
        {
            vector<int> locations = each_key_val.second;
            int start_loc = locations[0];
            int end_loc = locations[locations.size() - 1];
            int curr_max = (start_loc + end_loc + 1) / 2;
            for (int i = 1; i < locations.size(); i++)
            {
                curr_max = max(curr_max, (locations[i] - locations[i - 1]) / 2);
            }
            ans = min(ans, curr_max);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
}