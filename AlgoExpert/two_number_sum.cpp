//check if the targetSum - number_at_index is present in the array
//10-3 = 7 => not present
//10-5 = 5 => not present :- cannot consider number at same index
//10-11 = 1 => present => return the tuple of those two numbers

#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum)
{
    // Write your code here.
    //since we cannot look sum the number at the same index
    vector<int> arr;
    // if(array.size() < 1){
    // 	return null;
    // }else{
    for (int i = 0; i < array.size(); i++)
    {
        int x = targetSum - array[i];
        for (int j = 0; j < array.size(); j++)
        {
            if (i != j && x == array[j])
            {
                arr.push_back(x);
                arr.push_back(array[j]);
            }
        }
    }
    // }
    return arr;
}
