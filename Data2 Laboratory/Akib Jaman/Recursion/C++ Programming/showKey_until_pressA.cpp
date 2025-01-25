#include<bits/stdc++.h>

using namespace std;

int main()
{
    char number='0';
    cout<<"Enter alphabet A to exit the program..."<<endl;
    cout<<endl;

    while(number!='A')
    {
        cout<<"Press any key to show that key : ";
        cin>>number;
        if(number=='A')
        {
            cout<<"You have exit the system"<<endl;
            break;
        }
        else
        {
            cout<<"You have pressed : "<<number<<endl;
        }

    }

    return 0;
}
