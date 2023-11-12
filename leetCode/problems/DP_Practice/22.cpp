#include <bits/stdc++.h>
#include <stdio.h>
#include </home/chinmay/Coding/DSA_and_CP/templates/print_list_and_map.h>
using namespace std;

class Solution
{
public:
    void recur(int i, int n, vector<string> &ans, string curr_str, stack<char> st)
    {
        if (i > n)
        {
            while (st.size() > 0)
            {
                curr_str += ')';
                st.pop();
            }
            ans.push_back(curr_str);
            return;
        }
        curr_str.push_back('(');
        st.push('(');
        recur(i + 1, n, ans, curr_str, st);

        curr_str.pop_back();
        curr_str.push_back(')');
        st.pop();
        recur(i, n, ans, curr_str, st);
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string curr_str = "";
        stack<char> st;
        recur(0, n, ans, curr_str, st);
        return ans;
    }
};
int main()
{
    Solution sol;
    printf("THE ANS \n");
    vector<string> ans = sol.generateParenthesis(3);
    for (auto x : ans)
    {
        cout << x << endl;
    }
}