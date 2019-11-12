#ifndef FIRST_LAB_INTERFACE_H
#define FIRST_LAB_INTERFACE_H

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
    void virtual popTail()=0;
    void virtual popHead()=0;
    void virtual Enter_element()=0;
    //T virtual element(int)=0;
    void virtual quicksort(int=1,int=-2)=0;
    void virtual insertionsort()=0;
    void virtual mergesort(int=1,int=-2)=0;
    void virtual heapsort()=0;
    void virtual selectionsort()=0;
    void virtual random()=0;
};


#endif //FIRST_LAB_INTERFACE_H
