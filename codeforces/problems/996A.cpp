#include <bits/stdc++.h>

using namespace std;
/*
solving by greedy approach
*/
int greedy(int x)
{
    int i = 0;
    while (x >= 0)
    {
        if (100 <= x)
        {
            x = x - 100;
            i++;
        }
        else if (20 <= x && x < 100)
        {
            x = x - 20;
            i++;
        }
        else if (10 <= x && x < 20)
        {
            x = x - 10;
            i++;
        }
        else if (5 <= x && x < 10)
        {
            x = x - 5;
            i++;
        }
        else if (1 <= x && x < 5)
        {
            x = x - 1;
            i++;
        }
        else
        {
            break;
        }
    }
    return i;
}

// template <typename A, typename B>
// ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
// ostream &operator<<(ostream &os, const T_container &v)
// {
//     os << '{';
//     string sep;
//     for (const T &x : v)
//         os << sep << x, sep = ", ";
//     return os << '}';
// }
// void dbg_out() { cerr << endl; }
// template <typename Head, typename... Tail>
// void dbg_out(Head H, Tail... T)
// {
//     cerr << ' ' << H;
//     dbg_out(T...);
// }
// #ifdef LOCAL
// #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
// #else
// #define dbg(...)
// #endif

// #define ar array
// #define ll long long
// #define ld long double
// #define sza(x) ((int)x.size())
// #define all(a) (a).begin(), (a).end()

// const int MAX_N = 1e5 + 5;
// const ll MOD = 1e9 + 7;
// const ll INF = 1e9;
// const ld EPS = 1e-9;

// void solve()
// {

// }

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        int n;
        cin >> n;
        cout << "\n"
             << greedy(n) << endl;
        // cout << "The program ran \t" << greedy(43);
    }
    return 0;
}