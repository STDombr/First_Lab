#include <iostream>
#include <vector>
//#include "List.h"
#include "List.cpp"

using namespace std;

int main()
{
    int a,n;
    cin>>n;
    List<int> Time;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        Time.add(a);
    }
    Time.selectionsort();
    Time.print();

}