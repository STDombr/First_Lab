#include <iostream>
#include "Test.cpp"
//#include "Time.cpp"
#include <ctime>
using namespace std;

void menu();

int main()
{
    srand(time(0));
    menu();
}


//функція для представлення в консоль основних варіантів роботи з програмою
void menu()
{
    cout<<"1-Testing class Time"<<endl
        <<"2-Testing class Date"<<endl
        <<"3-Testing structure of List"<<endl
        <<"4-Testing structure of Array"<<endl
        <<"9-Exit"<<endl;
    int i;
    cin>>i;
    if (i==9)
        return;
    if (i==3 || i==4)
    {
        std::cout<<std::endl<<std::endl;
        test_list_int<int>(i);
        test_list_double<double>(i);
        test_list_string<string>(i);
        test_list_class_Time<Time<int>>(i);
        test_list_class_Date<Date<int>>(i);
    }
    if (i==1)
    {
        std::cout<<std::endl<<std::endl;
        test_Time<int>();
    }
    if (i==2)
    {
        std::cout<<std::endl<<std::endl;
        test_Date<int>();
        menu();
    }
    menu();
}