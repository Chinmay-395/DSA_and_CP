#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        key.erase(remove(key.begin(), key.end(), ' '), key.end());

        unordered_map<char, char> hMap;
        int ascii = 97;
        for (int i = 0; i < key.size() && ascii < 123; i++)
        {
            if (hMap.find(key[i]) == hMap.end())
            {
                hMap[key[i]] = char(ascii);
                ascii++;
            }
        }
        string ans = "";
        for (int j = 0; j < message.size(); j++)
        {
            if (message[j] != ' ')
            {
                ans.push_back(hMap.at(message[j]));
            }
            else
            {
                ans.push_back(' ');
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    cout << obj.decodeMessage("the quick brown fox jumps over the lazy dog", "vkbs bs t suepuv") << endl;
    return -1;
}