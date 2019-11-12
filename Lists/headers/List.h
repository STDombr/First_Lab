#ifndef FIRST_LAB_LIST_H
#define FIRST_LAB_LIST_H
#include "Interface.h"

//Клас, на основі зв'язних списків організовані алгоритми сортування
template <typename T>
class List : public Interface<T>
{
private:
    Node<T> *head,*tail;
    int size;
public:
    //конструктор для класу List
    List();
    //функція для видалення всієї інформації
    void remove();
    //функція для добавляння одного листа
    void add(T);
    //функція для виведення всього класу
    void print();
    //функція для видалення листа tail
    void popTail();
    //функція для видалення листа head
    void popHead();
    void Enter_element();
    //функція для повернення елемента з і індексом
    T element(int);
    //функція для повернення листа з і інлексом
    Node<T> *elect_element(int);
    //алгоритм сортування quicksort
    void quicksort(int=1,int=-2);
    //алгоритм сортування insertionsort
    void insertionsort();
    //алгоритм сортування mergesort
    void merge(int, int, int);
    void mergesort(int=1,int=-2);
    //алгоритм сортування heapsort
    void heap(int,int);
    void heapsort();
    //алгоритм сортування selectionsort
    void selectionsort();
    //функція для повернення покажчика на head
    Node<T> *gethead();
    //функція для рандомного заповнення елементів
    void random();
};

#endif //FIRST_LAB_LIST_H