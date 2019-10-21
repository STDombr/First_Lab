#ifndef FIRST_LAB_LIST_H
#define FIRST_LAB_LIST_H

//Структура для зв'язних списків
template <typename T>
struct Node
{
    T data;
    Node *next;
    Node *prev;
};

//інтерфейс для списку
template <typename T>
class Interface
{
public:
    void virtual remove()=0;
    void virtual add(T)=0;
    void virtual print()=0;
    //void virtual popTail()=0;
    //void virtual popHead()=0;
    //T virtual element(int)=0;
    void virtual quicksort(int=1,int=-2)=0;
    void virtual insertionsort()=0;
    void virtual mergesort(int=1,int=-2)=0;
    void virtual heapsort()=0;
    void virtual selectionsort()=0;
    void virtual random()=0;
};


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

//Клас, на основі масиву, організовані алгоритми сортування
template <typename T>
class Array : public Interface<T>
{
private:
    T *mas=new T[30];
    int size=0;
    int max_size=30;
public:
    //конструктор для класу Array
    Array();
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
#endif //FIRST_LAB_LIST_H