// July 17, 2023
// Amazon OA (medium difficulty) on hackerearth

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int recurPlayAndWin(vector<int> &arr, int i)
{

    if (i < 0)
        return 0;
    int pick = arr[i] + recurPlayAndWin(arr, i - 2);
    int notPick = arr[i - 1] + recurPlayAndWin(arr, i - 1 - 2);
    return max(pick, notPick);
}

int opti2RecurPlayAndWin(vector<int> &arr, int i, vector<int> &dp)
{

    if (i < 0)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int pick = arr[i] + opti2RecurPlayAndWin(arr, i - 2, dp);
    int notPick = arr[i - 1] + opti2RecurPlayAndWin(arr, i - 1 - 2, dp);
    return dp[i] = max(pick, notPick);
}

int optiRecurPlayAndWin(vector<int> &arr, vector<int> &dp)
{

    dp[0] = arr[0];
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1)
        {
            pick += dp[i - 2];
        }
        int nonPick = dp[i - 1];

        dp[i] = max(pick, nonPick);
    }
    return dp[n - 1];
}
// int answerFunc(vector<int> arr)
// {

//     cout << "the ans " << recurPlayAndWin(arr, arr.size() - 1) << endl;
// }
int main()
{

    // int num;
    // cin >> num;
    // cout << "Input num is " << num << endl;
    vector<int> arr = {1, 6, 4, 8, 11, 16};
    // int n1 = arr.size();
    // vector<int> dp(arr.size() + 1, -1);
    // cout << "the ans " << opti2RecurPlayAndWin(arr, arr.size() - 1, dp) << endl;
    vector<int> dp(arr.size(), -1);
    cout << "the ans " << optiRecurPlayAndWin(arr, dp) << endl;
    vector<int> arr2 = {18, 115, 13, 17};
    // vector<int> dp2(arr.size() + 1, -1);
    // cout << "the ans " << opti2RecurPlayAndWin(arr2, arr2.size() - 1, dp2) << endl;
    vector<int> dp2(arr2.size(), -1);
    cout << "the ans " << optiRecurPlayAndWin(arr2, dp2) << endl;
}