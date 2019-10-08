#include <iostream>
#include <math.h>
#include "List.h"
#include "Time.cpp"

//конструктор для класу List
template <typename T>
List<T>::List()
{
    head=NULL;
    tail=NULL;
    size=0;
}

//функція для видалення всієї інформації
template <typename T>
void List<T>::remove()
{
    head=NULL;
    tail=NULL;
    size=0;
}

//функція для добавляння одного листа
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

//функція для виведення всього класу
template <typename T>
void List<T>::print()
{
    Node<T>* node = head;
    std::cout<<std::endl;
    for(int i=0;i<size;i++)
    {
        std::cout << node->data << " ";
        node=node->next;
    }
    std::cout<<std::endl;
}

template <>
inline void List<Time<int>>::print()
{
    Node<Time<int>>* node = head;
    std::cout<<std::endl;
    for(int i=0;i<size;i++)
    {
        node->data.print();
        node=node->next;
    }
    std::cout<<std::endl;
}

template <>
inline void List<Date<int>>::print()
{
    Node<Date<int>>* node = head;
    std::cout<<std::endl;
    for(int i=0;i<size;i++)
    {
        node->data.print();
        node=node->next;
    }
    std::cout<<std::endl;
}

//функція для видалення листа tail
template <typename T>
void List<T>::popTail()
{
    if (head==NULL)
        return;
    if (head==tail)
    {
        delete head;
        head=NULL;
        tail=NULL;
        size=0;
        return;
    }
    Node<T> *temp = tail;
    tail=tail->prev;
    delete temp;
    tail->next=NULL;
    size--;
}

//функція для видалення листа head
template <typename T>
void List<T>::popHead()
{
    if (head==NULL)
        return;
    if (head==tail)
    {
        delete head;
        head=NULL;
        tail=NULL;
        size=0;
        return;
    }
    Node<T> *temp=head;
    head=head->next;
    delete temp;
    head->prev=NULL;
    size--;
}

//функція для повернення елемента з і індексом
template <typename T>
T List<T>::element(int position)
{
    Node<T> *temp=head;
    if (position<=size)
        for (int i=1;i<position;i++)
            temp=temp->next;
    return temp->data;
}

//функція для повернення листа з і інлексом
template <typename T>
Node<T> *List<T>::elect_element(int position)
{
    Node<T> *temp=head;
    if (position<=size)
        for (int i=1;i<position;i++)
            temp=temp->next;
    return temp;
}

//алгоритм сортування quicksort
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

//алгоритм сортування insertionsort
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

//алгоритм сортування mergesort
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

//алгоритм сортування heapsort
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

//алгоритм сортування selectionsort
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

//функція для повернення покажчика на head
template <typename T>
Node<T> *List<T>::gethead()
{
    return head;
}

//функція для рандомного заповнення елементів
template <typename T>
void List<T>::random()
{
    int r=rand()%10+5;
    for (int i=0;i<r;i++)
        add(rand());
}

template <>
inline void List<double>::random()
{
    int r=rand()%10+5;
    for (int i=0;i<r;i++)
        add(1.1*rand());
}

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

template <>
inline void List<Time<int>>::random()
{
    int r=rand()%10+5;
    Time<int> t;
    for (int i=0;i<r;i++)
    {
        t.random();
        add(t);
    }
}

template <>
inline void List<Date<int>>::random()
{
    int r=rand()%10+5;
    Date<int> d;
    for (int i=0;i<r;i++)
    {
        d.random();
        add(d);
    }
}

template <typename T>
Array<T>::Array()
{
    T *mas=new T[30];
    size=0;
    max_size=30;
}

template <typename T>
void Array<T>::remove()
{
    T *mas=new T[30];
    size =0;
    max_size=30;
}

//функція для добавляння одного листа
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

//функція для виведення всього класу
template <typename T>
void Array<T>::print()
{
    std::cout<<std::endl;
    for(int i=0;i<size;i++)
        std::cout<<mas[i]<<" ";
    std::cout<<std::endl;
}

template <>
inline void Array<Time<int>>::print()
{
    std::cout<<std::endl;
    for(int i=0;i<size;i++)
        mas[i].print();
    std::cout<<std::endl;
}

template <>
inline void Array<Date<int>>::print()
{
    std::cout<<std::endl;
    for(int i=0;i<size;i++)
        mas[i].print();
    std::cout<<std::endl;
}

//функція для видалення елемента tail
template <typename T>
void Array<T>::popTail()
{
    if (size>=1)
    {
        size--;
    }
}

//функція для видалення елемента head
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

//
template <typename T>
T Array<T>::element(int position)
{
    if (size>=position)
        return mas[position-1];
    return 0;
}

//алгоритм сортування quicksort
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

//алгоритм сортування insertionsort
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

//алгоритм сортування mergesort
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

//алгоритм сортування heapsort
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

//алгоритм сортування selectionsort
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

//функція для рандомного заповнення елементів
template <typename T>
void Array<T>::random()
{
    int r=rand()%10+5;
    for (int i=0;i<r;i++)
        add(rand());
}

template <>
inline void Array<double>::random()
{
    int r=rand()%10+5;
    for (int i=0;i<r;i++)
        add(1.1*rand());
}

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

template <>
inline void Array<Time<int>>::random()
{
    int r=rand()%10+5;
    Time<int> t;
    for (int i=0;i<r;i++)
    {
        t.random();
        add(t);
    }
}

template <>
inline void Array<Date<int>>::random()
{
    int r=rand()%10+5;
    Date<int> d;
    for (int i=0;i<r;i++)
    {
        d.random();
        add(d);
    }
}