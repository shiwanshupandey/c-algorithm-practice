#include<stdio.h>
#include<stdlib.h>
#include<math.h>


struct Node
{
    int coeff;
    int exp;
    struct node *next;

}*poly=NULL;

void create()
{
    struct Node *t,*last=NULL;
    int num,i;

    printf("enter number of terms");
    scanf("%d",&num);
    printf("enter each term with coeff and exp\n");

    for(i=0;i<num;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d",&t->coeff,&t->exp);
        t->next=NULL;
        if(poly=NULL)
        {
            poly=last=t;

        }
        else
        {
            last->next=t;
            last=t;
        }

    }
}

void display(struct Node *p)
{
    while(p)
    {
        printf("%dx%d +",p->coeff,p->exp);
        p=p->next;
    }
    printf("\n");

}

long eval(struct Node *p,int x)
{
    long val=0;

    while(p)
    {
        val+=p->coeff*pow(x,p->exp);
        p=p->next;
    }
    return val;
}


int main()
{
    create();
    display(poly);
    printf("%ld\n",eval(poly,1));

    return 0;
}
