#include<stdio.h>

int main()
{
    char A[]="find";
    int H[26],i;

    for(i=0;A[i]!='\0';i++)
    {
        H[A[i]-97]+=1;
    }
    for(i=0;i<26;i++)
    {
        if(H[i]>1)
        {
            printf("%c",i+97);
            printf("%d",H[i]);
        }
    }
}
