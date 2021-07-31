#include <stdlib.h>

int main()
{
    char A[]="how are you";
    int i,vcount=0;
    for(i=0;A[i]!='\0';i++)
    {
        if(A[i]=='a'||A[i]=='A'||A[i]=='E'||A[i]=='e'||
           A[i]=='i'||A[i]=='I'||A[i]=='O'||A[i]=='o'||A[i]=='u'||
           A[i]=='U')
        {
            vcount++;
        }
    }
}
