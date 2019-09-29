#include <iostream>
#include "Test.cpp"
using namespace std;

int main()
{
    /*List<Time<int>> a;
    a.gethead()->data;
    Time<int> temp;
    a.add(temp);
    a.gethead()->data.print();
*/
    test_list_int<int>();
    test_list_double<double>();
    test_list_string<string>();

}

