#include<iostream>
#include<stdio.h>
#include "Queuecpp.h"
using namespace std;

class tree
{
    node *root;

public:
    tree(){root=NULL;}
    void createtree();
    void preorder(){preorder(root);}
    void preorder(node *p);
    void postorder(){postorder(root);}
    void postorder(node *p);
    void inorder(){inorder(root);}
    void inorder(node *p);
    void levelorder(){levelorder(root);}
    void levelorder(node *p);
    int height(){return height (root);}
    int height(node *root);
};

void tree::createtree()
{
    node *p,*t;
    int x;
    queue q(100);

    printf("enter root value");
    scanf("%d",&x);
    root=new node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p=q.dequeue();
        printf("enter left child of %d",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=new node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        printf("enter right child of %d",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=new node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}

void tree::preorder(struct node *p)
{
    if(p)
    {
        printf("%d",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void tree::inorder(struct node *p)
{
    if(p)
    {

        inorder(p->lchild);
        printf("%d",p->data);
        inorder(p->rchild);
    }
}
void tree::postorder(struct node *p)
{
    if(p)
    {

        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d",p->data);
    }
}

void tree::levelorder(struct node *root)
{
    queue q(100);

    printf("%d",root->data);
    q.enqueue(root);

    while(!q.isEmpty())
    {
        root=q.dequeue();
        if(root->lchild)
        {
            printf("%d",root->lchild->data);
            q.enqueue(root->rchild);
        }
    }
}

int tree::height(struct node *root)
{
    int x=0,y=0;
    if(root==0)
        return 0;
    x=height(root->lchild);
    y=height(root->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}

int main()
{
    tree t;
    t.createtree();
    cout<<"preorder";
    t.preorder();
    cout<<endl;
    cout<<"inorder ";
    t.inorder();
    cout<<endl<<endl;

    return 0;
}
