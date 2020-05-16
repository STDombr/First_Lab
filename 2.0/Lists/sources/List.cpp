/**
 * 2nd Course K-28
 * Lab 1. Variant 2-9
 * Task: make a structure of Linked lists and realise different sort algorithms
 *
 *Purpose: this file contains all the methods that are written in the List.h
 *
 *@author Stanislav Dombrovskyi
 *@version 13/11/19
 */

#include <iostream>
#include <math.h>
#include "List.h"
#include "Date_and_Time.h"

/**
     * The default constructor
     */
template <typename T>
List<T>::List()
{
    head=NULL;
    tail=NULL;
    size=0;
}

/**
     * delete all elements
     */
template <typename T>
void List<T>::remove()
{
    head=NULL;
    tail=NULL;
    size=0;
}

/**
     * Adds the input value to the list
     *
     * @param data The value that would be added to the List
     */
template <typename T>
void List<T>::add(T data)
{
    Node<T>* node = new Node<T>;
    if (head==NULL)
    {
        node->data=data;
        node->prev=NULL;
        node->next=NULL;
        head=node;
        tail=node;
    }
    else
    {
        node->data=data;
        node->next=NULL;
        node->prev=tail;
        tail->next=node;
        tail=node;
    }
    size++;
}

/**
     * Function that prints all the data from the list on the screen
     */
template <typename T>
void List<T>::print()
{
    Node<T>* node = head;
    for(int i=0;i<size;i++)
    {
        std::cout << node->data << " ";
        node=node->next;
    }
    std::cout<<std::endl;
}

/**
     * Function that prints all the data from the list on the screen of type class Date_and_Time
     */
template <>
inline void List<Date_and_Time>::print()
{
    Node<Date_and_Time>* node = head;
    for(int i=0;i<size;i++)
    {
        node->data.print();
        node=node->next;
    }
    std::cout<<std::endl;
}

/**
     * Deletes the last element of the list
     */
template <typename T>
T List<T>::popTail()
{
    T n;
    if (head==NULL)
        return n;
    if (head==tail)
    {
        n=head->data;
        delete head;
        head=NULL;
        tail=NULL;
        size=0;
        return n;
    }
    n=tail->data;
    Node<T> *temp = tail;
    tail=tail->prev;
    delete temp;
    tail->next=NULL;
    size--;
    return n;
}
/**
     * Function that adds entered the element to the List
     *
     */
template <typename T>
void List<T>::Enter_element()
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
inline void List<Date_and_Time>::Enter_element()
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
     * Deletes the first element of the list
     */
template <typename T>
T List<T>::popHead()
{
    T n;
    if (head==NULL)
        return n;
    if (head==tail)
    {
        n=head->data;
        delete head;
        head=NULL;
        tail=NULL;
        size=0;
        return n;
    }
    n=head->data;
    Node<T> *temp=head;
    head=head->next;
    delete temp;
    head->prev=NULL;
    size--;
    return n;
}

/**
     * Function thad return elements from position
     *
     * @param position
     * @return elements
     */
template <typename T>
T List<T>::element(int position)
{
    Node<T> *temp=head;
    if (position<=size)
        for (int i=1;i<position;i++)
            temp=temp->next;
    return temp->data;
}

/**
     * Function thad return reference elements from position
     *
     * @param position
     * @return reference on elements
     */
template <typename T>
Node<T> *List<T>::elect_element(int position)
{
    Node<T> *temp=head;
    if (position<=size)
        for (int i=1;i<position;i++)
            temp=temp->next;
    return temp;
}

/**
    * Function that performs the quicksort algorithm
     *
     *@param a The start sorting
     *@param b The end sorting
    */
