#include <stdio.h>

int pow(int m, int n)
{
    if(n==0)
        return (1);
    return pow(m,n-1)*m;
    }

int pow(int m, int n)
    if(n==0)
        return(1);
    if(n%2==0)
        return pow(m*m,n/2);
    else
        return m*pow(m*m,(n-1)/2);
}
int main()
{
    int r;
    r=pow(2,9);
    printf("%d", r);
    return 0;
}
