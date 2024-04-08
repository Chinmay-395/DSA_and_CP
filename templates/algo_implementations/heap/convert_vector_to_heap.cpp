#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main()
{
    int myints[] = {10, 20, 30, 5, 15};
    std::vector<int> v(myints, myints + 5);

    std::make_heap(v.begin(), v.end());
    std::cout << "initial max heap   : " << v.front() << '\n';

    // Modify first element
    v[0] = 10;
    std::make_heap(v.begin(), v.end());
    std::cout << "after modification max heap   : " << v.front() << '\n';
}