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

// cout << "Input number is " << num << endl;	// Writing output to STDOUT
/*

0  1,2  3,4,5  6,7,8,9  10,11,12,13,14,15
1   2     3     4       5
1   3     6      10     15

2(1)/2 = 1
3(2)/2 = 3
4(3)/2 = 6
n(n-1)/2 => 5(4)/2 = 10

group 1 (only 1)
group 2 (next two) only possible if i+2<n
group 3 (next 3 ) only possible if i+3<n
group 4 (next 4) only possible if i+4<n


index     |  how many can I take |
0th index -> [all-of-them]
1st index -> [upcoming 3 index from 1st (including)]
2nd index -> [upcoming 3 index from 2nd (including)]
3rd index -> [upcoming 3 index from 3rd (including)]
4th index -> [only 4th index]
5th index -> [only 5th index]

we can get the lower_bound by calculating [x(x-1)/2] for every index
and sum those indexes where x = n-i

TC:O(N^2)



*/
void solve()
{
    int num;
    cin >> num;
    vector<int> size_calc_arr;

    for (int i = 2; i <= num; i++)
    {
        int x = (i * (i - 1)) / 2;
        size_calc_arr.push_back(x);
    }
    vector<int> arr(num);
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    int max_special_sum = INT_MIN;
    for (int i = 0; i < num; i++)
    {
        int running_sum = 0;
        // get the lowerbound of num-i
        // get the range from ith position will store it in j
        int n = num;
        int j = i;
        int group_size = 1;
        while (j + group_size <= n)
        {
            running_sum += accumulate(arr.begin() + i, arr.begin() + i + group_size, 0);

            group_size++;
        }

        max_special_sum = max(running_sum, max_special_sum);
    }
    cout << max_special_sum << endl;
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