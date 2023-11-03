// // The base template c++ code
// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

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
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     /*
//     nznooeeoer
//     'z' : 1
//     'e' : 3
//     'r' : 1
//     'o' : 3
//     'n' : 2

//     to maximise the output
//     we need to count Os and Es

//     z and r must me equal
//     n --> determines number of 1s

//     if z > n
//         then min(z,n) --> z-n ones and z zeros
//     else max(z,n) --> n-z ones and z zeros
//     */
//     string str, ans;
//     cin >> str;
//     unordered_map<char, int> hmap; // freq-map
//     for (auto val : str)
//     {
//         hmap[val]++;
//     }
//     int count_ones, count_zeros = 0;
//     for (int i = 0; i < hmap['n']; i++) // all them will be 1s
//     {
//         ans = ans + "1" + " ";
//     }

//     for (int i = 0; i < hmap['z']; i++) // all them will be zeros
//     {
//         ans = ans + "0" + " ";
//     }
// }

// int main()
// {

//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int tc = 1;
//     // cin >> tc;
//     for (int t = 1; t <= tc; t++)
//     {
//         // cout << "Case #" << t << ": ";
//         solve();
//     }
// }
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// ... [Keep all your other definitions and debug template here] ...

void solve()
{
    string str, ans;
    int total = 0;
    cin >> total;
    cin >> str;
    unordered_map<char, int> hmap; // freq-map
    for (auto val : str)
    {
        hmap[val]++;
    }

    // Since 'n' appears in "one" and 'z' appears in "zero",
    // you need to first use all occurrences of 'n' to form "1" (one)
    // Then subtract 2 for each 'n' used, because "one" has two more 'n's than "zero"
    int count_ones = hmap['n'];                    // count of 'n' for ones
    int count_zeros = hmap['z'];                   // count of 'z' for zeros
    count_ones = max(0, count_ones - count_zeros); // subtract the ones used for 'z'

    // Append ones and zeros to the answer
    for (int i = 0; i < count_ones; i++) // all of them will be 1s
    {
        ans += "1 ";
    }

    for (int i = 0; i < count_zeros; i++) // all of them will be zeros
    {
        ans += "0 ";
    }

    // Output the answer
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Redirect input and output
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tc = 1;
    cin >> tc; // Uncomment if the first line of the input specifies the number of test cases
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": "; // Uncomment if you need case numbering
        solve();
    }

    // Close files
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
