#include<bits/stdc++.h>
using namespace std;

struct balloon
{
    int start;
    int end;
};

bool assending(balloon a, balloon b)
{
    return a.end<b.end;
}

void activitySelection(balloon place[],int n)
{
    int arrow=n;

    for(int j=0; j<n; j++)
    {
        for(int i=j+1; i<n; i++)
        {
            if(place[j].start >= place[i].start && place[j].start<= place[i].end)
            {
                arrow--;
            }

        }
    }
    cout<<arrow;
}

int main()
{
    int n;

    cin>>n;
    struct balloon place[n];

    for(int i=0; i<n; i++)
    {
        cin>>place[i].start;
        cin>>place[i].end;
    }

    activitySelection(place,n);


    return 0;
}
