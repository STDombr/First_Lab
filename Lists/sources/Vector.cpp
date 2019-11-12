#include <iostream>
#include <math.h>
#include "Times.h"
#include "Date.h"
#include "Vector.h"

//Конструктор для класу Array
template <typename T>
Vector<T>::Vector()
{
    arr.clear();
}

//функція для видалення класу
template <typename T>
void Vector<T>::remove()
{
    arr.clear();
}

//функція для добавляння одного листа
template <typename T>
void Vector<T>::add(T data)
{
    arr.push_back(data);
}

//функція для виведення всього класу
template <typename T>
void Vector<T>::print()
{
    std::cout<<std::endl;
    for(int i=0;i<arr.size();i++)
        std::cout<<arr[i]<<" ";
    std::cout<<std::endl;
}

//функція для виведення всього класу для типу Time
template <>
inline void Vector<Time>::print()
{
    std::cout<<std::endl;
    for(int i=0;i<arr.size();i++)
        arr[i].print();
    std::cout<<std::endl;
}

//функція для виведення всього класу для типу Date
template <>
inline void Vector<Date>::print()
{
    std::cout<<std::endl;
    for(int i=0;i<arr.size();i++)
        arr[i].print();
    std::cout<<std::endl;
}

//функція для видалення елемента tail
template <typename T>
void Vector<T>::popTail()
{
    for(int i=1;i<arr.size();i++)
        arr[0]=arr[1];
    popHead();
}

//функція для видалення елемента head
template <typename T>
void Vector<T>::popHead()
{
    arr.pop_back();
}


template <typename T>
T Vector<T>::element(int position)
{
    if (arr.size()>=position)
        return arr[position-1];
    return 0;
}

//алгоритм сортування quicksort
template <typename T>
void Vector<T>::quicksort(int a,int b)
{
    if (b==-2)
        b=arr.size();
    int left=a,right=b;
    T piv=arr[(left+right)/2-1];
    while(left<=right)
    {
        while (piv>arr[left-1])
            left++;
        while (arr[right-1]>piv)
            right--;
        if (left<=right)
        {
            T temp=arr[left-1];
            arr[left-1]=arr[right-1];
            arr[right-1]=temp;
            //swap(mas[left-1],mas[right-1]);
            left++;
            right--;
        }
    }
    if (a<right)
        quicksort(a,right);
    if (b>left)
        quicksort(left,b);
}

//алгоритм сортування insertionsort
template <typename T>
void Vector<T>::insertionsort()
{
    int i,j;
    T key;
    for (i=2;i<=arr.size();i++)
    {
        key=arr[i-1];
        j=i-1;
        while (j>=1 && arr[j-1]>key)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=key;
    }
}

//алгоритм сортування mergesort
template <typename T>
void Vector<T>::merge(int left,int m,int right)
{
    int i=1,j=1,k=left;
    int n1=m-left+1;
    int n2=right-m;
    Vector L,R;
    for (int y=1;y<=n1;y++)
        L.add(arr[left+y-2]);
    for (int y=1;y<=n2;y++)
        R.add(arr[m+y-1]);
    while (i<=n1 && j<=n2)
    {
        if (R.arr[j-1]>L.arr[i-1])
        {
            arr[k-1]=L.arr[i-1];
            i++;
        }
        else
        {
            arr[k-1]=R.arr[j-1];
            j++;
        }
        k++;
    }

    while (i<=n1)
    {
        arr[k-1]=L.arr[i-1];
        i++;
        k++;
    }
    while (j<=n2)
    {
        arr[k-1]=R.arr[j-1];
        j++;
        k++;
    }
    L.remove();
    R.remove();
}

template <typename T>
void Vector<T>::mergesort(int left,int right)
{
    if (right==-2)
        right=arr.size();
    if (left<right)
    {
        int m=(left+right)/2;
        mergesort(left,m);
        mergesort(m+1,right);
        merge(left,m,right);
    }
}

//алгоритм сортування heapsort
template <typename T>
void Vector<T>::heap(int n,int i)
{
    int largest=i;
    int left=i*2+1;
    int right=i*2+2;
    if (left<n && arr[left]>arr[largest])
        largest=left;
    if (right<n && arr[right]>arr[largest])
        largest=right;
    if (largest!=i)
    {
        T temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        //swap(arr[i],arr[largest]);
        heap(n,largest);
    }
}

template <typename T>
void Vector<T>::heapsort()
{
    for (int i=arr.size()/2-1;i>=0;i--)
        heap(arr.size(),i);
    for (int i=arr.size()-1;i>=0;i--)
    {
        T temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        //swap(arr[0],arr[i]);
        heap(i,0);
    }
}

//алгоритм сортування selectionsort
template <typename T>
void Vector<T>::selectionsort()
{
    int i,j,min;
    for (i=0;i<arr.size()-1;i++)
    {
        min=i;
        for (j=i+1;j<arr.size();j++)
            if (arr[min]>arr[j])
                min=j;
        T temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
        //swap(arr[i],arr[min]);
    }
}

//функція для рандомного заповнення елементів
template <typename T>
void Vector<T>::random()
{
    int r=rand()%10+5;
    for (int i=0;i<r;i++)
        add(rand());
}

//функція для рандомного заповнення елементів для типу double
template <>
inline void Vector<double>::random()
{
    int r=rand()%10+5;
    for (int i=0;i<r;i++)
        add(1.1*rand());
}

//функція для рандомного заповнення елементів для типу string
template <>
inline void Vector<std::string>::random()
{
    int r=rand()%10+5;
    for (int i=0;i<r;i++)
    {
        std::string s="";
        int l=rand()%10+1;
        for (int j=0;j<l;j++)
            s+= static_cast<char>(rand()%26+97);
        add(s);
    }
}

//функція для рандомного заповнення елементів для типу Time
template <>
inline void Vector<Time>::random()
{
    int r=rand()%10+5;
    Time t;
    for (int i=0;i<r;i++)
    {
        t.random();
        add(t);
    }
}

//функція для рандомного заповнення елементів для типу Date
template <>
inline void Vector<Date>::random()
{
    int r=rand()%10+5;
    Date d;
    for (int i=0;i<r;i++)
    {
        d.random();
        add(d);
    }
}