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
    int recur(vector<int> rating, int i, int taken,
              int state)
    {
        if (taken == 3)
        {
            return 1;
        }
        if (i == rating.size())
            return 0;

        int ans = 0;
        int each_num = rating[i];
        for (int j = i + 1; j < rating.size() - 1; j++)
        {

            if (state == 0)
            {

                if (rating[j] > each_num)
                {
                    ans += recur(rating, j, taken + 1, 1, ans);
                }
                else
                {
                    ans += recur(rating, j, taken + 1, 2, ans);
                }
            }
            else if (state == 1 && rating[j] > ele)
            { // strictly increasing
                ans += recur(rating, j + 1, taken + 1, 1, ans);
            }
            else if (state == 2 && rating[j] > ele)
            { // strictly decreasing
                ans += recur(rating, j + 1, taken + 1, 2, ans);
            }
        }
        return ans;
    }

    int
    numTeams(vector<int> &rating)
    {
        int n = rating.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans += recur(rating, i, 1, 0);
        }
        return ans;
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

    //     int tc = 1;
    //     cin >> tc; // Uncomment if the first line of the input specifies the number of test cases
    //     for (int t = 1; t <= tc; t++)
    //     {
    //         // cout << "Case #" << t << ": "; // Uncomment if you need case numbering
    //         solve();
    //     }

    //     // Close files
    //     fclose(stdin);
    //     fclose(stdout);
    Solution sol;
    vector<int> a = {2,
                     5,
                     3,
                     4,
                     1};
    int ans = sol.numTeams(a);
    return 0;
}
