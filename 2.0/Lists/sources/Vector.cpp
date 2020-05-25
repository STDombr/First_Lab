/**
 * 2nd Course K-28
 * Lab 1. Variant 2-9
 * Task: make a structure of Vectors and realise different sort algorithms
 *
 *Purpose: this file contains all the methods that are written in the Vector.h
 *
 *@author Stanislav Dombrovskyi
 *@version 13/11/19
 */

#include <iostream>
#include <math.h>
#include "Vector.h"
#include "Date_and_Time.h"

/**
     * The default constructor
     */
template <typename T>
Vector<T>::Vector()
{
    arr.clear();
}

/**
     * delete all elements
     */
template <typename T>
void Vector<T>::remove()
{
    arr.clear();
}

/**
     * Adds the input value to the list
     *
     * @param data The value that would be added to the List
     */
template <typename T>
void Vector<T>::add(T data)
{
    arr.push_back(data);
}

/**
     * Function that prints all the data from the list on the screen
     */
template <typename T>
void Vector<T>::print()
{
    for(int i=0;i<arr.size();i++)
        std::cout<<arr[i]<<" ";
    std::cout<<std::endl;
}
/**
     * Function that adds entered the element to the List
     *
     */
template <typename T>
void Vector<T>::Enter_element()
{
    T i;
    std::cin>>i;
    add(i);
}
/**
     * Function that adds entered the element to the List of type class Date_and_Time
     *
     */
template <>
inline void Vector<Date_and_Time>::Enter_element()
{
    Date_and_Time i1;
    int i;
    i=i1.Enter_element();
    if (i==2)
        add(i1);
    else
        std::cout<<"Invalid element!"<<std::endl;
}

/**
     * Function that prints all the data from the list on the screen of type class Date_and_Time
     */
template <>
inline void Vector<Date_and_Time>::print()
{
    int temp = arr.size();
    for(int i=0;i<temp;i++)
        arr[i].print();
    std::cout<<std::endl;
}

/**
     * Deletes the last element of the list
     */
template <typename T>
T Vector<T>::popTail()
{
    T n;
    if (arr.size()>0)
    {
        n=arr.back();
        arr.pop_back();
    }
    return n;
}

/**
     * Deletes the first element of the list
     */
template <typename T>
T Vector<T>::popHead()
{
    T n;
    if (arr.size()>0)
    {
        n=arr[0];
        for(int i=1;i<arr.size();i++)
            arr[i-1]=arr[i];
        arr.pop_back();
    }
    return n;
}

/**
     * Function thad return elements from position
     *
     * @param position
     * @return elements
     */
template <typename T>
T Vector<T>::element(int position)
{
    if (arr.size()>=position)
        return arr[position];
    T n;
    return n;
}
/**
    * Function that performs the quicksort algorithm
     *
     *@param a The start sorting
     *@param b The end sorting
    */
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
/**
     * Function that performs the insertion sort algorithm
     */
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

/**
     *The function that divides the array in two subarrays and then merges them into one in ascending order
     *
     * @param left The start of the first array
     * @param m The end of the first array and the start of the second array
     * @param right The end of the second array
     */
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
/**
    * Function that basically calls the merge function
    *
     * @param left The start sorting
     * @param right The end sorting
     *
     */
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

/**
     +* task
     *
     * Function that performs the heapsort algorithm
     *
     * @param n count of elements
     * @param i position of largest element
     */
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
/**
     +* task
     *
     *Function that basically calls the heap function
     */
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

/**
     +* task
     *
    * Function that performs the selection sort algorithm
    */
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

/**
     * Function that randomly generates the List of int
     */
template <typename T>
void Vector<T>::random()
{
    int r=rand()%10+5;
    for (int i=0;i<r;i++)
        add(rand());
}

template<typename T>
int Vector<T>::GetSize() {
    return this->arr.size();
}

/**
     * Function that randomly generates the List of double
     */
template <>
inline void Vector<double>::random()
{
    int r=rand()%10+5;
    for (int i=0;i<r;i++)
        add(1.123411*rand());
}

/**
     * Function that randomly generates the List of string
     */
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
/**
     * Function that randomly generates the List of class Date_and_Time
     */
template <>
inline void Vector<Date_and_Time>::random()
{
    int r=rand()%10+5;
    Date_and_Time t;
    for (int i=0;i<r;i++)
    {
        t.random();
        add(t);
    }
}

/**
     * Function thad return elements from position
     *
     * @param position
     * @return elements
     */
template <typename T>
std::string Vector<T>::get_element(int position)
{
    if (arr.size()>=position)
        return std::to_string(arr[position]);
    T n;
    return std::to_string(n);
}

template <>
inline std::string Vector<std::string>::get_element(int position)
{
    if (arr.size()>=position)
        return arr[position];
    std::string n;
    return n;
}

template <>
inline std::string Vector<Date_and_Time>::get_element(int position)
{
    if (arr.size()>=position)
    {
        std::string tempTime;
        std::string tempDate;
        tempTime = std::to_string(arr[position].T.get_hour()) + ":" + std::to_string(arr[position].T.get_minute()) + ":" + std::to_string(arr[position].T.get_second());
        tempDate = std::to_string(arr[position].D.get_day()) + "." + std::to_string(arr[position].D.get_month()) + "." + std::to_string(arr[position].D.get_year());
        return (tempTime + " " + tempDate);
    }
    std::string n;
    return n;
}
