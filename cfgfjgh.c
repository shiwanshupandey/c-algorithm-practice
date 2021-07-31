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
void swap (int *x,int*y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int LinearSearch(struct Array *arr,int Key)
{
    int i;
    for(i=0;i<arr.l;i++)
    {
        if(Key==arr->A[i])
        {
            swap(&arr->A[i],&arr->A[i-1]);
            return i;
            }
    }
    return -1;
}

int main()
{
    struct Array arr={{2,3,4,5,6},10,5};

    printf("%d\n",LinearSearch(arr,5));
    Display(arr);

    return 0;
 }
