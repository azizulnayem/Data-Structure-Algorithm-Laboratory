#include<bits/stdc++.h>
using namespace std;

struct question_set
{
    int number;
    int time;
};

bool desinding(question_set first, question_set second)
{
    return first.number>second.number;
}

int own_method(question_set array[], int n, int t)
{
    int dayna[n][t+1],curr_time = 0,total_marks = 0,track = 0;
    sort(array, array+n, desinding);
    for(int question=0; question<=n; question++)
    {
        curr_time += array[question].time;
        for(int time=0; time<=t+1; time++)
        {
            if(question==0 || time == 0)
            {
                dayna[question][time] = 0;
            }
            else if(curr_time == time)
            {
                dayna[question][time] = dayna[question-1][time-1] + 1;
                if(track == 0)
                {
                    total_marks += array[question].number * 2;
                }
                else
                {
                    total_marks += array[question].number;
                }
            }
            else
            {
                int maximum = max(dayna[question][time-1],dayna[question-1][time]);
                dayna[question][time] = maximum;
            }
        }
    }

    //for(int i=0; i<=n; i++)
    //{
    //    for(int j=0; j<=t; j++)
    //    {
    //        cout<<dayna[i][j];
    //    }
    //    cout<<endl;
    // }

    return total_marks;
}

int main()
{
    int n,t;

    cin>>n>>t;
    struct question_set array[n];

    array[0].number = 0;
    array[0].time = 0;
    for(int i=1; i<=n; i++)
    {
        cin>>array[i].number>>array[i].time;
    }

    cout<<own_method(array,n,t);

    return 0;
}
