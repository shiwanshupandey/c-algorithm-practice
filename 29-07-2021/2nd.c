#include<stdio.h>
#define SIZE 10

int hash(int key)
{
    return key%SIZE;
}

int probe(int h[], int key){
    int index=hash(key);
    int i=0;
    while(h[(index+i)%SIZE]!=0)
    i++;
    return (index+i)%SIZE;

}

void insert(int h[],int key)
{
    int index=hash(key);
    if(h[index]!=0)
    index=probe(h,key);
    h[index]=key;
}

int search(int h[], int key)
{
    int index=hash(key);
    int i=0;

    while(h[(index+1)%SIZE]!=key)
    i++;

    return (index+1)%SIZE;

}

int main()
{
    int ht[10]={0};
    insert(ht,12);
    insert(ht,35);
    insert(ht,25);
    insert(ht,26);

    printf("\n key found at %d \n",search(ht,35));
    return 0;
    

}