#include<stdio.h>
#ifndef Queuecpp_h
#define Queuecpp_h


class node
{
public:
    node *lchild;
    int data;
    node *rchild;

};
class queue
{
private:
    int front;
    int rear;
    int size;
    node **Q;
public:
    queue(){front=rear=-1;size=10;Q=new node*[size];}
    queue(int size){front=rear=-1;this->size=size;Q=new node*[this->size];}
    void enqueue(node *x);
    node* dequeue();
    void display();
};

void queue::enqueue(struct node *x)
{
    if(rear==size-1)
        printf("queue full\n");
    else
        {
            rear++;
            Q[rear]=x;
        }
}

struct node* queue::dequeue()
{
    struct node* x=NULL;
    if(front==rear)
        printf("queeue is empty\n");
    else
    {
        x=Q[front+1];
        front++;
    }
    return x;
}

void queue::display()
{
    for(int i=front=i;i<=rear;i++)
        printf("%d",Q[i]);
    printf("\n");
}

#endif // Queue_h
