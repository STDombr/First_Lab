#include <iostream>

using namespace std;

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
    void remove()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }

    void add(T data)
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
            tail=node;
        }
        size++;
    }

    void print()
    {
        Node<T>* node = head;
        for(int i=0;i<size;i++)
        {
            cout << node->data << " ";
            node=node->next;
        }
    }

    void popTail()
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

    void popHead()
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
};

int main()
{
    List<int> Time;
    Time.add(4);
    Time.print();

}