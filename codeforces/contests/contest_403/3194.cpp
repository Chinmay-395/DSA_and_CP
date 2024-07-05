/*
[ 7, 8, 3, 4, 15, 13, 4, 1 ]

[1,3,4,4,7,8,13,15] -> 16/2 = 8
[,3,4,4,7,8,13] -> 16/2 = 8
[4,4,7,8] -> 12/2 = 6
[4,7] -> 11/2 = 5.5
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

void solve()
{
}

class Solution
{
public:
    double minimumAverage(vector<int> &nums)
    {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int start = 0;
        int end = nums.size() - 1;
        double ans = INT_MAX;
        while (start < end)
        {
            double total = ((double)sorted_nums[start] + (double)sorted_nums[end]) / (double)2;
            start++;
            end--;
            ans = min(total, ans);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    printf("THE ANSWERS\n");
    vector<int> nums = {7, 8, 3, 4, 15, 13, 4, 1};
    printf("%lf", sol.minimumAverage(nums));
    return 0;
}