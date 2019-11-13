/**
 * 2nd Course K-28
 * Lab 1. Variant 2-9
 * Task: make a structure of Arrays and realise different sort algorithms
 *
 *Purpose: this file contains all the methods that are written in the Array.h
 *
 *@author Stanislav Dombrovskyi
 *@version 13/11/19
 */

#include <iostream>
#include <math.h>
#include "Times.h"
#include "Date.h"
#include "Array.h"

/**
     * The default constructor
     */
template <typename T>
Array<T>::Array()
{
    T *mas=new T[30];
    size=0;
    max_size=30;
}

/**
     * delete all elements
     */
template <typename T>
void Array<T>::remove()
{
    T *mas=new T[30];
    size =0;
    max_size=30;
}

/**
     * Adds the input value to the list
     *
     * @param data The value that would be added to the List
     */
template <typename T>
void Array<T>::add(T data)
{
    if (size>=max_size) {
        T *b = new T[max_size];
        max_size += 10;
        for (int i = 0; i <= size; i++)
            b[i] = mas[i];
        T *mas=new T[max_size+10];
        for (int i = 0; i <= size; i++)
            mas[i] = b[i];
    }
    mas[size]=data;
    size++;
}

/**
     * Function that prints all the data from the list on the screen
     */
template <typename T>
void Array<T>::print()
{
    for(int i=0;i<size;i++)
        std::cout<<mas[i]<<" ";
    std::cout<<std::endl;
}

/**
     * Function that prints all the data from the list on the screen of type class Time
     */
template <>
inline void Array<Time>::print()
{
    for(int i=0;i<size;i++)
        mas[i].print();
    std::cout<<std::endl;
}

/**
     * Function that prints all the data from the list on the screen of type class Date
     */
template <>
inline void Array<Date>::print()
{
    for(int i=0;i<size;i++)
        mas[i].print();
    std::cout<<std::endl;
}

/**
     * Deletes the last element of the list
     */
template <typename T>
void Array<T>::popTail()
{
    if (size>=1)
    {
        size--;
    }
}

/**
     * Deletes the first element of the list
     */
template <typename T>
void Array<T>::popHead()
{
    if (size>=1)
    {
        for(int i=1;i<size;i++)
            mas[i-1]=mas[i];
        size--;
    }
}
/**
     * Function that adds entered the element to the List
     *
     */
template <typename T>
void Array<T>::Enter_element()
{
    T i;
    std::cin>>i;
    add(i);
}
/**
     * Function that adds entered the element to the List of type class Time
     *
     */
template <>
inline void Array<Time>::Enter_element()
{
    Time i1,i2;
    int i;
    i=i1.Enter_element();
    if (i==1)
        add(i1);
    else
        std::cout<<"Invalid element!"<<std::endl;
}
/**
     * Function that adds entered the element to the List of type class Date
     *
     */
template <>
inline void Array<Date>::Enter_element()
{
    int i;
    Date i1,i2;
    i=i1.Enter_element();
    if (i==1)
        add(i1);
    else
        std::cout<<"Invalid element!"<<std::endl;
}
/**
     * Function thad return elements from position
     *
     * @param position
     * @return elements
     */
template <typename T>
T Array<T>::element(int position)
{
    if (size>=position)
        return mas[position-1];
    return 0;
}

/**
    * Function that performs the quicksort algorithm
     *
     *@param a The start sorting
     *@param b The end sorting
    */
