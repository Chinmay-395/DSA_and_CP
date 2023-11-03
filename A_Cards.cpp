// The base template c++ code
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
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    string str, ans;
    cin >> str;

    /*
    nznooeeoer
    'z' : 1
    'e' : 3
    'r' : 1
    'o' : 3
    'n' : 2

    to maximise the output
    we need to count Os and Es

    z and r must me equal
    n --> determines number of 1s

    if z > n
        then min(z,n) --> z-n ones and z zeros
    else max(z,n) --> n-z ones and z zeros
    */
    unordered_map<char, int> hmap; // freq-map
    for (auto val : str)
    {
        hmap[val]++;
    }
    int count_ones, count_zeros = 0;
    for (int i = 0; i < hmap['n']; i++) // all them will be 1s
    {
        ans = ans + "1" + " ";
    }

    for (int i = 0; i < hmap['z']; i++) // all them will be zeros
    {
        ans = ans + "0" + " ";
    }

    cout << ans;
}