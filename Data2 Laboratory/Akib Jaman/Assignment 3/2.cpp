#include <bits/stdc++.h>
using namespace std;

void dijkstra(int graph[100][100], int l, int array[], int V)
{
    int array_flag[100] = {0};
    int count =0;

    for(int i=0; i<l; i++)
    {
        if(array_flag[i]==1)
        {
            break;
        }
        else
        {
            for(int j=0; j<V; j++)
            {
                if(graph[array[i]-1][j]==1)
                {
                    array_flag[i] = array_flag[array[i]-1]+1;
                    count++;
                    break;
                }
            }
            if(array_flag[array[i]-1]!=1)
            {
                count = -1;
                break;
            }
        }

    }

    cout<<count<<endl;

}


int main()
{
    int n,m,t;

    int array[100],l;

    cin>>t;

    for(int sector=0; sector<t; sector++)
    {
        cin>>n>>m>>l;

        int graph[100][100]= {0};

        for(int i=0; i<l; i++)
        {
            cin>>array[i];
        }

        for(int i=0; i<m; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            graph[u-1][v-1] = w;
            graph[v-1][u-1] = w;
        }


        dijkstra(graph,l,array,m);
    }


    return 0;
}
