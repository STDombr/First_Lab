#ifndef FIRST_LAB_LIST_H
#define FIRST_LAB_LIST_H

template <typename T>
struct Node
{
    T data;
    Node *next;
    Node *prev;
};

template <typename T>
class List
{
private:
    Node<T> *head,*tail;
    int size;
public:
    List();
    void remove();
    void add(T);
    void print();
    void popTail();
    void popHead();
    T element(int);
    Node<T> *elect_element(int);
    void quicksort(int=1,int=-2);
    void insertionsort();
    void merge(int, int, int);
    void mergesort(int=1,int=-2);
    void heap(int,int);
    void heapsort();
    void selectionsort();
};

#endif //FIRST_LAB_LIST_H