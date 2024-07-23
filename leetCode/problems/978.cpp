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
    int recur(int i, int prev, int size, int sign, vector<int> &arr)
    {
        if (i == arr.size() - 1)
        {
            return 0;
        }
        int pick = 0, not_pick = 0;
        if (sign == 1 && arr[i] < arr[i + 1])
        { // curr less than next
            return 1 + recur(i + 1, arr[i], ++size, !sign, arr);
        }
        else if (sign == 0 && arr[i] > arr[i + 1])
        { // curr greater than next
            return 1 + recur(i + 1, arr[i], ++size, !sign, arr);
        }
        else
        {
            return 0;
        }
        // theres no skipping because it is a sub-array
        return 0;
    }
    int maxTurbulenceSize(vector<int> &arr)
    {
        if (arr.size() == 1)
            return 1;
        int ans = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            int check_eo = i % 2 == 0 ? 0 : 1; // 0 is even; 1 is odd
            int x, y;
            if (check_eo == 0)
            { // when its even

                x = recur(i + 1, arr[i], 1, 1, arr); // arr[k] < arr[k + 1] when k is even
                y = recur(i + 1, arr[i], 1, 0, arr); // arr[k] > arr[k + 1] when k is even
            }
            else
            {                                        // when its odd
                x = recur(i + 1, arr[i], 1, 0, arr); // arr[k] > arr[k + 1] when k is odd
                y = recur(i + 1, arr[i], 1, 1, arr); // arr[k] < arr[k + 1] when k is odd
            }

            ans = max({ans, x, y});
        }
        return ans;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //     // Redirect input and output

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int tc = 1;
    // cin >> tc; // Uncomment if the first line of the input specifies the number of test cases
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": "; // Uncomment if you need case numbering
        Solution sol;
        vector<int> arr = {4, 8, 12, 16};
        int x = sol.maxTurbulenceSize(arr);
        cout << "THE ANS " << x << endl;
    }

    // // Close files
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
