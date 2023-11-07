#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
class Solution
{
public:
    int countCollisions(string directions)
    {
        /*
            direction: RLRSLL
                        2
                        SRSLL
                        3
                        SSSLL
                        4
                        SSSSL
                        5

            direction: LLRR
                       0
                       LLRR
                        0
                       LLRR
                         0
                       LLRR
                          0


                          llll

        */
        int count = 0;
        std::vector<char> str(directions.begin(), directions.end());
        for (int i = 0; i < str.size(); i++)
        {
            if ((i == 0 && str[i] == 'L') || str[i] == 'S')
                continue;
            if (str[i - 1] == 'R' && str[i] == 'L')
            {
                str[i - 1] = 'S';
                str[i] = 'S';
                count += 2;
            }
            else if (str[i] == 'R' && str[i + 1] == 'S')
            {
                str[i] = 'S';
                count += 1;
            }
            else if (str[i - 1] == 'S' && str[i] == 'L')
            {
                str[i] = 'S';
                count += 1;
            }
        }
        return count;
    }
};
int main()
{
    Solution sol;
    cout << "THE ANS" << endl;
    int x = sol.countCollisions("LLRR");
    cout << x << endl;
}