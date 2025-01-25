#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,number[100],check,unique1[100],count1,count2=0;

    cout<<"Enter total number you wanted to take : ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter "<<i+1<<" no number : ";
        cin>>number[i];
    }

    for(int i=0; i<n; i++)
    {
        check = number[i];
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

            unique1[count2] = check;
            count2++;
        }
    }

    //for(int i=0; i!='\0'; i++)
    //{
     //   count2++;
    //}

    for(int i=0; i<count2; i++)
    {
        count1=0;
        cout<<unique1[i]<<" occurs ";
        for(int j=0; j<n; j++)
        {
            if(unique1[i]==number[j])
            {
                count1++;
            }
        }
        cout<<count1<<" times"<<endl;
    }

    return 0;
}
