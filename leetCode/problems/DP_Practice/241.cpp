#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int operation(int x, int y, char ch)
    {
        if (ch == '+')
            return x + y;
        else if (ch == '-')
            return x - y;
        else
            return x * y;
    }
    vector<int> diffWaysToCompute(string exp)
    {
        vector<int> ans;
        bool isNum = 1;
        for (int i = 0; i < exp.size(); i++)
        {
            if (exp[i] == '*' || exp[i] == '-' || exp[i] == '+')
            {
                isNum = 0;
                // split the equations to left and right
                vector<int> left = diffWaysToCompute(exp.substr(0, i));
                vector<int> right = diffWaysToCompute(exp.substr(i + 1));

                for (auto l : left)
                {
                    for (auto r : right)
                    {
                        ans.push_back(operation(l, r, exp[i]));
                    }
                }
            }
        }
        if (isNum == 1)
            ans.push_back(stoi(exp));
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> ans = sol.diffWaysToCompute("2-1-1");
}