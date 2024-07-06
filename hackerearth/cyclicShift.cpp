#include <iostream>
using namespace std;
void solve()
{
    int lengthOfString = 0, numberOfShifts = 0, displacement = 0;
    cin >> lengthOfString >> numberOfShifts;
    string inputString = "";
    cin >> inputString;
    string maxString = "";
    int periodicity = -1;
    for (int i = 0; i < lengthOfString; i++)
    {
        if (maxString < inputString)
        {
            maxString = inputString;
            displacement = i;
        }
        else if (maxString == inputString)
        {
            periodicity = i - displacement;
            break;
        }
        inputString = inputString.substr(1, lengthOfString) + inputString[0];
    }
    if (periodicity == -1)
    {
        cout << (displacement + (numberOfShifts - 1) * lengthOfString)
             << "\n";
    }
    else
    {
        cout << (displacement + (numberOfShifts - 1) * periodicity)
             << endl;
    }
}
int main()
{
    int num;
    cin >> num; // Reading input from STDIN
    // cout << "Input number is " << num << endl;	// Writing output to STDOUT
    while (num--)
    {
        solve();
    }
}
/*
The following solution actually works
#include <iostream>
using namespace std;
int main() {
int num;
cin >> num; //Reading input from STDIN
while(num--)
{
long long int n,k;
cin>>n>>k;
string s;
cin>>s;
string maxstr = "";
long long int d = 0 , p = -1;
// cout<<s.substr(1)<<endl;
for(long long int i=0;i<n;i++)
{
if(maxstr < s)
{
maxstr = s;
d = i;
}
else if(maxstr == s)
{
p = i-d;
break;
}

s = s.substr(1) + s.substr(0 , 1);
}

if(p == -1)
{
long long int ans = (d + ((k-1) * n));
cout<<ans<<endl;
}
else
{ long long int ans = (d + ((k-1) * p));
cout<<ans<<endl;

}

}
return 0;
}
*/