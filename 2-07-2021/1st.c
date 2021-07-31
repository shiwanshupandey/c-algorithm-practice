#include<stdio.h>
#include<stdlib.h>


struct stack
{

    int size;
    int top;
    int *S;

};

void create(struct stack *st)
{
    printf("enter size");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));

}

void Display(struct stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
        printf("%d ",st.S[i]);
    printf("\n");
}

void push(struct stack *st,int x)
{
    if(st->top==st->size-1)
        printf("stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}

int pop(struct stack *st)
{
    int x=-1;

    if(st->top==-1)
        printf("stack underflow\n");
    else
    {
        x=st->S[st->top--];
    }
    return x;
}

int peek(struct stack st,int index)
{

    int x=-1;
    if(st.top-index<+0)
        printf("invalid index \n");
    x=st.S[st.top-index+1];

    return x;


}

int isempty(struct stack st)
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}

int isfull(struct stack st)
{
    return st.top==st.size-1;
}

int stacktop(struct stack st)
{
    if(!isempty(st))
        return st.S[st.top];
    return -1;
}

int main()
{

    struct stack st;
    create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);

    printf("%d \n",isfull(st));
    Display(st);

    return 0;

}
