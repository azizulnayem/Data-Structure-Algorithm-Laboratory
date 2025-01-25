#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,number;
    double avg,sum=0;
    cout<<"Enter total number you wanted to input : ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter "<<i+1<<" no number : ";
        cin>>number;
        sum = sum+number;
    }
    avg = sum/n;

    cout<<"The average is : "<<fixed<<setprecision(2)<<avg;

    return 0;
}
