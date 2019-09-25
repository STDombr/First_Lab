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
    Node<T> *head=NULL,*tail=NULL;
    int size=0;
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
            tail->next=node;
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

    T element(int position)
    {
        Node<T> *temp=head;
        if (position<=size)
            for (int i=1;i<position;i++)
                temp=temp->next;
        return temp->data;
    }

    Node<T> *elect_element(int position)
    {
        Node<T> *temp=head;
        if (position<=size)
            for (int i=1;i<position;i++)
                temp=temp->next;
        return temp;
    }

    void quicksort(int a=1,int b=-2)
    {
        if (b==-2)
            b=size;
        int left=a,right=b;
        T piv=element((left+right)/2);
        while(left<=right)
        {
            while (element(left)<piv)
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
};

int main()
{
    int a,n;
    cin>>n;
    List<int> Time;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        Time.add(a);
    }
    Time.quicksort();
    Time.print();

}