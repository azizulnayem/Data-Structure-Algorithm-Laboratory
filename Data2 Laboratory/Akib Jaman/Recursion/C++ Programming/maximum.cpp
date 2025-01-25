//take input from user
//make a array
//find the maximum

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,number[100],check,temp;

    cout<<"Enter total number you wanted to take : ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter "<<i+1<<" no number : ";
        cin>>number[i];
    }

    cout<<"The maximum number is : ";

    check = number[0];
    for(int i=1; i<n; i++)
    {
        if(check<number[i])
        {
            temp = check;
            check = number[i];
        }

    }

    cout<<check;

    return 0;
}
