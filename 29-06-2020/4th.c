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



int main()
{
    int a[]={3,5,7,10,15,8,12,2};

    create(a,8);

    //printf("sum is %d\n\n", rsum(first));

    printf("max is %d\n\n",rmax(first));

    return 0;
}

