#include<iostream>

using namespace std;

int calc_factorial (int x)
{
    cout<< x << "! = " ;
    int f =1;
    for (int i = x; i>1; i--)
    {
        cout<< i <<" X ";
        f=f*i;

    }

    cout<< " 1 = " << f <<endl;

    return f;
}



int main()
{
    int a,b;
    cin>>a;
    cin>>b;
    for(int i=a; i<b; i++)
    {
        int f = calc_factorial(i);
    }

    return 0;
}