template <typename T>
void List<T>::quicksort(int a,int b)
{
    if (b==-2)
        b=size;
    int left=a,right=b;
    T piv=element((left+right)/2);
    while(left<=right)
    {
        while (piv>element(left))
            left++;
        while (element(right)>piv)
            right--;
        if (left<=right)
        {
            T temp2;
            temp2=elect_element(left)->data;
            elect_element(left)->data=elect_element(right)->data;
            elect_element(right)->data=temp2;
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
void List<T>::insertionsort()
{
    int i,j;
    T key;
    for (i=2;i<=size;i++)
    {
        key=element(i);
        j=i-1;
        while (j>=1 && element(j)>key)
        {
            elect_element(j+1)->data=elect_element(j)->data;
            j--;
        }
        elect_element(j+1)->data=key;
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
void List<T>::merge(int left,int m,int right)
{
    int i=1,j=1,k=left;
    int n1=m-left+1;
    int n2=right-m;
    List L,R;
    for (int y=1;y<=n1;y++)
        L.add(element(left+y-1));
    for (int y=1;y<=n2;y++)
        R.add(element(m+y));
    while (i<=n1 && j<=n2)
    {
        if (R.element(j)>L.element(i))
        {
            elect_element(k)->data=L.element(i);
            i++;
        }
        else
        {
            elect_element(k)->data=R.element(j);
            j++;
        }
        k++;
    }

    while (i<=n1)
    {
        elect_element(k)->data=L.element(i);
        i++;
        k++;
    }
    while (j<=n2)
    {
        elect_element(k)->data=R.element(j);
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
void List<T>::mergesort(int left,int right)
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
void List<T>::heap(int n,int i)
{
    int largest=i;
    int left=i*2+1;
    int right=i*2+2;
    if (left<n && element(left+1)>element(largest+1))
        largest=left;
    if (right<n && element(right+1)>element(largest+1))
        largest=right;
    if (largest!=i)
    {
        T temp;
        temp=elect_element(i+1)->data;
        elect_element(i+1)->data=elect_element(largest+1)->data;
        elect_element(largest+1)->data=temp;
        heap(n,largest);
    }
}
/**
     +* task
     *
     *Function that basically calls the heap function
     */
template <typename T>
void List<T>::heapsort()
{
    for (int i=size/2-1;i>=0;i--)
        heap(size,i);
    for (int i=size-1;i>=0;i--)
    {
        T temp;
        temp=elect_element(1)->data;
        elect_element(1)->data=elect_element(i+1)->data;
        elect_element(i+1)->data=temp;
        heap(i,0);
    }
}

/**
     +* task
     *
    * Function that performs the selection sort algorithm
    */
template <typename T>
void List<T>::selectionsort()
{
    int i,j,min;
    for (i=0;i<size-1;i++)
    {
        min=i;
        for (j=i+1;j<size;j++)
            if (element(min+1)>element(j+1))
                min=j;
        T temp;
        temp=elect_element(min+1)->data;
        elect_element(min+1)->data=elect_element(i+1)->data;
        elect_element(i+1)->data=temp;
    }
}

/**
     * Function thad return reference on head
     *
     * @return reference on elements
     */
template <typename T>
Node<T> *List<T>::gethead()
{
    return head;
}

/**
     * Function that randomly generates the List of int
     */
template <typename T>
void List<T>::random()
{
    int r=rand()%10+5;
    for (int i=0;i<r;i++)
        add(rand());
}

template<typename T>
int List<T>::GetSize() {
    return this->size;
}

/**
     * Function that randomly generates the List of double
     */
template <>
inline void List<double>::random()
{
    int r=rand()%10+5;
    for (int i=0;i<r;i++)
        add(1.123411*rand());
}

/**
     * Function that randomly generates the List of string
     */
template <>
inline void List<std::string>::random()
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
inline void List<Date_and_Time>::random()
{
    int r=rand()%10+5;
    Date_and_Time d;
    for (int i=0;i<r;i++)
    {
        d.random();
        add(d);
    }
}

/**
     * Function thad return elements from position
     *
     * @param position
     * @return elements
     */
template <typename T>
T List<T>::get_element(int position)
{
    Node<T> *temp=head;
    if (position<=size)
        for (int i=0;i<position;i++)
            temp=temp->next;
    return temp->data;
}
