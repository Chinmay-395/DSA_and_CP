#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
class Solution
{
public:
    /*
    the base case is
        if there are not 2-consecutive ++ then return true if thats the chance of second-player or false if it's the first player

    at every index check whether there are any two consecutive '++'
        if it exists take recursive function
        OR
        skip that index and move to the next one

    f(i, currState, playerFlip){
        possible_indexs[currState.size()]={0};
        for(i to n){

        }
    }



                            ++++
    /                           |                           \
    --++                     +--+                             ++--
     |                        |                                 |
   ----                   true                                ----
    |                                                           |
    false                                                       false

-----------------------------------------------------------------------------------



        +++++
        |=> --+++
            |=> ----+
            |=> --+--
        |=> +--++
            |=> +----
        |=> ++--+
            |=> ----+

        ++++++
        |=> --++++
            |=> ----++
                |=> ------
            |=> --+--+
            |=> --++--
                |=> ------

        |=> +--+++
            |=> +----+
        |=> ++--++
            |=> ----+
            |=>


    */
    bool canWin(string currentState)
    {
        if (currentState.size() == 0)
            return false;

        for (int i = 0; i < currentState.size() - 1; i++)
        {
            if (currentState[i] == '+' && currentState[i + 1] == '+')
            {
                currentState[i] = '-';
                currentState[i + 1] = '-';
                if (!canWin(currentState))
                {
                    return true;
                }
                currentState[i] = '+';
                currentState[i + 1] = '+';
            }
        }
        return false;
    }
};
