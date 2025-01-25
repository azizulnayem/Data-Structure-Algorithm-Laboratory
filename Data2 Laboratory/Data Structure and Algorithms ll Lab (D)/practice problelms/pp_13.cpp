//print even number
#include<iostream>
using namespace std;
int even(int num1, int num2)
{
   if(num1>num2)
    return 0;
    cout<<num1<<" ";
return even(num1+2,num2);
}
int main()
{
    int num1,num2;
    cout<<"Enter your fast limit:";
    cin>>num1;
    cout<<"Enter your last limit:";
    cin>>num2;
    cout<<"Output:";
    even(num1,num2);
}