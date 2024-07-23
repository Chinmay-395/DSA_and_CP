#include <iostream>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;
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
    string s;
    cin >> s;
    int num;
    cin >> num; // Reading input from STDIN
    // cout << "Input number is " << num << endl;	// Writing output to STDOUT
    vector<string> vec_suffix;
    for (int i = 0; i < s.size(); i++)
    {
        string suffix = "";
        for (int j = 0; j < s.size(); j++)
        {
            suffix.push_back(s[s.size() - j - 1]);
        }
        vec_suffix.push_back(suffix);
    }
    sort(vec_suffix.begin(), vec_suffix.end());
    cout << vec_suffix[num] << endl;
}