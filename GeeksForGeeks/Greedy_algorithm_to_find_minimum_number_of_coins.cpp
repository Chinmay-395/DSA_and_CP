#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
{
      int V = 30;
      vector < int > ans;
      int coins[] = {25, 10, 5};
      
      int n = sizeof(coins) / sizeof(coins[0]);
      sort(coins, coins+n);
      for (int i = n - 1; i >= 0; i--) {
        while (V >= coins[i]) {
          V -= coins[i];
          ans.push_back(coins[i]);
        }
      }
    cout<<"The minimum number of coins is "<<ans.size()<<endl;
    cout<<"The coins are "<<endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
