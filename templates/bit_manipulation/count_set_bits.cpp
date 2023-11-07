int count_set_bits(int n)
{
    /**
     * @brief this function will count number of set bits in the unsigned number
     * count how many odds numbers there are while dividing the number by 2
     * references:
     * https://en.cppreference.com/w/cpp/numeric/popcount
     * https://stackoverflow.com/questions/60165922/stdbitsetncount-vs-builtin-popcount
     * built-in function in c++: ```int  __builtin_popcount(unsigned int);```
     * complexity:
     * this will take `log to the base 2 of n` (log n) time
     * @param int value.
     * @return int of number of set bits
     */

    int count = 0;

    while (n != 0)
    {
        if (n % 2 != 0)
        {
            count++;
        }
        n = n / 2;
    }
    return count;
    /*
    for eg: 5 ==> 101
    5 --> odd -> count = 1
    5/2=2 --> even -> count=1
    2/2=1 --> odd --> count=2
    1/2=0 --> even
    */
}

/*
1<<4

10000
*/