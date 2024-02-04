#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    cin >> n; // first line
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        string l;
        cin >> l;
        int len = l.size();
        // for(int i=0; i<len; i++){
        if (l[0] == 'X')
        { // either at the start
            if (l[1] == '+' && l[2] == '+')
            {
                total += 1;
            }
            else
            {
                total -= 1;
            }
        }
        else
        { // else at the end
            if (l[1] == '-' && l[0] == '-')
            {
                total -= 1;
            }
            else
            {
                total += 1;
            }
        }
    }
    cout << total;
}