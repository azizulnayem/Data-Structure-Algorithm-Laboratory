//Problem 03
//Course Selection Problem

#include<bits/stdc++.h>
using namespace std;
void maxNumOfCourse(int start[],int end[],int n ){
    pair<int,int>p[n+1];
    for(int i=0; i<n; i++){
        p[i].first=end[i];
        p[i].second=i;
    }
    sort(p,p+n);
    int limit=p[0].first;
    vector<int>course;
    course.push_back(p[0].second+1);

    for(int i=0; i<n; i++){
        if(start[p[i].second]>=limit){
            course.push_back(p[i].second+1);
            limit=p[i].first;
        }
    }
    for(int i=0; i<course.size(); i++){
        cout<<course[i]<<" ";
    }
}
int main(){
    int start[]={1,5,2,1,1,2};
    int end[]={3,6,4,6,3,3};
    int n=sizeof(start)/sizeof(start[0]);
    maxNumOfCourse(start,end,n);
    return 0; 
}