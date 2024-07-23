#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cin >> num; // Reading input from STDIN
    // cout << "Input number is " << num << endl;	// Writing output to STDOUT
    vector<string> vec;

    for (int i = 0; i < num; i++)
    {
        string s;
        cin >> s;
        vec.push_back(s);
        int count = 0;

        for (int j = 0; j < i; j++)
        {
            if (vec[j] < vec[i])
            {
                count++;
            }
        }
        cout << count << endl;
    }
}
