#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_set<int> p5{1, 5, 25, 125, 625, 3125, 15625};
int minimumBeautifulSubstrings1(const string &s)
{
    vector<int> dp(s.size() + 1, s.size() + 1);
    dp[s.size()] = 0;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        for (int j = i, val = 0; s[i] != '0' && j < s.size(); ++j)
        {
            val = val * 2 + s[j] - '0';
            if (p5.count(val))
                dp[i] = min(dp[i], 1 + dp[j + 1]);
        }
    }
    return dp[0] > s.size() ? -1 : dp[0];
}

int binaryToDecimal(string str)
{
    int dec_num = 0;
    int power = 0;
    int n = str.length();

    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == '1')
        {
            dec_num += (1 << power);
        }
        power++;
    }

    return dec_num;
}

bool isPowerof5(string s)
{
    int n = s.size(), i = 0, decimal_num = 0;
    for (int j = n - 1; j >= 0; j--)
    {
        decimal_num += (s[j] - '0') * (1 << i);
        i++;
    }
    while (decimal_num != 1)
    {
        if (decimal_num % 5 != 0)
            return false;
        decimal_num /= 5;
    }
    return true;
}
//(0,"1011",4,0)
int helper(int ind, string s, int n, int prev_ind)
{
    if (ind == n)
    {
        string g = s.substr(prev_ind, ind - prev_ind);
        if (isPowerof5(g))
            return 0;
        return INT_MAX - 1;
    }
    int mini = INT_MAX;
    // Pick option
    // the s[ind+1]=='1' indicates that the none of the substrings should have a leading zero in it
    if (s[ind] == '1' && ind < n - 1 && s[ind + 1] == '1')
    {
        string g = s.substr(prev_ind, ind - prev_ind + 1);
        if (isPowerof5(g))
            mini = min(mini, 1 + helper(ind + 1, s, n, ind + 1));
    }
    // Unpick option
    mini = min(mini, helper(ind + 1, s, n, prev_ind));
    return mini;
}

int minimumBeautifulSubstrings2(string s)
{
    if (s[0] == '0')
        return -1;
    int n = s.size(), ans = -1;
    ans = helper(0, s, n, 0);
    return (ans >= INT_MAX - 1) ? -1 : ans + 1;
}
int main()
{
    string s = "1011";
    // cout << "The ans " << recursive(s, s.size() - 1, "") << endl;
    cout << "The ans " << minimumBeautifulSubstrings2(s) << endl;
}