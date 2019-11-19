#include <iostream>
#include <string>
#include "Interface.h"
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
 *  Tests class with class Date and Time
 * @tparam T type of date
 * @param a class which want to sort
 */
template <typename T>
inline void test_list_class_Date_and_Time(Interface<T> &a)
{
    std::cout << "Lists with class Date and Time" << std::endl;
    test_insertionsort(a);
    test_quicksort(a);
    test_mergesort(a);
    test_heapsort(a);
    test_selectionsort(a);
    std::cout<<std::endl<<std::endl;
}

/**
 *  Testing class Date and Time with all function
 */
inline void test_Date_and_Time()
{
    DIFF d;
    Date_and_Time t1,t2;
    std::cout<<"System time T1: ";
    t1.print();
    std::cout<<std::endl<<"Random time T2: ";
    t2.random();
    t2.print();

    std::cout<<std::endl;
    std::cout<<"Week number in the year of T1: ";
    t1.getDate().num_of_week_at_year();
    std::cout<<std::endl<<"Day of the week T1: ";
    t1.getDate().weekday();
    std::cout<<std::endl<<"Difference between T1 and T2 : "<<std::endl;
    d=difference(t1,t2);
    std::cout<<d.days<<" days "<<d.hours<<" hours "<<d.minutes<<" minutes "<<d.seconds<<" seconds "<<std::endl<<"OR"<<std::endl;
    difference_in_days(d);
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
    std::cout<<std::endl;
    std::cout<<std::endl;
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
 * Manual testing class Date and Time with some function
 * @param T testing class
 */
inline void Manual_testing_Date_and_Time(Date_and_Time T)
{
    int y;
    int i;
    DIFF t1,t2;
    Time tm;
    Date dt;
    int q1,q2,q3,q4,q5,q6;
    Date_and_Time tm1,tm2;
    std::cin>>i;
    if (i==1)
    {
        T.random();
        std::cout<<"Random generating Date and Time."<<std::endl;
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
        T.T.yet_time();
        T.D.yet_date();
    }
    if (i==5)
    {
        std::cout<<"Enter days, hours, minutes, seconds:"<<std::endl;
        std::cin>>t1.days>>t1.hours>>t1.minutes>>t1.seconds;
        T.plus_to_time(t1);
        std::cout<<"Plussing to time."<<std::endl;
    }
    if (i==6)
    {
        std::cout<<"Enter days, hours, minutes, seconds:"<<std::endl;
        std::cin>>t1.days>>t1.hours>>t1.minutes>>t1.seconds;
        T.minus_to_time(t1);
        std::cout<<"Minusing from time."<<std::endl;
    }
    if (i==7)
    {
        std::cout<<"Enter first time(h:m:s d.m.y):"<<std::endl;
        std::cin>>q1>>q2>>q3>>q4>>q5>>q6;
        tm.add(q1,q2,q3);
        dt.add(q4,q5,q6);
        tm1.add(tm,dt);
        std::cout<<"Enter second time(h:m:s d.m.y):"<<std::endl;
        std::cin>>q1>>q2>>q3>>q4>>q5>>q6;
        tm.add(q1,q2,q3);
        dt.add(q4,q5,q6);
        tm2.add(tm,dt);
        t1=difference(tm1,tm2);
        std::cout<<"Difference in days: ";
        difference_in_days(t1);
        std::cout<<std::endl;
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
    if (i==8)
    {
        std::cout<<"Day of the week: ";
        T.D.weekday();
    }
    if (i==9)
    {
        std::cout<<"Number of week at year: ";
        T.D.num_of_week_at_year();
    }
    if (i!=10)
        Manual_testing_Date_and_Time(T);
}

/**
 * This Function defines the data type and class
 * which need to testing
 */
//функція для представлення в консоль основних варіантів роботи з програмою
inline void menu()
{
    Date_and_Time T;
    List<int> L1; List<double> L2; List<std::string> L3; List<Date_and_Time> L4;
    Array<int> A1; Array<double> A2; Array<std::string> A3; Array<Date_and_Time> A4;
    Vector<int> V1; Vector<double> V2; Vector<std::string> V3; Vector<Date_and_Time> V4;
    std::cout<<"1-Testing structure of List"<<std::endl
        <<"2-Testing class Date and Time"<<std::endl
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
            test_list_class_Date_and_Time(L4);
        }
        else if (i1==21)
        {
            std::cout << "Arrays" << std::endl;
            test_list_int(A1);
            test_list_double(A2);
            test_list_string(A3);
            test_list_class_Date_and_Time(A4);
        }
        else if (i1==31)
        {
            std::cout << "Vectors" << std::endl;
            test_list_int(V1);
            test_list_double(V2);
            test_list_string(V3);
            test_list_class_Date_and_Time(V4);
        }
        else
        {
            std::cout<<"Type of date"<<std::endl
                     <<"1-int"<<std::endl
                     <<"2-double"<<std::endl
                     <<"3-string"<<std::endl
                     <<"4-class Date and Time"<<std::endl;
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
            else if (i1==221)
                Manual_testing_List(&A1);
            else if (i1==222)
                Manual_testing_List(&A2);
            else if (i1==223)
                Manual_testing_List(&A3);
            else if (i1==224)
                Manual_testing_List(&A4);
            else if (i1==321)
                Manual_testing_List(&V1);
            else if (i1==322)
                Manual_testing_List(&V2);
            else if (i1==323)
                Manual_testing_List(&V3);
            else if (i1==324)
                Manual_testing_List(&V4);
        }
    }
    else if (i1==2) {
        std::cout << "Type of testing" << std::endl
                  << "1-Automatic testing" << std::endl
                  << "2-Manual testing" << std::endl;
        std::cin >> i2;
        if (i2 == 1)
            test_Date_and_Time();
        else if (i2 == 2)
        {
            std::cout<<"1-Random Time"<<std::endl
                     <<"2-Print"<<std::endl
                     <<"3-Set time"<<std::endl
                     <<"4-Yet time"<<std::endl
                     <<"5-Plus to Date"<<std::endl
                     <<"6-Minus to Date"<<std::endl
                     <<"7-Difference with date"<<std::endl
                     <<"8-Day of the week"<<std::endl
                     <<"9-Number of week at year"<<std::endl
                     <<"10-Return"<<std::endl;
            Manual_testing_Date_and_Time(T);
        }
    }

    menu();
}