#include<iostream>

using namespace std;

int main()
{
    int arr[] ={4, 256, 2, 4, 3, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<n; i++)
    {
        cout<<"considering :    "<< arr[i] << endl;
        int unique_chk = 1;
        for (int j=0; j<i; j++)
        {

            cout<<"checking :   " << arr[j] << endl;
            if(arr[i] == arr[j])
            {
                unique_chk = 0;
                break;
            }

        }
        if (unique_chk == 1) cout<< "unique :" << arr[i] << endl;
        if  (unique_chk == 0) cout<< "not unique: " << arr[i] << endl;

    }
}
