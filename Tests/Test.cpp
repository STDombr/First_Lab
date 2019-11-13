#include <iostream>
#include <string>
#include "Interface.h"
#include "Time.h"
#include "Array.cpp"
#include "List.cpp"
#include "Vector.cpp"

/**
 *  Tests insertionsort with any class
 * @tparam T type of date
 * @param a class which want to sort
 */
template <typename T>
void test_insertionsort(Interface<T> &a)
{
    std::cout<<"1) Random list ";
    a.random();
    a.print();
    std::cout<<"Insertion sort ";
    a.insertionsort();
    a.print();
    a.remove();
}

/**
 *  Tests quicksort with any class
 * @tparam T type of date
 * @param a class which want to sort
 */
template <typename T>
void test_quicksort(Interface<T> &a)
{
    std::cout<<"2) Random list ";
    a.random();
    a.print();
    std::cout<<"quick sort ";
    a.quicksort();
    a.print();
    a.remove();
}

/**
 *  Tests mergesort with any class
 * @tparam T type of date
 * @param a class which want to sort
 */
template <typename T>
void test_mergesort(Interface<T> &a)
{
    std::cout<<"3) Random list ";
    a.random();
    a.print();
    std::cout<<"merge sort ";
    a.mergesort();
    a.print();
    a.remove();
}

/**
 *  Tests heapsort with any class
 * @tparam T type of date
 * @param a class which want to sort
 */
template <typename T>
void test_heapsort(Interface<T> &a)
{
    std::cout<<"4) Random list ";
    a.random();
    a.print();
    std::cout<<"heap sort ";
    a.heapsort();
    a.print();
    a.remove();
}

/**
 *  Tests selectionsort with any class
 * @tparam T type of date
 * @param a class which want to sort
 */
template <typename T>
void test_selectionsort(Interface<T> &a)
{
    std::cout<<"5) Random list ";
    a.random();
    a.print();
    std::cout<<"selection sort ";
    a.selectionsort();
    a.print();
    a.remove();
}

/**
 *  Tests class with type int
 * @tparam T type of date
 * @param a class which want to sort
 */
template <typename T>
inline void test_list_int(Interface<T> &a)
{
        std::cout << "Lists with int" << std::endl;
        test_insertionsort(a);
        test_quicksort(a);
        test_mergesort(a);
        test_heapsort(a);
        test_selectionsort(a);
    std::cout<<std::endl<<std::endl;
}

/**
 *  Tests class with type double
 * @tparam T type of date
 * @param a class which want to sort
 */
template <typename T>
inline void test_list_double(Interface<T> &a)
{
    std::cout << "Lists with double" << std::endl;
        test_insertionsort(a);
        test_quicksort(a);
        test_mergesort(a);
        test_heapsort(a);
        test_selectionsort(a);
        std::cout<<std::endl<<std::endl;
}

/**
 *  Tests class with type string
 * @tparam T type of date
 * @param a class which want to sort
 */
template <typename T>
inline void test_list_string(Interface<T> &a) {
    std::cout << "Lists with string" << std::endl;
    test_insertionsort(a);
    test_quicksort(a);
    test_mergesort(a);
    test_heapsort(a);
    test_selectionsort(a);
    std::cout<<std::endl<<std::endl;
}


/**
 *  Tests class with class Time
 * @tparam T type of date
 * @param a class which want to sort
 */
template <typename T>
inline void test_list_class_Time(Interface<T> &a)
{
    std::cout << "Lists with class Time" << std::endl;
    test_insertionsort(a);
    test_quicksort(a);
    test_mergesort(a);
    test_heapsort(a);
    test_selectionsort(a);
    std::cout<<std::endl<<std::endl;
}

/**
 *  Tests class with class Date
 * @tparam T type of date
 * @param a class which want to sort
 */
template <typename T>
inline void test_list_class_Date(Interface<T> &a)
{
    std::cout << "Lists with class Date" << std::endl;
    test_insertionsort(a);
    test_quicksort(a);
    test_mergesort(a);
    test_heapsort(a);
    test_selectionsort(a);
    std::cout<<std::endl<<std::endl;
}

/**
 *  Testing class Time with all function
 */
inline void test_Time()
{
    TM d;
    Time t1,t2;
    std::cout<<"System time T1: ";
    t1.print();
    std::cout<<std::endl<<"Random time T2: ";
    t2.random();
    t2.print();
    std::cout<<std::endl<<"Difference between T1 and T2 : "<<std::endl;
    d=difference(t1,t2);
    difference_in_hours(d);
    difference_in_minutes(d);
    difference_in_seconds(d);
    std::cout<<"T1-difference : ";
    t1.minus_to_time(d);
    t1.print();
    std::cout<<std::endl<<"T1+difference : ";
    t1.plus_to_time(d);
    t1.plus_to_time(d);
    t1.print();
    std::cout<<std::endl<<std::endl;
}

