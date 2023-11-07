# index

## The template cpp file for codeforces

```cpp
// The base template c++ code
#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
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



void solve() {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
    // Close files
    fclose(stdin);
    fclose(stdout);
}
```

## The template cpp file for leetcode

```cpp
#include <bits/stdc++.h>
using namespace std;

// ------ The code from leetcode ----

// ------ ------------------------ ----
int main()
{
    Solution sol;

    return -1;
}
```

## Code snippets

_To find duplicates present in a vector,_

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

template<typename T>
std::set<T> findDuplicates(std::vector<T> vec)        // no-ref, no-const
{
    std::set<int> duplicates;
    std::sort(vec.begin(), vec.end());
    std::set<int> distinct(vec.begin(), vec.end());
    std::set_difference(vec.begin(), vec.end(), distinct.begin(), distinct.end(),
        std::inserter(duplicates, duplicates.end()));
    return duplicates;
}

int main()
{
    std::vector<int> vec = {2, 2, 4, 1, 3, 6, 6, 7, 6, 8};

    std::set<int> duplicates = findDuplicates(vec);
    for (auto &i: duplicates) {
        std::cout << i << ' ';
    }

    return 0;
}
```

# Algorithms

## minimum spanning tree

1. Kruskal's algorithm✅
2. Prim jarniks algorithm✅
3. Baruvka's algorithm
4.

# DP problems

1. 70 climbing stair (leetcode)
2. 746 min cost climbing stairs (leetcode)
3. 1137 Nth tri-bonacci number (leetcode)
4. 2244 minimum round (leetcode)

## Array

1. Hit lottery (CF)
2. Fair division (CF)

## strings

## Linked-list

## Trees

## Graph

## Bitwise operations

```
I'm looking for a great, enthusiactic, engineering team to work for that will provide me with challenging, interesting work that I can learn from and contribute to.
```
