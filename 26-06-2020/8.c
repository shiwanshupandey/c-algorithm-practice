#include<stdio.h>


void perm(char S[],int l,int h)
{
    int i;

    if(l==h)
    {
        printf(S);
    }
    else
    {
        for(i=l;i<=h;i++)
        {
            swap(S[l],S[i]);
            perm(S,l+1,h);
            swap(S[l],S[i]);

        }
    }
}

int main ()
{
    char S[]="ABC";
    perm(S);
}