/**
 *  Testing class Date with all function
 */
inline void test_Date()
{
    Date d1,d2;
    std::cout<<std::endl<<"System date D1: ";
    d1.print();
    std::cout<<std::endl<<"Random date D2: ";
    d2.random();
    d2.print();
    std::cout<<std::endl<<"Day of the week D1: ";
    d1.weekday();
    std::cout<<"Day of the week D2: ";
    d2.weekday();
    std::cout<<"Week number in the year of D1: ";
    d1.num_of_week_at_year();
    std::cout<<"Week number in the year of D2: ";
    d2.num_of_week_at_year();
    std::cout<<std::endl<<std::endl;

}

/**
 *  Manual testing any List with any type of date
 * @tparam T type of date
 * @param a class
 */
template <typename T>
void Manual_testing_List(Interface<T> *a)
{
    int i;
    std::cin>>i;
    if (i==1)
    {
        a->random();
        std::cout<<"Random generating lists."<<std::endl;
    }
    if (i==2)
    {
        a->print();
    }
    if (i==3)
    {
        std::cout<<"Enter element"<<std::endl;
        a->Enter_element();
    }
    if (i==4)
    {
        std::cout<<"Pop element."<<std::endl;
        a->popTail();
    }
    if (i==5)
    {
        std::cout<<"Sorting lists."<<std::endl;
        a->quicksort();
    }
    if (i==6)
    {
        std::cout<<"Deleting."<<std::endl;
        a->remove();
    }
    if (i!=9)
        Manual_testing_List(a);
}

/**
 * Manual testing class Time with some function
 * @param T testing class
 */
inline void Manual_testing_Time(Time T)
{
    int y;
    int i;
    TM t1,t2;
    Time tm1,tm2;
    std::cin>>i;
    if (i==1)
    {
        T.random();
        std::cout<<"Random generating time."<<std::endl;
    }
    if (i==2)
    {
        T.print();
        std::cout<<std::endl;
    }
    if (i==3)
    {
        std::cout<<"Enter element"<<std::endl;
        y=T.Enter_element();
        if(y==0)
            std::cout<<"Invalid element!"<<std::endl;
    }
    if (i==4)
    {
        std::cout<<"Yet time."<<std::endl;
        T.yet_time();
    }
    if (i==5)
    {
        std::cout<<"Enter hour, minute, second:"<<std::endl;
        std::cin>>t1.hour>>t1.minute>>t1.second;
        T.plus_to_time(t1);
        std::cout<<"Plussing to time."<<std::endl;
    }
    if (i==6)
    {
        std::cout<<"Enter hour, minute, second:"<<std::endl;
        std::cin>>t1.hour>>t1.minute>>t1.second;
        T.minus_to_time(t1);
        std::cout<<"Minusing from time."<<std::endl;
    }
    if (i==7)
    {
        std::cout<<"Enter first time:"<<std::endl;
        std::cin>>t1.hour>>t1.minute>>t1.second;
        tm1.add(t1.hour,t1.minute,t1.second);
        std::cout<<"Enter second time:"<<std::endl;
        std::cin>>t2.hour>>t2.minute>>t2.second;
        tm2.add(t2.hour,t2.minute,t2.second);
        t1=difference(tm1,tm2);
        std::cout<<"Difference in hours: ";
        difference_in_hours(t1);
        std::cout<<std::endl;
        std::cout<<"Difference in minutes: ";
        difference_in_minutes(t1);
        std::cout<<std::endl;
        std::cout<<"Difference in seconds: ";
        difference_in_seconds(t1);
        std::cout<<std::endl;
    }
    if (i!=9)
        Manual_testing_Time(T);
}

/**
 * Manual testing class Date with some function
 * @param T testing class
 */
inline void Manual_testing_Date(Date D)
{
    int i,y;
    std::cin>>i;
    if (i==1)
    {
        D.random();
        std::cout<<"Random generating date."<<std::endl;
    }
    if (i==2)
    {
        D.print();
        std::cout<<std::endl;
    }
    if (i==3)
    {
        std::cout<<"Enter element"<<std::endl;
        y=D.Enter_element();
        if(y==0)
            std::cout<<"Invalid element!"<<std::endl;
    }
    if (i==4)
    {
        std::cout<<"Yet time."<<std::endl;
        D.yet_date();
    }
    if (i==5)
    {
        std::cout<<"Day of the week: ";
        D.weekday();
    }
    if (i==6)
    {
        std::cout<<"Number of week at year: ";
        D.num_of_week_at_year();
    }
    if (i!=9)
        Manual_testing_Date(D);
}

/**
 * This Function defines the data type and class
 * which need to testing
 */
