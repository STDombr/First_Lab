#include <iostream>
#include <string>
//#include "Time.cpp"
#include "List.cpp"

//функція для тестування insertsort
template <typename T>
void test_insertionsort(Interface<T> &a)
{
    std::cout<<"1) Random list";
    a.random();
    a.print();
    std::cout<<"Insertion sort";
    a.insertionsort();
    a.print();
    a.remove();
}

//функція для тестування quicksort
template <typename T>
void test_quicksort(Interface<T> &a)
{
    std::cout<<"2) Random list";
    a.random();
    a.print();
    std::cout<<"quick sort";
    a.quicksort();
    a.print();
    a.remove();
}

//функція для тестування mergesort
template <typename T>
void test_mergesort(Interface<T> &a)
{
    std::cout<<"3) Random list";
    a.random();
    a.print();
    std::cout<<"merge sort";
    a.mergesort();
    a.print();
    a.remove();
}

//функція для тестування heapsort
template <typename T>
void test_heapsort(Interface<T> &a)
{
    std::cout<<"4) Random list";
    a.random();
    a.print();
    std::cout<<"heap sort";
    a.heapsort();
    a.print();
    a.remove();
}

//функція для тестування selectionsort
template <typename T>
void test_selectionsort(Interface<T> &a)
{
    std::cout<<"5) Random list";
    a.random();
    a.print();
    std::cout<<"selection sort";
    a.selectionsort();
    a.print();
    a.remove();
}

//функція для тестування класу List на основі типу даних int
template <typename T>
void test_list_int(int c)
{
    List<int> L;
    Array<int> A;
    if (c == 3)
    {
        std::cout << "List with int" << std::endl;
        test_insertionsort(L);
        test_quicksort(L);
        test_mergesort(L);
        test_heapsort(L);
        test_selectionsort(L);
    }
    else if (c==4)
    {
        std::cout << "Array with int" << std::endl;
        test_insertionsort(A);
        test_quicksort(A);
        test_mergesort(A);
        test_heapsort(A);
        test_selectionsort(A);
    }
    std::cout<<std::endl<<std::endl;
}

//функція для тестування класу List на основі типу даних double
template <typename T>
void test_list_double(int c)
{
    List<double> L;
    Array<double> A;
    if (c == 3)
    {
        std::cout << "List with double" << std::endl;
        test_insertionsort(L);
        test_quicksort(L);
        test_mergesort(L);
        test_heapsort(L);
        test_selectionsort(L);
    }
    else if (c==4)
    {
        std::cout << "Array with double" << std::endl;
        test_insertionsort(A);
        test_quicksort(A);
        test_mergesort(A);
        test_heapsort(A);
        test_selectionsort(A);
    }
    std::cout<<std::endl<<std::endl;
}

//функція для тестування класу List на основі типу даних string
template <typename T>
void test_list_string(int c) {
    List<std::string> L;
    Array<std::string> A;
    if (c == 3)
    {
        std::cout << "List with string" << std::endl;
        test_insertionsort(L);
        test_quicksort(L);
        test_mergesort(L);
        test_heapsort(L);
        test_selectionsort(L);
    }
    else if (c==4)
    {
        std::cout << "Array with string" << std::endl;
        test_insertionsort(A);
        test_quicksort(A);
        test_mergesort(A);
        test_heapsort(A);
        test_selectionsort(A);
    }
    std::cout << std::endl<< std::endl;
}


//функція для тестування класу List на основі класу Time
template <typename T>
void test_list_class_Time(int c)
{
    List<Time <int>> L;
    Array<Time <int>> A;
    if (c == 3)
    {
        std::cout << "List with class Time" << std::endl;
        test_insertionsort(L);
        test_quicksort(L);
        test_mergesort(L);
        test_heapsort(L);
        test_selectionsort(L);
    }
    else if (c==4)
    {
        std::cout << "Array with class Time" << std::endl;
        test_insertionsort(A);
        test_quicksort(A);
        test_mergesort(A);
        test_heapsort(A);
        test_selectionsort(A);
    }
    std::cout << std::endl<< std::endl;
}

//функція для тестування класу List на основі класу Date
template <typename T>
void test_list_class_Date(int c)
{
    List<Date <int>> L;
    Array<Date <int>> A;
    if (c == 3)
    {
        std::cout << "List with class Date" << std::endl;
        test_insertionsort(L);
        test_quicksort(L);
        test_mergesort(L);
        test_heapsort(L);
        test_selectionsort(L);
    }
    else if (c==4)
    {
        std::cout << "Array with class Date" << std::endl;
        test_insertionsort(A);
        test_quicksort(A);
        test_mergesort(A);
        test_heapsort(A);
        test_selectionsort(A);
    }
    std::cout << std::endl<< std::endl;
}

//функція для тестування класу Time
template <typename T>
void test_Time()
{
    TM<int> d;
    Time<int> t1,t2;
    std::cout<<"System time T1: ";
    t1.print();
    std::cout<<"Random time T2: ";
    t2.random();
    t2.print();
    std::cout<<"Difference between T1 and T2 : "<<std::endl;
    d=difference(t1,t2);
    difference_in_hours(d);
    difference_in_minutes(d);
    difference_in_seconds(d);
    std::cout<<"T1-difference : ";
    t1.minus_to_time(d);
    t1.print();
    std::cout<<"T1+difference : ";
    t1.plus_to_time(d);
    t1.plus_to_time(d);
    t1.print();
    std::cout<<std::endl<<std::endl;
}

//функція для тестування класу Date
template <typename T>
void test_Date()
{
    Date<int> d1,d2;
    std::cout<<"System date D1: ";
    d1.print();
    std::cout<<"Random date D2: ";
    d2.random();
    d2.print();
    std::cout<<"Day of the week D1: ";
    d1.weekday();
    std::cout<<"Day of the week D2: ";
    d2.weekday();
    std::cout<<"Week number in the year of D1: ";
    d1.num_of_week_at_year();
    std::cout<<"Week number in the year of D2: ";
    d2.num_of_week_at_year();
    std::cout<<std::endl<<std::endl;

}