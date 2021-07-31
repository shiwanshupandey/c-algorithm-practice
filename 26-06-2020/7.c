 #include<stdio.h>

void perm(char S[],int k)
{
    static int A[10]={0};
    static char res[10];
    int i;
    if(S[k]=='\0')
        {
            res[k]='\0'; printf(res);
    }
}

else
    {
            for(i=0;S[i]!='\0';i++)
            {
                if (A[i]==0)
                {
                    res[k]=S[i];
                    A[i]=1;
                    perm(s,K+1);
                    A[i]=0;
                }
            }
        }



int main ()
{
    char S[]="ABC";
    perm(S,0);
}
