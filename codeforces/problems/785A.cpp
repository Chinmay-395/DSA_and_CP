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
    int n;
    cin >> n;
    int x = 0;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "Tetrahedron")
        {
            x += 4;
        }
        if (s == "Cube")
        {
            x += 6;
        }
        if (s == "Octahedron")
        {
            x += 8;
        }
        if (s == "Dodecahedron")
        {
            x += 12;
        }
        if (s == "Icosahedron")
        {
            x += 20;
        }
    }
    cout << x << endl;
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
