#include<bits/stdc++.h>
using namespace std;

struct jinis_pati{
    int item;
    int cost;

};

bool assending(jinis_pati first, jinis_pati second)
{
    return first.cost<second.cost;
}

int can_take_item(jinis_pati array[], int n, int m)
{
    int dayna[n][m+1];
    int total_item = 0;
    int curr_cost,b=0,a=0;
    int array1[n] = {0};
    sort(array, array+n, assending);
    for(int i=0; i<n; i++)
    {
        a = array[i].cost;
        array1[i] = a+b;
        //cout<<array1[i]<<endl;
        b = array1[i];
    }

    for(int item = 0; item <= n; item++)
    {
        //curr_cost=0;
        //int temp_cost = array[item-1].cost;
        for(int own_cost =0; own_cost<= m+1; own_cost++)
        {
            //curr_cost = array[item-1].cost;
            if(own_cost == 0 || item == 0)
            {
                dayna[item][own_cost] = 0;
            }
            else if(array1[item-1] == own_cost)
            {
                dayna[item][own_cost] = dayna[item-1][own_cost-1] +1;
                total_item += array[item-1].item;
            }
            else
            {
                int maximum = max(dayna[item][own_cost -1],dayna[item-1][own_cost]);
                dayna[item][own_cost] = maximum;
            }
        }
    }


    return total_item;
}


int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    struct jinis_pati array[n];

    for(int i=0; i<n; i++)
    {
        cin>>array[i].item>>array[i].cost;
    }

    int a = can_take_item(array,n,m);
    if(a>=k)
    {
        cout<<"Yes "<<a;
    }
    else
    {
        cout<<"No";
    }

    return 0;
}
