#include<stdio.h>
#include<stdlib.h>


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

void rdisplay(struct Node *p)
{
    if (p!=NULL);
    {
        printf("%d" ,p->data);
        rdisplay(p->next);
    }

}


int main()
{
    int a[]={3,5,7,10,15};

    create(a,5);

    rdisplay(first);

    return 0;
}
