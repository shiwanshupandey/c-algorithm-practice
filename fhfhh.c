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
int main()
{
    struct Array arr={{2,3,4,5,6},10,5};

    printf("%d\n",BinarySearch(arr,2));
    Display(arr);

    return 0;
 }

