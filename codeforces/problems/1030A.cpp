#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int val;
    for (int i = 0; i < n; i++)
    {

        cin >> val;
        if (val == 1)
        {
            cout << "HARD" << endl;
            break;
        }
    }
    if (val == 0)
    {
        cout << "EASY" << endl;
    }
    return 0;
}