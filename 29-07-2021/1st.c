#include <stdio.h>
#include "chain.h"
int hash(int key)
{
return key%10;
}
void Insert(struct node *H[],int key)
{
int index=hash(key);
sort(&H[index],key);
}
int main()
{
struct node *HT[10];
struct node *temp;
int i;
for(i=0;i<10;i++)
HT[i]=NULL;
Insert(HT,12);
Insert(HT,22);
Insert(HT,42);
temp=search(HT[hash(22)],22);
printf("%d ",temp->data);
return 0;
}