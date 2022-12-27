// #include <bits/stdc++.h>
// using namespace std;
#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 256;
// ------ The code from leetcode ----
class Solution
{

    // Function to print distinct characters in
    // given string str[]
    vector<char> printDistinct(string str)
    {
        int n = str.length();

        // count[x] is going to store count of
        // character 'x' in str. If x is not present,
        // then it is going to store 0.
        int count[MAX_CHAR];

        // index[x] is going to store index of character
        // 'x' in str. If x is not present or x is
        // more than once, then it is going to store a value
        // (for example, length of string) that cannot be
        // a valid index in str[]
        int index[MAX_CHAR];

        // Initialize counts of all characters and indexes
        // of distinct characters.
        for (int i = 0; i < MAX_CHAR; i++)
        {
            count[i] = 0;
            index[i] = n; // A value more than any index
                          // in str[]
        }

        // Traverse the input string
        for (int i = 0; i < n; i++)
        {
            // Find current character and increment its
            // count
            char x = str[i];
            ++count[x];

            // If this is first occurrence, then set value
            // in index as index of it.
            if (count[x] == 1 && x != ' ')
                index[x] = i;

            // If character repeats, then remove it from
            // index[]
            if (count[x] == 2)
                index[x] = n;
        }

        // Since size of index is constant, below operations
        // take constant time.
        vector<char> arr;
        sort(index, index + MAX_CHAR);
        for (int i = 0; i < MAX_CHAR && index[i] != n; i++)
            arr.push_back(str[index[i]]);

        sort(arr.begin(), arr.end());
        return arr;
    }

    vector<char> cntDistinct(string str)
    {
        // Set to store unique characters
        // in the given string
        unordered_set<char> s;

        // Loop to traverse the string
        for (int i = 0; i < str.size(); i++)
        {

            // Insert current character
            // into the set
            s.insert(str[i]);
        }
        vector<char> arr;
        unordered_set<char>::iterator itr;
        for (itr = s.begin(); itr != s.end(); ++itr)
        {
            arr.push_back(*itr);
        }
        sort(arr.begin(), arr.end());
        return arr;
    }

public:
    int similarPairs(vector<string> &words)
    {
        map<vector<char>, int> map_of_vector;
        map_of_vector[cntDistinct(words[0])] = 1;
        for (int i = 1; i < words.size(); i++)
        {
            vector<char> temp = cntDistinct(words[i]);
            if (map_of_vector.find(temp) != map_of_vector.end())
            {
                map_of_vector[temp] += 1;
            }
            else
            {
                map_of_vector[temp] = 1;
            }
        }
        map<vector<char>, int>::iterator itr;
        int count = 0;
        for (itr = map_of_vector.begin(); itr != map_of_vector.end(); ++itr)
        {
            int val = itr->second;
            // while (val > 1)
            // {
            //     if (val == 2)
            //     count = count + 1;//val;
            //     else if(val > 2 ){
            //         count = count
            //     }
            // }
            // n(n - 1) / 2
            // count = (val * (val - 1)) / 2;
            if (val == 2)
                count = count + 1; // val;
            else if (val > 2)
            {
                count = count + val;
            }
        }
        return count;
    }
};
// ------ ------------------------ ----
int main()
{
    Solution sol;
    vector<string> words = {"aba", "aabb", "abcd", "bac", "aabc"}; //{"aba", "aabb", "abcd", "bac", "aabc"};
    cout
        << "ANS: " << sol.similarPairs(words) << endl;
    return -1;
}