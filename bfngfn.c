#include <stdio.h>
#include<stdlib.h>

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

void reverse2(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->l-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}

void insertsort(struct Array *arr,int x)
{
    int i=arr->l-1;
    if(arr->l==arr->size)
        return;
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->l++;

}

int issorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.l-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
}

void rearrange(struct Array *arr)
{
    int i,j;
    i=0;
    j=arr->l-1;

    while(i<j)
    {
        while(arr->A[i]<0)i++;
        while(arr->A[i]>=0)j--;
        if(i<j)swap(&arr->A[i],&arr->A[j]);
    }
}


struct Array* merge(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->l && j<arr2->l)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->l;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr1->l;j++)
        arr3->A[k++]=arr1->A[j];
    arr3->l=arr1->l+arr2->l;
    arr3->size=10;

    return arr3;

}

struct Array* Union(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->l && j<arr2->l)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if (arr2->A[j]<arr1->A[i])
            arr3->A[k++]=arr2->A[j++];
        else
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->l;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr1->l;j++)
        arr3->A[k++]=arr1->A[j];
    arr3->l=k;
    arr3->size=10;

    return arr3;

}

struct Array* intersection(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->l && j<arr2->l)
    {
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if (arr2->A[j]<arr1->A[i])
            j++;
        else if (arr2->A[j]<arr1->A[i])
        {
            arr3->A[k++]=arr1->A[i++];
            j++;

        }
    }
    arr3->l=k;
    arr3->size=10;

    return arr3;

}

int main()

{

    struct Array arr1={{2,6,10,15,25},10,5};
    struct Array arr2={{3,10,6,18,20},10,5};
    struct Array *arr3;

    //arr3=Union(&arr1,&arr2);

    //printf("%d\n",get(arr,9));
    //set(&arr,0,15);
    //printf("%d\n",max(arr));
    //printf("%d\n",min(arr));
    //printf("%d\n",sum(arr));
    //printf("%f\n",avg(arr));
    //reverse2(&arr);
    //insertsort(&arr,12);
    //printf("%d \n",issorted(arr));
    //rearrange(&arr);

    arr3=intersection(&arr1,&arr2);
    Display (*arr3);

    return 0;
}

