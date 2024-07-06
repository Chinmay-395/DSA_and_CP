#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
/*
=> (X&Y)^(X|Y) 
=> (x ^ (x|y)) & (y^(x|y))
=> (x^x | x^y) & (y^x | y^y)
=> (0 | x^y) & (y^x | 0)
=> (x^y) & (y^x)
=> (x^y)
XOR of Similar Numbers: The XOR value between two numbers is minimized when the numbers are as close as possible. For example, if you have two numbers a and b where b = a + 1, the XOR of a and b will typically be smaller than the XOR of a and any number that is further away from a in value.

Bit Differences: XOR works on the binary representation of numbers. For numbers that are close together, their binary representations will have fewer differing bits, resulting in a smaller XOR value. Conversely, numbers that are far apart will have more differing bits, leading to a larger XOR value.
thats why we sort the value
*/
void solve(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	std::sort(arr.begin(),arr.end());
	int ans = 1e9+7;
	for(int i=0; i<n-1; i++){
		ans = min(ans, arr[i]^arr[i+1]);
	}
	cout<<ans<<endl;
}
int main() {
	int num;
	cin >> num;    //Reading input from STDIN
	// cout << "Input number is " << num << endl;	// Writing output to STDOUT
	while(num--){
		solve();
	}
}
//(x & y) ^ (x | y)
/*
numbers | xor
000
001  
010     |  011(3) ^ 010(2) = 001
011
100
101
110
111

|3(011) ^ 5(101) = 110(6)
|3(011) ^ 6(110) = 101(5)
|3(011) ^ 7(111) = 100(4)
|3(0011) ^ 8(1000) = 1011(11)
|3(0011) ^ 9(1001) = 1010(10)



*/
