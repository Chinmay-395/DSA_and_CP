#include <bits/stdc++.h>
using namespace std;

// ------ The code from leetcode ----
class Solution
{
public:
    int primeFactors(int n)
    {
        int tempVal = n;
        int sum = 0;
        int c = 2;
        while (n > 1)
        {
            if (n % c == 0)
            {
                // cout << c << " ";
                sum = sum + c;
                n /= c;
            }
            else
                c++;
        }
        if (sum % tempVal == 0)
            return -1;
        else
            return sum;
    }
    bool isPrime(int n)
    {
        // Corner cases
        if (n <= 1)
            return false;
        // suppose n=7 that is prime and its pair are (1,7)
        // so if a no. is prime then it can be check by numbers smaller than square root
        //  of the n
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int smallestValueHelper(int n)
    {

        if (n == 2 || isPrime(n))
        {
            return n;
        }
        int temp = 0;
        int z = n;
        while (z != -1)
        {
            z = primeFactors(z);
            if (z == -1)
            {
                break;
            }
            temp = z;
        }
        return temp;
    }
};
// ------ ------------------------ ----
int main()
{
    Solution sol;
    cout << " " << sol.smallestValueHelper(15) << endl;
    return -1;
}