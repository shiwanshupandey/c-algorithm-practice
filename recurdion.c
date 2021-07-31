#include <stdio.h>

int fun(int n)
{
    if(n>10)
        return n-10;
    return fun(fun(n+11));
}

int main()
{
    int r;
    r=fun(10);
    printf("%d", r);
    return 0;
}
