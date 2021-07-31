#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct node *root=NULL;

void treecreate()
{
    struct node *p,*t;
    int x;
    struct queue q;
    create (&q,100);

    printf("enter root value");
    scanf("%d",&x);
    root=(struct node *)malloc(sizeof(struct node ));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q, root);

    while(!isempty(q))
    {
        p=dequeue(&q);
        printf("enter left child of %d",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct node*)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("enter right child of %d",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct node*)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}

void Ipostorder(struct node *p)
{
    struct stack stk;
    long int temp;
    stackcreate(&stk,100);

    while(p!=NULL || !isEmptystack(stk))
    {
        if(p)
        {
            push(&stk,p);
            p=p->lchild;
        }
        else
        {
            temp=pop(&stk);
            if(temp>0)
            {
                push(&stk,--temp);
                p=((struct node*)temp)->rchild;
            }
            printf("%d",((struct node *)temp)->data);
            p=NULL;
        }
    }
}

void preorder(struct node  *p)
{
    if(p)
    {
        printf("%d",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }

}

void inorder(struct node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d", p->data);
        inorder(p->rchild);
    }
}
void postorder(struct node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d",p->data);
    }
}

int main()
{

    treecreate();
    preorder(root);
    printf("\npost order ");
    preorder(root);

    return 0;

}
