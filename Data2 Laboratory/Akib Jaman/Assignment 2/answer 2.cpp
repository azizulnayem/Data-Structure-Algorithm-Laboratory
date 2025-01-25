#include<bits/stdc++.h>
using namespace std;

struct times
{
    int start;
    int end;
};

bool assending(times a, times b)
{
    return a.end<b.end;
}

void activitySelection(times uni_course[],int n,int cur_start,int cur_end)
{
    int curr = 0,count=0;

    if(uni_course[curr].start>=cur_start && uni_course[curr].end<=cur_end)
    {
        count++;

        for(int i=1; i<n; i++)
        {
            if(uni_course[curr].end <= uni_course[i].start)
            {
                if(uni_course[i].start>=cur_start && uni_course[i].end<=cur_end)
                {
                    count++;
                }
                curr++;

            }
        }
    }
    cout<<count;
}

int main()
{
    int n,q,cur_start,cur_end;

    cin>>n>>q;
    struct times uni_course[n],sam_time[q];

    for(int i=0; i<n; i++)
    {
        cin>>uni_course[i].start;
        cin>>uni_course[i].end;
    }
    for(int i=0; i<q; i++)
    {
        cin>>sam_time[i].start;
        cin>>sam_time[i].end;
    }
    sort(uni_course,uni_course+n,assending);

    for(int i=0; i<q; i++)
    {
        cur_start = sam_time[i].start;
        cur_end = sam_time[i].end;
        activitySelection(uni_course,n,cur_start,cur_end);
        cout<<endl;
    }

    return 0;
}