template <typename T>
void Array<T>::quicksort(int a,int b)
{
    if (b==-2)
        b=size;
    int left=a,right=b;
    T piv=mas[(left+right)/2-1];
    while(left<=right)
    {
        while (piv>mas[left-1])
            left++;
        while (mas[right-1]>piv)
            right--;
        if (left<=right)
        {
            T temp=mas[left-1];
            mas[left-1]=mas[right-1];
            mas[right-1]=temp;
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

/**
     * Function that performs the insertion sort algorithm
     */
template <typename T>
void Array<T>::insertionsort()
{
    int i,j;
    T key;
    for (i=2;i<=size;i++)
    {
        key=mas[i-1];
        j=i-1;
        while (j>=1 && mas[j-1]>key)
        {
            mas[j]=mas[j-1];
            j--;
        }
        mas[j]=key;
    }
}

/**
     *The function that divides the array in two subarrays and then merges them into one in ascending order
     *
     * @param left The start of the first array
     * @param m The end of the first array and the start of the second array
     * @param right The end of the second array
     */
template <typename T>
void Array<T>::merge(int left,int m,int right)
{
    int i=1,j=1,k=left;
    int n1=m-left+1;
    int n2=right-m;
    Array L,R;
    for (int y=1;y<=n1;y++)
        L.add(mas[left+y-2]);
    for (int y=1;y<=n2;y++)
        R.add(mas[m+y-1]);
    while (i<=n1 && j<=n2)
    {
        if (R.mas[j-1]>L.mas[i-1])
        {
            mas[k-1]=L.mas[i-1];
            i++;
        }
        else
        {
            mas[k-1]=R.mas[j-1];
            j++;
        }
        k++;
    }

    while (i<=n1)
    {
        mas[k-1]=L.mas[i-1];
        i++;
        k++;
    }
    while (j<=n2)
    {
        mas[k-1]=R.mas[j-1];
        j++;
        k++;
    }
    L.remove();
    R.remove();
}
/**
    * Function that basically calls the merge function
    *
     * @param left The start sorting
     * @param right The end sorting
     *
     */
template <typename T>
void Array<T>::mergesort(int left,int right)
{
    if (right==-2)
        right=size;
    if (left<right)
    {
        int m=(left+right)/2;
        mergesort(left,m);
        mergesort(m+1,right);
        merge(left,m,right);
    }
}

/**
     +* task
     *
     * Function that performs the heapsort algorithm
     *
     * @param n count of elements
     * @param i position of largest element
     */
template <typename T>
void Array<T>::heap(int n,int i)
{
    int largest=i;
    int left=i*2+1;
    int right=i*2+2;
    if (left<n && mas[left]>mas[largest])
        largest=left;
    if (right<n && mas[right]>mas[largest])
        largest=right;
    if (largest!=i)
    {
        T temp=mas[i];
        mas[i]=mas[largest];
        mas[largest]=temp;
        //swap(mas[i],mas[largest]);
        heap(n,largest);
    }
}
/**
     +* task
     *
     *Function that basically calls the heap function
     */
template <typename T>
void Array<T>::heapsort()
{
    for (int i=size/2-1;i>=0;i--)
        heap(size,i);
    for (int i=size-1;i>=0;i--)
    {
        T temp=mas[0];
        mas[0]=mas[i];
        mas[i]=temp;
        //swap(mas[0],mas[i]);
        heap(i,0);
    }
}

/**
     +* task
     *
    * Function that performs the selection sort algorithm
    */
template <typename T>
void Array<T>::selectionsort()
{
    int i,j,min;
    for (i=0;i<size-1;i++)
    {
        min=i;
        for (j=i+1;j<size;j++)
            if (mas[min]>mas[j])
                min=j;
        T temp=mas[i];
        mas[i]=mas[min];
        mas[min]=temp;
        //swap(mas[i],mas[min]);
    }
}

/**
     * Function that randomly generates the List of int
     */
template <typename T>
void Array<T>::random()
{
    int r=rand()%10+5;
    for (int i=0;i<r;i++)
        add(rand());
}

/**
     * Function that randomly generates the List of double
     */
template <>
inline void Array<double>::random()
{
    int r=rand()%10+5;
    for (int i=0;i<r;i++)
        add(1.1*rand());
}

/**
     * Function that randomly generates the List of string
     */
template <>
inline void Array<std::string>::random()
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

/**
     * Function that randomly generates the List of class Time
     */
template <>
inline void Array<Time>::random()
{
    int r=rand()%10+5;
    Time t;
    for (int i=0;i<r;i++)
    {
        t.random();
        add(t);
    }
}

/**
     * Function that randomly generates the List of class Date
     */
template <>
inline void Array<Date>::random()
{
    int r=rand()%10+5;
    Date d;
    for (int i=0;i<r;i++)
    {
        d.random();
        add(d);
    }
}