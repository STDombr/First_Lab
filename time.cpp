#include <iostream>
#include <vector>

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

    void insertionsort()
    {
        int i,key,j;
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

    void merge(int left,int m,int right)
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
            if (L.element(i)<R.element(j))
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

    void mergesort(int left=1,int right=-2)
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

    void heap(int n,int i)
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

    void heapsort()
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

    void selectionsort()
    {
        int i,j,min;
        for (i=0;i<size-1;i++)
        {
            min=i;
            for (j=i+1;j<size;j++)
                if (element(j+1)<element(min+1))
                    min=j;
            T temp;
            temp=elect_element(min+1)->data;
            elect_element(min+1)->data=elect_element(i+1)->data;
            elect_element(i+1)->data=temp;
        }
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
    Time.selectionsort();
    Time.print();

}