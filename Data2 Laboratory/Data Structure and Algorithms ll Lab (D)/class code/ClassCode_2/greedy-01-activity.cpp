#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int number;
    int start;
    int finish;
};

void printMaxActivities(Job input[], int n)
{
    int currentJob, nextJob;
    cout <<"Following activities are selected "<< endl;
    currentJob = 0;
    cout << input[currentJob].number <<" ";
    for (nextJob = 1; nextJob < n; nextJob++)
    {
        if (input[nextJob].start >= input[currentJob].finish)
        {
            cout <<input[nextJob].number<<" ";
            currentJob = nextJob;
        }
    }
}

bool comp (Job i, Job j)
{
    return i.finish<j.finish;
}

int main()
{
    int n;
    cout<<"number of jobs   :";
    cin>>n;

    struct Job inputs[n];

    for (int i=0; i<n; i++)
    {
        inputs[i].number=i+1;
        cin>>inputs[i].start;
        cin>>inputs[i].finish;
    }

    sort(inputs, inputs + n, comp);

    printMaxActivities(inputs, n);
    return 0;
}
