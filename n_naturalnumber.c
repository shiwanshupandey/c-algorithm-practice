#include <stdio.h>

int sum(int n)
{
    if(n==0)
        return 0;
    return sum(n-1)+n;
}
int Isum(int n){

    int s=0;
    int i;
    for(i=1;i<=n;i++)
        s=s+1;
    return s;

}

int main()
{
    int r;
    r=sum(5);
    printf("%d", r);
    return 0;
}
