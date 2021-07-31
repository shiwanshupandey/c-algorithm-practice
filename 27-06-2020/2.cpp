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
        A=new int[2];
    }

    D(int n)
    {
        this->n=n;
        A=new int[n];
    }

    ~D()
    {
        delete []A;
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
};

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
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    cout<<A[i]<<" ";
                else
                    cout<<"0 ";

            }
            cout<<endl;
        }
    }


int main ()
{
    D d(4);

    d.set(1,1,5);
    d.set(2,2,8);
    d.set(3,3,9);
    d.set(4,4,12);

    d.display();

    return 0;

}
