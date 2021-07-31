#include <stdio.h>
#include <stdlib.h>




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

void Display(struct Node *p)
{
    while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
}

void Merge(struct Node *p,struct Node *q)
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
                if(p->data < q->data)
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

int main()
{
    int A[]={10,20,30};
    int B[]={1.2,3};
    create(A,3);
    create(B,3);


    Merge(first,second);
    Display(third);


    return 0;
}
