/*
we cannot use the greedy method obviously

abaac

aa is the problem min(3,4) = 3

aabaa

index [0,1] & [3,4] are the problem
cost   1,2     4,1


aaabaaa cost = [1,2,2,3,4,1,1]

problem: [0,1] [1,2] [4,5] [5,6]
cost      1,2    2,2  4,1   1,1


aabaa




*/

// The base template c++ code
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

class Solution
{
public:
    int total;
    int recur(int i, string s, int cost, vector<int> neededTime, string color)
    {

        if (i >= color.size())
            return cost;

        if (s.size() > 0 && s[s.size() - 1] == color[i])
            return -1;

        string x = s + color[i];
        int pick = recur(i + 1, x, cost + neededTime[i], neededTime, color);

        int skip = recur(i + 1, s, cost, neededTime, color);

        return max(pick, skip);
    }
    int minCost(string s, vector<int> &cost)
    {
        int res = 0, max_cost = 0, sum_cost = 0, n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (i > 0 && s[i] != s[i - 1])
            {
                res += sum_cost - max_cost;
                sum_cost = max_cost = 0;
            }
            sum_cost += cost[i];
            max_cost = max(max_cost, cost[i]);
        }
        res += sum_cost - max_cost;
        return res;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Redirect input and output

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    // int tc = 1;
    // cin >> tc; // Uncomment if the first line of the input specifies the number of test cases
    // for (int t = 1; t <= tc; t++)
    // {
    //     // cout << "Case #" << t << ": "; // Uncomment if you need case numbering

    // }
    Solution sol;
    vector<int> vec = {1, 2, 3, 4, 1};
    string s = "aabaa";
    int x = sol.minCost(s, vec);
    cout << "\n THE ANS\t" << x << endl;

    // Close files
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
