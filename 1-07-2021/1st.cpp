#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class linkedlist
{
private:
    Node *first;
public:
    linkedlist(){first=NULL;}
    linkedlist(int A[],int n);
    ~linkedlist();

    void display();
    void insert(int index,int x);
    int Delete(int index);
    int lenght();
};

linkedlist::linkedlist(int A[], int n)
{
    Node *last,*t;
    int i=0;

    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

linkedlist::~linkedlist()
{
    Node *p=first;
    while(first)
    {
        first=first->next;
        delete p;
        p=first;
    }
}

void linkedlist::display()
{
    Node *p=first;

    while(p)
    {
        cout<<p->data<<"";
        p=p->next;
    }
    cout<<endl;
}

void linkedlist::insert(int index,int x)
{
    Node *t,*p=first;

    if(index <0|| index > lenght())
        return;
    t=new Node;
    t->data=x;
    t->next=NULL;

    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}

int linkedlist::lenght()
{
    Node *p=first;
    int len=0;

    while(p)
    {
        len++;
        p=p->next;

    }
    return len;

}

int linkedlist::Delete(int index)
{
    Node *p,*q=NULL;
    int x=-1;

    if(index < 1 || index > lenght())
        return -1;
    if(index==1)
    {
        p=first;
        first=first->next;
        x=p->data;
        delete p;
    }
    else
    {
        p=first;
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
    }
    return x;
}





int main()
{

    int A[]={1,2,3,4,5};
    linkedlist l(A,5);

    //cout<<l.lenght()<<endl;

    l.insert(2,10);

    l.display();



    return 0;
}
