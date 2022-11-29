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

void solve()
{
    int n, one = 0, two = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int z;
        cin >> z;
        v.push_back(z);
    }
    // cin >> v[i];
    sort(v.rbegin(), v.rend());
    for (auto i : v)
    {
        if (one <= two)
        {
            one += i;
        }
        else
            two += i;
    }
    one == two ? cout << "YES\n" : cout << "NO\n";
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}