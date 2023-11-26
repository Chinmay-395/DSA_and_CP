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

ll memo(int i, int cnt_nc, int n, int non_conseq, string str, vector<vector<int>> &dp)
{
    // base case
    if (i == n)
    {
        if (cnt_nc >= non_conseq)
        {
            return dp[i][cnt_nc] = 0;
        }

        return dp[i][cnt_nc] = 1;
    }
    if (dp[i][cnt_nc] != -1)
        return dp[i][cnt_nc];
    if (cnt_nc >= non_conseq)
        return dp[i][cnt_nc] = 0;
    // if()
    ll pickX = memo(i + 1, str[str.size() - 1] == 'x' ? cnt_nc + 1 : 1, n, non_conseq, str + 'x', dp);
    ll pickY = memo(i + 1, cnt_nc, n, non_conseq, str + 'y', dp);
    return dp[i][cnt_nc] = pickX + pickY;
}

long long recur(int i, int cnt_nc, int n, int non_conseq, string str)
{
    // base case
    if (i == n)
    {
        if (cnt_nc >= non_conseq)
        {
            return 0;
        }

        return 1;
    }
    if (cnt_nc >= non_conseq)
        return 0;
    // if()
    long long pickX = recur(i + 1, str[str.size() - 1] == 'x' ? cnt_nc + 1 : 1, n, non_conseq, str + 'x');
    long long pickY = recur(i + 1, cnt_nc, n, non_conseq, str + 'y');
    return pickX + pickY;
}

long long countSuperStrings(int n, int p, int countX, bool started)
{
    // base cases
    if (n == 0)
        return 1;
    if (countX >= p)
        return 0;

    // choosing 'Y'
    long long total = countSuperStrings(n - 1, p, 0, true) % MOD;

    // choosing 'X', ensuring it doesn't start with 'X'
    if (started)
    {
        total = (total + countSuperStrings(n - 1, p, countX + 1, true)) % MOD;
    }

    return total;
}

int editorial(int N, int P, vector<vector<int>> &dp)
{
    for (int i = 2; i <= N; i++)
    {

        dp[i][0] = dp[i][1] = 0; // initializing to 0;

        dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
        // for 'Y' the previous can be anything so adding those values

        for (int j = 1; j < P; j++)
        {

            if (i - j <= 0)
                break;

            dp[i][1] += (dp[i - j][0]);

            if (dp[i][1] >= MOD)
                dp[i][1] -= MOD;
        }
    }
    return (dp[N][0] + dp[N][1]) % MOD;
}

void solve()
{
    int length_of_string, non_conseq;
    cin >> length_of_string;
    cin >> non_conseq;
    vector<vector<int>> dp(length_of_string, vector<int>(2));
    // int x = recur(1, 0, length_of_string, non_conseq, "y");
    // cout << "THE ANS " << x << endl;
    // x = memo(1, 0, length_of_string, non_conseq, "y", dp);
    // cout << "THE ANS " << x << endl;
    // x = editorial(length_of_string, non_conseq, dp);
    // cout << "THE ANS " << x << endl;
    int x = countSuperStrings(6, 6, 0, false);
    cout << "THE ANS " << x << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Redirect input and output

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    cin >> tc; // Uncomment if the first line of the input specifies the number of test cases
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": "; // Uncomment if you need case numbering
        solve();
    }

    // Close files
    fclose(stdin);
    fclose(stdout);
    return 0;
}
