// Coding Ninja Problems
#include <bits/stdc++.h>
using namespace std;

int getTheMax(int day,
              int last,
              vector<vector<int>> &points)
{
  if (day == 0)
  {
    int maxi = 0;
    for (int i = 0; i <= 2; i++)
    {
      if (i != last)
      {
        maxi = max(maxi, points[0][i]);
      }
    }
    return maxi;
  }
  int maxi = 0;
  for (int i = 0; i <= 2; i++)
  {
    if (i != last)
    {
      int activity = points[day][i] +
                     getTheMax(day - 1, i, points);
      maxi = max(maxi, activity);
    }
  }
  return maxi;
}
int getTheMaxMemoized(int day,
                      int last,
                      vector<vector<int>> &points,
                      vector<vector<int>> &dp)
{
  if (dp[day][last] != -1)
    return dp[day][last];
  if (day == 0)
  {
    int maxi = 0;
    for (int i = 0; i <= 2; i++)
    {
      if (i != last)
      {
        maxi = max(maxi, points[0][i]);
      }
    }
    dp[day][last] = maxi;
    return dp[day][last];
  }
  int maxi = 0;
  for (int i = 0; i <= 2; i++)
  {
    if (i != last)
    {
      int activity = points[day][i] +
                     getTheMaxMemoized(
                         day - 1,
                         i,
                         points,
                         dp);
      maxi = max(maxi, activity);
    }
  }
  dp[day][last] = maxi;
  return dp[day][last];
}
int ninjaTraining(
    int n,
    vector<vector<int>> &points)
{
  // Write your code here.
  /*
          1(0)
      /         \
      1(1)      1(2)
      /    \       /\
      3(0) 3(1) 3(0) 3(1)

          1(1)
      /         \
      3(0)       1(2)
      /    \       /\
      3(1) 3(2) 3(0) 3(1)

           5(2)
       /         \
      3(0)       1(1)
      /    \       /\
      3(1) 3(2) 3(0) 3(2)

      since there are only 3 columns in the matrix


  */
  vector<vector<int>> dp(n, vector<int>(4, -1));
  cout << "The regular function " << getTheMax(n - 1, 3, points) << endl;
  cout << "The memoized functiojn" << getTheMaxMemoized(n - 1, 3, points, dp) << endl;
  return -1;
}

int main()
{
  vector<vector<int>> points = {
      {1, 2, 5},
      {3, 1, 1},
      {3, 3, 3}};

  int n = points.size();
  cout << "The size of points " << n << endl;
  cout << ninjaTraining(n, points) << endl;
}
