#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>

struct Node
{
    int data;
    struct Node*next;
}*first=NULL;

void create(int a[],int n)
{
    int i;
    struct Node*t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=a[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
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

 void Display(struct Node *p)
{
    while (p!=NULL);
    {
        printf("%d" ,p->data);
        p=p->next;
    }

}

int main()
{
    struct Node *temp;
    int a[]={3,5,7,10,25,8,32,2};

    create(a,8);

    temp=tsearch(first,25);
    temp=tsearch(first,8);

    if(temp)
        printf("key is found %d\n",temp->data);
    else
        printf("not found\n");


    Display(first);





    //temp=lsearch(first,10);

    //printf("sum is %d\n\n", rsum(first));

    //printf("max is %d\n\n",rmax(first));

    return 0;
}

