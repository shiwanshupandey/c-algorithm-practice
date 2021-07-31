#include <stdio.h>
#include<stdlib.h>
#define __STDC_LIMIT_MACROS
#include <stdint.h>
void swap(int *x,int *y)
{
int temp=*x;
*x=*y;
*y=temp;
}
void Merge(int A[],int l,int mid,int h)
{
int i=l,j=mid+1,k=l;
int B[100];
while(i<=mid && j<=h)
{
if(A[i]<A[j])
B[k++]=A[i++];
else
B[k++]=A[j++];
}
for(;i<=mid;i++)
B[k++]=A[i];
for(;j<=h;j++)
B[k++]=A[j];
for(i=l;i<=h;i++)
A[i]=B[i];
}
void MergeSort(int A[],int l,int h)
{
int mid;
if(l<h)
{
mid=(l+h)/2;
MergeSort(A,l,mid);
MergeSort(A,mid+1,h);
Merge(A,l,mid,h);
}
}
int findmax(int A[],int n)
{
    int max=INT32_MIN;
    int i;
    for(i=0;i<n;i++)
    {
        if(A[i]>max)
        max=A[i];
    }
    return max;
}
void count(int A[],int n)
{
    int i,j,max,*c;

max=findmax(A,n);
    c=(int *)malloc(sizeof(int)*max+1);

    for(i=0;i<max+1;i++)
    {
        c[i]=0;
    }
    for(i=0;i<n;i++)
    {
        c[A[i]]++;
    }
    i=0;j=0;
    while(j<max+1)
    {
        if(c[j]>0)
        {
            A[i++]=j;
            c[j]--;
        }
        else j++;
    }
}

int main()
{
int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
count(A,n);
//MergeSort(A,0,n-1);
for(i=0;i<10;i++)
printf("%d ",A[i]);
printf("\n");
return 0;
}