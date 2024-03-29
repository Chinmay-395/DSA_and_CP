#include <bits/stdc++.h>
using namespace std;
class Allocator
{
public:
    vector<int> memory;
    int sz;
    unordered_map<int, vector<int>> mp;
    Allocator(int n)
    {
        memory.resize(n);
        sz = n;
    }

    int allocate(int size, int mID)
    {
        int free = 0, idx;
        for (int i = 0; i < sz; i++)
        {
            if (free == 0)
                idx = i;
            if (memory[i] == 0)
                free++;
            else
                free = 0;

            if (free >= size)
                break;
        }

        if (free >= size)
        {
            for (int i = idx; i < idx + size; i++)
            {
                memory[i] = mID;
                mp[mID].push_back(i);
            }
        }

        return free >= size ? idx : -1;
    }

    int free(int mID)
    {
        int count = 0;
        for (auto it : mp[mID])
        {
            memory[it] = 0;
            count++;
        }

        mp.erase(mID);
        return count;
    }
};