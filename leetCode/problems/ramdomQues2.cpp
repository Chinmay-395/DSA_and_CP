#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

static bool comp(vector<int> trip1, vector<int> trip2)
{
    return trip1[1] < trip2[1];
}

struct compPQ
{
    bool operator()(vector<int> trip1, vector<int> trip2)
    {
        if (trip1[2] == trip2[2])
            return trip1[1] > trip2[1];
        return trip1[2] > trip2[2];
    }
};

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int n = trips.size();
        if (n == 0)
            return false;
        sort(trips.begin(), trips.end(), comp);
        priority_queue<vector<int>, vector<vector<int>>, compPQ> pq;
        pq.push(trips[0]);
        capacity -= trips[0][0];
        if (capacity < 0)
            return false;
        for (int i = 1; i < n; i++)
        {
            capacity -= trips[i][0];
            auto topEl = pq.top();
            if (trips[i][1] >= topEl[2])
            {
                while (!pq.empty() && trips[i][1] >= topEl[2])
                {
                    // cout<<topEl[0]<<"\n";
                    capacity += topEl[0];
                    pq.pop();
                    if (!pq.empty())
                        topEl = pq.top();
                }
            }
            if (capacity < 0)
                return false;
            pq.push(trips[i]);
        }
        return true;
    }
};