#include<bits/stdc++.h>
using namespace std;

int v,con[100][100];
int total_edge[100],total_edge_desending[100];

bool desending(int a, int b){
    return a>b;
}

int crash_ver()
{
    int crash_vertex=-1;
    for(int i=0; i<v; i++)
    {
        if(total_edge_desending[0]==total_edge[i])
        {
            crash_vertex = i;
            break;
        }
    }
    for(int i=0; i<v; i++)
    {
        con[crash_vertex][i] = 0;
        con[i][crash_vertex] = 0;
    }
    return 1;
}

void count_edge()
{
    for(int i=0; i<v; i++)
    {
        int count = 0;
        for(int j=0; j<v; j++)
        {
            if(con[i][j]==1)
            {
                count++;
            }
        }
        total_edge[i] = count;
        total_edge_desending[i] = count;
    }
    sort(total_edge_desending,total_edge_desending+v,desending);
}

int main()
{
    int e,v_name,v_con;

    cin>>v>>e;

    int total_crash=0,a;

    for(int i=0; i<e; i++)
    {
        cin>>v_name>>v_con;
        con[v_name-1][v_con-1] = 1;
        con[v_con-1][v_name-1] = 1;
    }
    //sort(total_edge_desending,total_edge_desending+v,desending);

    for(int i=0; i<v; i++)
    {
        count_edge();
        if(total_edge_desending[0] != 0)
        {
            a = crash_ver();
            total_crash += a;
        }
    }

    cout<<total_crash;

    return 0;
}
