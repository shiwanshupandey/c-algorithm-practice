#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int l;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.l;i++)
        printf("%d ",arr.A[i]);
}
void swap(int *x,int *y)
{
    int temp=*x; *x=*y; *y=temp;
}


int get(struct Array arr, int index)

{
    if(index>=0 && index<arr.l)
        return arr.A[index];
    return -1;
}

void set(struct Array *arr,int index,int x)
{
    if(index>=0 && index<arr->l);
        arr->A[index]=x;
}

int max(struct Array arr)
{
    int max=arr.A[0];
    int i;
    for(i=1;i<arr.l;i++)
    {
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;
}

int min(struct Array arr)
{
    int min=arr.A[0];
    int i;
    for(i=1;i<arr.l;i++)
    {
        if(arr.A[i]<min)
            min=arr.A[i];
    }
    return min;
}

int sum(struct Array arr)
{

    int s=0;
    int i;
    for(i=0;i<arr.l;i++)
        s+=arr.A[i];

    return s;
}

float avg(struct Array arr)
{
    return (float)sum(arr)/arr.l;

}

int main()

{

    struct Array arr={{2,3,4,25,6},10,5};

    //printf("%d\n",get(arr,9));
    //set(&arr,0,15);
    //printf("%d\n",max(arr));
    //printf("%d\n",min(arr));
    //printf("%d\n",sum(arr));
    printf("%f\n",avg(arr));
    Display (arr);

    return 0;
}
