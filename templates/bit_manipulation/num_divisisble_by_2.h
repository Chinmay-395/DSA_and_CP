/**
 * @brief Using the and operation, we can check if a number n is even because  
    n & 1 = 0 
    if  n  is even, and  n & 1 = 1 
    if n  is odd.
    @param int n:
*/
bool isDivisibleByPowerOf2(int n, int k)
{
    int powerOf2 = 1 << k;
    return (n & (powerOf2 - 1)) == 0;
}