#include <iostream>
#include <string>
#include "Time.cpp"
#include "List.cpp"

template <typename T>
List<T> random_int(List<T> a)
{
    for (int i=0;i<10;i++)
        a.add(rand());
    return a;
}

template <typename T>
List<T> random_double(List<T> a)
{
    for (int i=0;i<10;i++)
        a.add(1.1*rand());
    return a;
}

template <typename T>
List<T> random_string(List<T> a)
{
    char c[]={'a','b'};
    for (int i=0;i<10;i++)
    {
        std::string s="";
        int l=rand()%10+1;
        for (int j=0;j<l;j++)
            s+= static_cast<char>(rand()%26+97);
        a.add(s);
    }
    return a;
}

template <typename T>
void test_list_int()
{
    List<int> a;
    std::cout<<"List with int"<<std::endl;
    std::cout<<"1) Random list";
    a=random_int(a);
    a.print1();
    std::cout<<"Insertion sort";
    a.insertionsort();
    a.print1();
    a.remove();
    std::cout<<"2) Random list";
    a=random_int(a);
    a.print1();
    std::cout<<"quick sort";
    a.quicksort();
    a.print1();
    a.remove();
    std::cout<<"3) Random list";
    a=random_int(a);
    a.print1();
    std::cout<<"merge sort";
    a.mergesort();
    a.print1();
    a.remove();
    std::cout<<"4) Random list";
    a=random_int(a);
    a.print1();
    std::cout<<"heap sort";
    a.heapsort();
    a.print1();
    a.remove();
    std::cout<<"5) Random list";
    a=random_int(a);
    a.print1();
    std::cout<<"selection sort";
    a.selectionsort();
    a.print1();
    a.remove();
    std::cout<<std::endl<<std::endl;
}

template <typename T>
void test_list_double()
{
    List<double> a;
    std::cout<<"List with double"<<std::endl;
    std::cout<<"1) Random list";
    a=random_double(a);
    a.print1();
    std::cout<<"Insertion sort";
    a.insertionsort();
    a.print1();
    a.remove();
    std::cout<<"2) Random list";
    a=random_double(a);
    a.print1();
    std::cout<<"quick sort";
    a.quicksort();
    a.print1();
    a.remove();
    std::cout<<"3) Random list";
    a=random_double(a);
    a.print1();
    std::cout<<"merge sort";
    a.mergesort();
    a.print1();
    a.remove();
    std::cout<<"4) Random list";
    a=random_double(a);
    a.print1();
    std::cout<<"heap sort";
    a.heapsort();
    a.print1();
    a.remove();
    std::cout<<"5) Random list";
    a=random_double(a);
    a.print1();
    std::cout<<"selection sort";
    a.selectionsort();
    a.print1();
    a.remove();
    std::cout<<std::endl<<std::endl;
}

template <typename T>
void test_list_string()
{
    List<std::string> a;
    std::cout<<"List with string"<<std::endl;
    std::cout<<"1) Random list";
    a=random_string(a);
    a.print1();
    std::cout<<"Insertion sort";
    a.insertionsort();
    a.print1();
    a.remove();
    std::cout<<"2) Random list";
    a=random_string(a);
    a.print1();
    std::cout<<"quick sort";
    a.quicksort();
    a.print1();
    a.remove();
    std::cout<<"3) Random list";
    a=random_string(a);
    a.print1();
    std::cout<<"merge sort";
    a.mergesort();
    a.print1();
    a.remove();
    std::cout<<"4) Random list";
    a=random_string(a);
    a.print1();
    std::cout<<"heap sort";
    a.heapsort();
    a.print1();
    a.remove();
    std::cout<<"5) Random list";
    a=random_string(a);
    a.print1();
    std::cout<<"selection sort";
    a.selectionsort();
    a.print1();
    a.remove();
    std::cout<<std::endl<<std::endl;
}