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
    /*
    BGGBG

    GBGGB

    BGGBG t=2
    GGBGB
----
    BGGBG t=3
    GGBGB
    GGGBB
----
    BGGBG t=3
    stack (n=5)
    i=5: G
    i=4: GB
    i=3: G-> GGB
    i=4


    */
    int n, t;
    cin >> n;
    cin >> t;
    string s;
    cin >> s;
    while (t)
    {
        for (int i = 1; i < n; i++)
        {
            if (s[i] == 'G' && s[i - 1] == 'B')
            {
                s[i - 1] = 'G';
                s[i] = 'B';
                i++;
            }
        }
        t--;
    }
    cout << s << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Redirect input and output

#ifndef ONLINE_JUDGE
    freopen("/home/chinmay/Coding/DSA_and_CP/codeforces/problems/input.txt", "r", stdin);
    freopen("/home/chinmay/Coding/DSA_and_CP/codeforces/problems/output.txt", "w", stdout);
#endif

    int tc = 3;
    // cin >> tc; // Uncomment if the first line of the input specifies the number of test cases
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