//функція для представлення в консоль основних варіантів роботи з програмою
inline void menu()
{
    Time T;
    Date D;
    List<int> L1; List<double> L2; List<std::string> L3; List<Time> L4; List<Date> L5;
    Array<int> A1; Array<double> A2; Array<std::string> A3; Array<Time> A4; Array<Date> A5;
    Vector<int> V1; Vector<double> V2; Vector<std::string> V3; Vector<Time> V4; Vector<Date> V5;
    std::cout<<"1-Testing structure of List"<<std::endl
        <<"2-Testing class Time"<<std::endl
        <<"3-Testing class Date"<<std::endl
        <<"9-Exit"<<std::endl;
    int i1,i2;
    std::cin>>i1;
    if (i1==9)
        return;
    else if (i1==1)
    {
        std::cout<<"Type of link"<<std::endl
                 <<"1-Linked lists"<<std::endl
                 <<"2-Arrays"<<std::endl
                 <<"3-Vectors"<<std::endl;
        std::cin>>i1;
        std::cout<<"Type of testing"<<std::endl
                 <<"1-Automatic testing"<<std::endl
                 <<"2-Manual testing"<<std::endl;
        std::cin>>i2;
        i1=i1*10+i2;
        if (i1==11)
        {
            std::cout << "Linked lists" << std::endl;
            test_list_int(L1);
            test_list_double(L2);
            test_list_string(L3);
            test_list_class_Time(L4);
            test_list_class_Date(L5);
        }
        else if (i1==21)
        {
            std::cout << "Arrays" << std::endl;
            test_list_int(A1);
            test_list_double(A2);
            test_list_string(A3);
            test_list_class_Time(A4);
            test_list_class_Date(A5);
        }
        else if (i1==31)
        {
            std::cout << "Vectors" << std::endl;
            test_list_int(V1);
            test_list_double(V2);
            test_list_string(V3);
            test_list_class_Time(V4);
            test_list_class_Date(V5);
        }
        else
        {
            std::cout<<"Type of date"<<std::endl
                     <<"1-int"<<std::endl
                     <<"2-double"<<std::endl
                     <<"3-string"<<std::endl
                     <<"4-class Time"<<std::endl
                     <<"5-class Date"<<std::endl;
            std::cin>>i2;
            i1=i1*10+i2;
            std::cout<<"1-Random lists"<<std::endl
                     <<"2-Print"<<std::endl
                     <<"3-Add element"<<std::endl
                     <<"4-Pop"<<std::endl
                     <<"5-Sorting"<<std::endl
                     <<"6-Deleting lists"<<std::endl
                     <<"9-Return"<<std::endl;
            if (i1==121)
                Manual_testing_List(&L1);
            else if (i1==122)
                Manual_testing_List(&L2);
            else if (i1==123)
                Manual_testing_List(&L3);
            else if (i1==124)
                Manual_testing_List(&L4);
            else if (i1==125)
                Manual_testing_List(&L5);
            else if (i1==221)
                Manual_testing_List(&A1);
            else if (i1==222)
                Manual_testing_List(&A2);
            else if (i1==223)
                Manual_testing_List(&A3);
            else if (i1==224)
                Manual_testing_List(&A4);
            else if (i1==225)
                Manual_testing_List(&A5);
            else if (i1==321)
                Manual_testing_List(&V1);
            else if (i1==322)
                Manual_testing_List(&V2);
            else if (i1==323)
                Manual_testing_List(&V3);
            else if (i1==324)
                Manual_testing_List(&V4);
            else if (i1==325)
                Manual_testing_List(&V5);
        }
    }
    else if (i1==2) {
        std::cout << "Type of testing" << std::endl
                  << "1-Automatic testing" << std::endl
                  << "2-Manual testing" << std::endl;
        std::cin >> i2;
        if (i2 == 1)
            test_Time();
        else if (i2 == 2)
        {
            std::cout<<"1-Random Time"<<std::endl
                     <<"2-Print"<<std::endl
                     <<"3-Set time"<<std::endl
                     <<"4-Yet time"<<std::endl
                     <<"5-Plus to Date"<<std::endl
                     <<"6-Minus to Date"<<std::endl
                     <<"7-Difference with date"<<std::endl
                     <<"9-Return"<<std::endl;
            Manual_testing_Time(T);
        }
    }
    else if (i1==3)
    {
        std::cout<<"Type of testing"<<std::endl
                 <<"1-Automatic testing"<<std::endl
                 <<"2-Manual testing"<<std::endl;
        std::cin>>i2;
        if (i2==1)
            test_Date();
        else if (i2==2)
        {
            std::cout<<"1-Random Date"<<std::endl
                     <<"2-Print"<<std::endl
                     <<"3-Set date"<<std::endl
                     <<"4-Yet date"<<std::endl
                     <<"5-Day of the week"<<std::endl
                     <<"6-Number of week at year"<<std::endl
                     <<"9-Return"<<std::endl;
            Manual_testing_Date(D);
        }
    }

    menu();
}