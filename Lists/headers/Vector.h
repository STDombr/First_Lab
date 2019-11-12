#ifndef FIRST_LAB_VECTOR_H
#define FIRST_LAB_VECTOR_H
#include "Interface.h"
#include "vector"

//Клас, на основі масиву, організовані алгоритми сортування
template <typename T>
class Vector : public Interface<T>
{
private:
    std::vector<T> arr;
public:
    //конструктор для класу Array
    Vector();
    //функція для видалення всієї інформації
    void remove();
    //функція для добавляння одного елемента
    void add(T);
    //функція для виведення всього класу
    void print();
    //функція для видалення елемента tail
    void popTail();
    //функція для видалення елемента head
    void popHead();
    //функція для повернення елемента з і індексом
    T element(int);
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
    //функція для рандомного заповнення елементів
    void random();
};


#endif //FIRST_LAB_VECTOR_H
