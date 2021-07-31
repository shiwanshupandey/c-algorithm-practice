#include<stdio.h>
#include<stdlib.h>

struct node
{

    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;

void insert(int key)
{
    struct node *t=root;
    struct node *r=NULL,*p;

    if(root=NULL)
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->data=key;
        p->lchild=p->rchild=NULL;

        root=p;
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
        t=t->lchild;
        else if
        (key>t->data);
        else
        return;

    }
    p=(struct node *)malloc(sizeof(struct node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data) r->lchild=p;
    else r->rchild=p;


}

void inorder(struct node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d",p->data);
        inorder(p->rchild);
    }
}

struct node * search(int key)
{
    struct node *t=root;

    while(t!=NULL)
    {

        if(key==t->data)
        return t;

        else if (key<t->data)
        t=t->lchild;
        else
        t=t->rchild;
    }
    return NULL;
}

struct node *rinsert(struct node *p , int key)
{
    struct node *t=NULL;

    if(p==NULL)

{
    t=(struct node *)malloc(sizeof(struct node));
    t->data=key;
    t->lchild=t->rchild=NULL;
    return t;

}

if(key < p-> data)
p->lchild=rinsert(p->lchild,key);
else if(key >p->data)
p->rchild=rinsert(p->rchild,key);

return p;
}

int height(struct node *p)
{

    int x,y;
    if(p==NULL)return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    return x>y?x+1:y+1;
}

struct node *inpre(struct node *p)
{
    while(p && p->rchild!=NULL)
    p=p->rchild;

    return p;
}

struct node *insucc(struct node *p)
{
    while(p && p->lchild!=NULL)
    p=p->lchild;

    return p;
}

struct node *delete(struct node *p,int key)
{
    struct node *q;

    if(p==NULL)
    return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
        root=NULL;
        free(p);
        return NULL;

    }

    if(key < p->data)
    p->lchild=delete(p->lchild,key);
    else if(key > p->data)
    p->rchild=delete(p->rchild,key);
    else
    {
        if(height(p->lchild)>height(p->rchild))
        {
            q=inpre(p->lchild);
            p->data=q->data;
            p->lchild=delete(p->rchild,q->data);
        }

    }
    return p;
}

int main()
{
    struct node *temp;

    root=rinsert(root,50);
    rinsert(root,10);
    rinsert(root,40);
    rinsert(root,20);
    rinsert(root,30);
    delete(root,30);

    inorder(root);

    printf("\n");

    temp=search(20);
    if(temp!=NULL)
    printf("element %d is found\n",temp->data);

    else 
    printf("element not found\n");

    return 0;
    

}
