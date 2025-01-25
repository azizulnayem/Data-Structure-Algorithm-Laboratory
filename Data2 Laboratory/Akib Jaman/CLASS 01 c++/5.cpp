#include<bits/stdc++.h>

using namespace std;

int factorial(int number1)
{

    if(number1==0)
    {
        return 1;
    }
    else
    {
        cout<<number1;
        if(number1!=1)
        {
            cout<<" X ";
        }
        else
        {
            cout<<" = ";
        }
        return number1*factorial(number1-1);
    }
}

int main()
{
    int number1,number2;

    cout<<"Take first number : ";
    cin>>number1;
    cout<<"Take second number : ";
    cin>>number2;
    for(int i=number1; i<=number2; i++)
    {
        cout<<i<<"! = "<<factorial(i)<<endl;
    }


    return 0;
}
