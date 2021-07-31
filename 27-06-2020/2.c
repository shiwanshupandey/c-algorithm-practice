#include<stdio.h>

struct matrix
{
    int A[10];
    int n;
};


class D
{

private:
    int n;
    int *A;

public:

    D(int n)
    {
        this->n=n;
        A=new int[n];
    }


    void D::set(int i,int j,int x)
    {
        if(i==j)
            A[i-1]=x;
    }


    int D::get(int i,int j)
    {
        if(i==j)
            return A[i-1];
        else
            return 0;
    }


    void D::display()
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==j)
                    cout<<A[i-1];
                else
                    cout<<"0 ";

            }
            cout<<end1;
        }
    }
    D()
    {
        delete[]A;
    }
};


int main ()
{
    struct matrix m;
    m.n=4;

    set(&m,1,1,5);set(&m,2,2,8);set(&m,3,3,9);set(&m,4,4,12);

    display(m);

    return 0;

}
