// #include <stdio.h>
#include <bits/stdc++.h>
// using namespace std;
int foo()
{
    int x = 0;
    int ans = x + (x = 1);
    // std::cout << ans << std::endl;
    return ans;
}
int main()
{
    std::cout << foo();
    return 0;
}

/*
let x = 1 in
  let f = fun y -> x in
  let x = 2 in
  f 0;;

  let x = 1 in
  let x = 2 in
  let f = fun y -> x in
  f 0;;

*/