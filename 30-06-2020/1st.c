#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;


    for(i=1;i<n;i++)
        {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=A[i];
            t->next=NULL;
            last->next=t;
            last=t;
        }
}

void create2(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=second;


    for(i=1;i<n;i++)
        {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=A[i];
            t->next=NULL;
            last->next=t;
            last=t;
        }
}

void create3(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=third;


    for(i=1;i<n;i++)
        {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=A[i];
            t->next=NULL;
            last->next=t;
            last=t;
        }
}

void Display(struct Node *p)
{
    while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
}

int count(struct Node *p)
{
    int l=0;
    while(p)
        {
            l++;
            p=p->next;
    }
    return l;
}

int rcount(struct Node *p)
{

    if(p!=NULL)
        return rcount(p->next)+1;
    else
        return 0;
}

int sum(struct Node *p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}

int rsum(struct Node*p)
{
    if(p==NULL)
        return 0;
    else
        return rsum(p->next)+p->data;
}

int max(struct Node *p)
{
    int max = INT32_MIN;
    //int max=-32768;MIN_INT;

    while(p)
    {
        if(p->data>max)
            max=p->data;
        p=p->next;
    }
    return max;
}

int rmax(struct Node *p)
{
    int x=0;
    if(p==0)
       return INT32_MIN;
    else
    {
        x=max(p->next);
        if(x>p->data)
            return x;
        else
            return p->data;
    }
}

struct node* rsearch(struct Node *p,int key)
{
    if(p==NULL)
        return NULL;
    else if(key==p->data)
        return p;
    else
    return rsearch(p->next,key);

}

struct node* lsearch(struct Node *p,int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
            return p;
        else
            p=p->next;
    }
}

struct Node* tsearch(struct Node *p,int key)
 {

     struct Node *q;

     while(p!=NULL)
     {
         q=p;
         if(key==p->data)
         {
             q->next=p->next;
             p->next=first;
             first=p;

             return p;
         }
         p=p->next;
     }
     return NULL;
 }

void Insert(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;
    if(index < 0 || index > count(p))
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(index == 0)
        {
            t->next=first;
    first=t;
    }
    else
        {
            for(i=0;i<index-1;i++)
            p=p->next;
            t->next=p->next;
            p->next=t;

            }

            }

void sinsert(struct Node *p,int x)
{
    struct Node *t,*q=NULL;

    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first=NULL)
        first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;

        }
    }
}

int delete(struct Node *p,int index)
{
    struct Node *q=NULL;
    int x=-1,i;

    if(index < 1 || index > count (p))
        return -1;
    if (index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;

    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;

    }
}

int issorted(struct Node *p)
{
    int x = -65536;

    while(p!=NULL)
    {
        if(p->data < x )
            return 0;
        x=p->data;
        p=p->next;

    }
    return 1;

}

void rmduplicate(struct Node *p)
{
    struct Node *q=p->next;

    while(q!=NULL)
        {
            if(p->data!=q->data)
            {
                p=q;
                q=q->next;
                }
                else
                    {
                        p->next=q->next;
                        free(q);
                        q=p->next;
                    }

        }
}

void reverse1(struct Node *p)
{
    int *a,i=0;
    struct Node *q=p;
    a=(int *)malloc(sizeof(int)*count(p));


    while(q!=NULL)
        {
            a[i]=q->data;
            q=q->next;
            i++;

        }
        q=p;
        i--;

        while(q!=NULL)
        {
            q->data=a[i];
            q=q->next;
            i--;
        }
}

void reverse2(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void reverse3(struct Node *q,struct Node *p)
{
    if(p)
    {
        reverse3(p,p->next);
        p->next=q;
    }
    else
        first=q;
}

void concat (struct Node *p,struct Node *q)
{
    third=p;

    while(p->next!=NULL)
        p=p->next;
    p->next=q;
}

void merge(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q)
    {
        if(p->data < q-> data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;

        }
    }
    if(p)last->next=p;
    if(q)last->next=q;

}

int isloop(struct Node *f)
{
    struct Node *p,*q;
    p=q=f;

    do
        {
            p=p->next;
            q=q->next;
            q=q?q->next:q;

        }
        while(p && q && p!=q);

        if(p==q)
            return 1;
        else
            return 0;
}


int main()
{
    struct Node *t1,t2;
    int A[]={10,20,30,40,50};
    create(A,5);

    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;

    printf("%d\n",isloop(first));


    return 0;
}
