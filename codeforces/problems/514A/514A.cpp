#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main()
{
    long long number;
    cin >> number;
    string str = to_string(number);
    int n = str.size();
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {

        if ((i == 0 && str[i] == '9') || (str[i] - '0' > 4 && i > 0))
        {
            // int integer_value = (int)
            ans = ans + (9 - (str[i] - '0')) * pow(10, n - i - 1);
        }
        else
        {
            ans += (str[i] - '0') * pow(10, n - i - 1);
        }
    }
    cout << ans;
}
