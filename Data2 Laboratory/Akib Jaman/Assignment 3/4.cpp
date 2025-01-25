#include<bits/stdc++.h>
using namespace std;

struct destination
{
    int s;
    int g;
    int d;
};

//void calculation(destination array[],int n,int t[n][n])
//{
//    cout<<t[0][1];
//}

int main()
{
    int n,m;
    cin>>n;
    int t[n][n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>t[i][j];
        }
    }

    cin>>m;
    struct destination array[m];
    int index,index1;

    for(int i=0; i<m; i++)
    {
        cin>>array[i].s>>array[i].g>>array[i].d;
    }

    //calculation(array,n,t);
    for(int i=0; i<m; i++)
    {
        int a = array[i].s;
        for(int j=0; j<n; j++)
        {
            if(a==t[j][0])
            {
                index = j;
                break;
            }
        }
        int b = array[i].g;
        int cost=0;
        for(int j=0; j<n; j++)
        {
            if(b==t[index][j])
            {
                index1 = j;
                break;
            }
            else
            {
                cost++;
            }

        }
        //cout<<cost<<" ";
        for(int j =index1; j<n; j++)
        {
            if(t[index][j]==array[i].d || t[index][j-1]==array[i].d)
            {
                //cost++;
                break;
            }
            else
            {
                cost++;
            }
        }
        cout<<cost<<" ";
        int cost2=0;
        for(int j=0; j<n; j++)
        {
            if(t[index][j]==array[i].d)
            {
                cout<<cost-cost2<<endl;
                break;
            }
            else{
                cost2++;
            }

        }
    }


    return 0;
}



/*
4
0 2 1 3
1 0 4 5
3 1 0 2
1 1 1 0
4
0 2 1
0 2 2
3 1 2
3 0 1

*/
