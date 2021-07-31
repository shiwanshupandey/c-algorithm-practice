#include <stdio.h>
#include<stdlib.h>

struct Array
{
    int *A;
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

int Delete(struct Array *arr,int index)
{
    int x=0;
    int i;

    if(index>=0 && index <arr->l)
    {
        x=arr->A[index];
        for(i=index;i<arr->l-1;i++)
            arr->A[i]=arr->A[i+1];
        arr->l--;
        return x;
    }
}

void swap(int *x,int *y)
{
    int temp=*x; *x=*y; *y=temp;
}

int LinearSearch(struct Array *arr,int Key)
{
    int i;
    for(i=0;i<arr->l;i++)
    {
        if(Key==arr->A[i])
        {
            swap(&arr->A[i],&arr->A[i-1]);
            return i;
            }
    }
    return -1;
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

int BinarySearch(struct Array arr,int Key)
{
    int c,mid,h;
    c=0;
    h=arr.l-1;

    while(c<=h)
    {
        mid=(c+h)/2;
        if(Key==arr.A[mid])
            return mid;
        else if(Key<arr.A[mid])
            h=mid-1;
        else
            c=mid+1;
    }
    return -1;
}


int RBinSearch(int a[],int c,int h, int Key)
{
    int mid;

    if(c<=h)
       {
           mid=(c+h)/2;
           if(Key==a[mid])
            return mid;
    else if (Key<a[mid])
        return RBinSearch(a,c,mid-1,Key);
    else
        return RBinSearch(a,mid+1,h,Key);
       }
       return -1;
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


void reversetwo(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->l-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
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
        else if (arr2->A[i]<arr1->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
            j++;

        }
    }
    arr3->l=k;
    arr3->size=10;

    return arr3;

}


struct Array* difference(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->l && j<arr2->l)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if (arr2->A[j]<arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for(;i<arr1->l;i++)
        arr3->A[k++]=arr1->A[i];
    arr3->l=k;
    arr3->size=10;

    return arr3;

}

int main()
{
    struct Array arr1;
    int ch;
    int x,index;

    printf("Enter Size of Array");
    scanf("%d",&arr1.size);
    arr1.A=(int *)malloc(arr1.size*sizeof(int));
    arr1.l=0;
do {
        printf("\n\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. avg\n");
        printf("6. max\n");
        printf("7. min\n");
        printf("8. Display\n");
        printf("9.Exit\n");

        printf("enter you choice ");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                printf("Enter an element and index ");
                scanf("%d%d",&x,&index);
                Insert(&arr1,index,x);
                break;
            case 2:
                printf("Enter index ");
                scanf("%d",&index);
                x=Delete(&arr1,index);
                printf("Deleted Element is %d\n",x);
                break;
            case 3:
                printf("Enter element to search ");
                scanf("%d",&x);
                index=LinearSearch(&arr1,x);
                printf("Element index %d",index);
                break;
            case 4:
                printf("Sum is %d\n",sum(arr1));
                break;
            case 5:
                printf("avg is %f\n",avg(arr1));
                break;
            case 6:
                printf("max is %d\n",max(arr1));
                break;
            case 7:
                printf("min is %d\n",min(arr1));
                break;
            case 5:
                Display(arr1);

                        }
    }
    while(ch<6);
    return 0;
}
