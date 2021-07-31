#include <stdio.h>


struct Array
{
    int A[10];
    int size;
    int l ;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.l;i++)
        printf("%d ",arr.A[i]);
}

void Append(struct Array *arr,int x)
{
    if(arr->l<arr->size)
        arr->A[arr->l++]=x;
}



void Insert(struct Array *arr,int index, int x)
{
    int i;

    if(index>=0 && index <=arr->l)
    {
        for(i=arr->l;i>index;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->l++;
    }
}


int main()
{
    struct Array arr1={{2,3,4,5,6},10,5};
    Append(&arr1,10);
    Insert(&arr1,0,12);
    Display(arr1);

    return 0;
 }
