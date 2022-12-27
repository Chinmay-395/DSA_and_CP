// https: // codeforces.com/contest/1669/problem/A

#include <bits/stdc++.h>

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

string solve(int n)
{

    if (n <= 1399)
    {
        return "Division 4";
    }
    else if (1400 <= n && n <= 1599)
    {
        return "Division 3";
    }
    else if (1600 <= n && n <= 1899)
    {
        return "Division 2";
    }
    else if (1900 <= n)
    {
        return "Division 1";
    }
    else
    {
        return "something went wrong";
    }
}

int main()
{
    int inputs;
    cin >> inputs;
    for (int t = 0; t < inputs; t++)
    {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
}