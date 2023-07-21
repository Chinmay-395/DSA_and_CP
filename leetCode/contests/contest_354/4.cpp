#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestValidSubstring(string word, vector<string> &forbidden)
    {
        int n = word.length();
        unordered_set<string> forbiddenSet(forbidden.begin(), forbidden.end());
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (i - j < 0)
                {
                    break;
                }
                if (forbiddenSet.find(word.substr(i - j, j + 1)) != forbiddenSet.end())
                {
                    dp[i] = j;
                    break;
                }
            }
            if (i > 0)
            {
                dp[i] = min(dp[i], dp[i - 1] + 1);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }

    // Recursive version of the solution
    int longestValidSubstringRecursive(string word, vector<string> &forbidden, int index)
    {
        if (index == 0)
        {
            return 0;
        }

        int maxLength = 0;
        cout << "The different substrings" << endl;
        for (int j = 0; j < 10; j++)
        {
            if (index - j < 0)
            {
                break;
            }
            string subWord = word.substr(index - j, j + 1);
            cout << subWord << endl;
            if (find(forbidden.begin(), forbidden.end(), subWord) != forbidden.end())
            {
                maxLength = j;
                break;
            }
        }

        int prevLength = longestValidSubstringRecursive(word, forbidden, index - 1);
        return max(maxLength, prevLength + 1);
    }
};

int main()
{
    Solution sol;
    string word = "leetcode";
    vector<string> forbidden = {"le", "de", "e"};
    cout << "Dynamic Programming: " << sol.longestValidSubstring(word, forbidden) << endl;
    cout << "Recursive: " << sol.longestValidSubstringRecursive(word, forbidden, word.length() - 1) << endl;
    return 0;
}
