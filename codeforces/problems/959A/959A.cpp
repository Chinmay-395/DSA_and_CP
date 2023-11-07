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
/*
Ehab chooses a number the number

starting from Mahmoud
    Mahmoud --> 'a' has to be even --> -2
    Ehab --> 'a' has to be odd --> -1

    for example
    5
    M -> 3
    E -> 2
    M -> 0
*/
void solve()
{
    int n;
    cin >> n; // ehab num
    bool mahmoud = true;
    while (n >= 1)
    {
        if (mahmoud)
        {
            n = n - 2;
        }
        else
        {
            n = n - 1;
        }
    }
    if (!mahmoud)
    {
        cout << "Ehab";
    }
    else
    {
        cout << "Mahmoud";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    //     int tc = 1;
    //     // cin >> tc;
    //     for (int t = 1; t <= tc; t++)
    //     {
    //         // cout << "Case #" << t << ": ";
    //         solve();
    //     }
    //     // Close files
    //     fclose(stdin);
    //     fclose(stdout);
    int n;
    cin >> n; // ehab num

    if (n % 2)
        printf("Ehab");
    else
        printf("Mahmoud");
}