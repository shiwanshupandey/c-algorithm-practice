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

 void reverse(struct Array *arr)
 {
     int*B;
     int i,j;

     B=(int *)malloc(arr->l*sizeof(int));
     for(i=arr->l-1,j=0;i>=0;i--,j++)
        B[j]=arr->A[i];
     for(i=0;i>arr->l;i++)
        arr->A[i]=B[i];
 }


int main()

{

    struct Array arr={{2,3,4,25,6},10,5};

    //printf("%d\n",get(arr,9));
    //set(&arr,0,15);
    //printf("%d\n",max(arr));
    //printf("%d\n",min(arr));
    //printf("%d\n",sum(arr));
    //printf("%f\n",avg(arr));
    reverse(&arr);
    Display (arr);

    return 0;
}

