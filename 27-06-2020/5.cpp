#include<iostream>

using namespace std;
class D
{

private:
    int n;
    int *A;

public:
    D()
    {
        n=2;
        A=new int[2*(2+1)/2];
    }

    D(int n)
    {
        this->n=n;
        A=new int[n*(n+1)/2];
    }

    ~D()
    {
        delete []A;
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
    int getdimension(){return n;}
};

void D::set(int i,int j,int x)
    {
        if(i>=j)
            A[(i-1)n-(i-2)(i-1)/2+(j-1)]=x;
    }


    int D::get(int i,int j)
    {
        if(i>=j)
            return A[(i-1)n-(i-2)(i-1)/2+(j-1)];
        else
            return 0;
    }


    void D::display()
    {
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==j)
                    cout<<A[(i-1)n-(i-2)(i-1)/2+(j-1)]<<" ";
                else
                    cout<<"0 ";

            }
            cout<<endl;
        }
    }


int main ()
{
    int d;
    cout<<"enter dimensions";
    cin>>d;

    D lm(d);

    int x;
    cout<<"enter all elements";
    for(int i=0;i<=d;i++)
        {
            for(int j=0;j<=d;j++)
            {
                cin>>x;
                lm.set(i,j,x);
            }


    lm.display();

    return 0;
        }

}
