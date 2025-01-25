#include<bits/stdc++.h>
using namespace std;


int total(int arr[],int n)
{
    if(n==1)
    {
       return 0;
    }
    else
    {
        int totalNo = 0;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]<arr[i+1])
               {
                   totalNo = totalNo+0;

               }
            else
            {

                totalNo += arr[i]-arr[i+1]+1;
                arr[i+1] = arr[i]+1;

            }
        }

        return totalNo;
    }

}
int main()
{
    int arr[] = {1,5,2,4,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int result = total(arr,n);

    cout << result <<endl;

return 0;
}




