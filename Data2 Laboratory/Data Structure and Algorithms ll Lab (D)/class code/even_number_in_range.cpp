#include <iostream>
#include <conio.h>
using namespace std;
//function declaration
void displayEven(int num, int limit);
int main()
{
    int lowerLimit, upperLimit;
    cout<<"Enter your lower limit\n";
    cin>>lowerLimit;
    cout<<"Enter your upper limit\n";
    cin>>upperLimit;
    cout<<"Even numbers from "<<lowerLimit<<" to "<<upperLimit<<endl;
    displayEven(lowerLimit, upperLimit);
    getch();
    return 0;
}
void displayEven(int num, int limit)
{
    if(num>limit)
        return;
    if(num%2==0)
    {
        cout<<num<<endl;
        displayEven(num + 2, limit);
    }
    else
    {
        num=num+1;
        cout<<num<<endl;
        displayEven(num + 2, limit);

    }
}
