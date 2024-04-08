// #include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  printf("enter full name \t");
  string s;
  getline(cin, s);
  cout << "the entire s" << endl
       << s;
  stringstream ss(s);
  cout << "The entire vector" << endl;
  // for(auto a: x){
  //   cout<<a<<endl;
  // }
  return 0;
}
