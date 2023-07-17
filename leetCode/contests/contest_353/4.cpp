// #include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void printVec(vector<int> arr)
{
    for (auto x : arr)
    {
        cout << " " << x;
    }
    cout << endl;
}
template <class InputIterator>
void print(InputIterator start, InputIterator end)
{
    for (auto itr = start; itr != end; ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;
}

class Solution
{
public:
    bool checkArray(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);
        long long ac = 0;

        cout << "initially \n ac: " << ac << endl;
        cout << "prefs: ";
        print(begin(pref), end(pref));
        for (int i = 0; i < n; i++)
        {
            ac -= pref[i];
            nums[i] -= ac;

            if (nums[i] < 0)
                return false;
            if (i + k <= n)
            {
                ac += nums[i];
                pref[i + k] += nums[i];
                nums[i] = 0;
            }
            else if (nums[i] > 0)
                return false;
            cout << "i: " << i << endl;
            cout << "\t ac: " << ac << endl;
            cout << "\t nums: ";
            print(begin(nums), end(nums));
            cout << "\t prefs: ";
            print(begin(pref), end(pref));
        }
        return true;
    }
    // Lee's solution
    bool checkArrayLee(vector<int> &A, int k)
    {
        int cur = 0, n = A.size();
        for (int i = 0; i < n; ++i)
        {
            cout << "i: " << i << endl;
            if (cur > A[i])
                return false;
            cout << "\t cur: " << cur << endl;
            A[i] -= cur;

            cur += A[i];
            cout << "\t cur: " << cur << endl;
            if (i >= k - 1)
            {
                cur -= A[i - k + 1];
                cout << "\t cur: " << cur << endl;
            }

            cout << "\t nums: ";
            print(begin(A), end(A));
        }
        return cur == 0;
    }
};

int main()
{
    // printf("Hello World");
    vector<int> arr = {2, 2, 3, 1, 1, 0};
    Solution sol;
    // cout<< "ans "<<checkArray(arr, 3) <<endl;
    bool x = sol.checkArrayLee(arr, 3);
    cout << "\n CheckArray Answer " << x << endl;
    return 0;
}
