//take input from user
//make a array
//print out the unique list from the array

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,number[100],check,count1;

    cout<<"Enter total number you wanted to take : ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter "<<i+1<<" no number : ";
        cin>>number[i];
    }

    cout<<"The unique list is : ";
    for(int i=0; i<n; i++)
    {
        check=number[i];
        count1=0;
        for(int j=i+1; j<n; j++)
        {
            if(check==number[j])
            {
                count1++;
            }
        }
        if(count1==0)
        {
            cout<<check<<" ";
        }
    }

    return 0;
}
