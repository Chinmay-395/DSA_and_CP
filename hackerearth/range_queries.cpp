#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int a[100005][20];

void pre_process()
{
    int val = 1;
    for (int i = 1; i <= 100000; i++)
    {
        int val = 1;
        for (int j = 1; val <= i; j++)
        {
            if (i & val)
            {
                a[i][j] = 1;
            }
            val *= 2;
        }
    }

    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= 100000; j++)
        {
            a[j][i] += a[j - 1][i];
        }
    }
}

int main()
{
    pre_process();
    int q;
    cin >> q;
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        int answer = a[r][x] - a[l - 1][x];
        cout << answer << endl;
    }
}
