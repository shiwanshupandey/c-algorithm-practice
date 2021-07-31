#include<stdio.h>
#include<stdlib.h>
#ifndef Queue_h
#define Queue_h
#endif // Queue_h


struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct queue
{
    int size;
    int front;
    int rear;
    node **Q;
};

void create(struct queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(node **)malloc(q->size*sizeof(node *));
}

void enqueue(struct queue *q,node *x)
{
    if((q->rear+1)%q->size==q->front)
        printf("queue is full");
    else
        {
            q->rear=(q->rear+1)%q->size;
            q->Q[q->rear]=x;
        }
}

node * dequeue(struct queue *q)
{
    node* x=NULL;

    if(q->front==q->rear)
        printf("queue is empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
