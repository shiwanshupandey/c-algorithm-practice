#include <stdio.h>


struct array
{
    int *A;
    int size;
    int lenght;
};

void diplay(struct array arr)
{
    int i ;
    printf("\n element are\n");
    for(i=0;i<arr.lenght;i++)
        printf("%d",arr.A[i]);
}

int main
{
    struct array arr;
    int n,i;
    printf("enter size of an array");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(arr.size*sizeof(int));
    arr.lenght=0;

    printf("enter number of numbers");
    scanf("%d",&n);

    printf("enter all elements\n")
    for(i=0;i<n;i++)
      scanf("%d",&arr.A[i]);
    arr.lenght=n;

    display(arr);

    return 0;
 }
