//Problem 02
//Feed The Children

#include<bits/stdc++.h>
using namespace std;

int feedChildren(vector<int>&g,vector<int>&s){
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int numOfChild=g.size(),numOfCookies=s.size();
        int cookies=0, result=0;
          for(int ind=0; ind<numOfChild && cookies<numOfChild;){
            if(s[cookies]>=g[ind]){
                ind++;
                result++;
            }
            cookies++;
          }
          return result;
}
int main(){
        vector<int> g={1,2};
        vector<int> s={1,2,3};
        cout<<feedChildren(g,s)<<endl;
        return 0;
}
