//Problem 4
//Brust The Balloons
#include<bits/stdc++.h>
using namespace std;
class Balloons{
    public:
        int minArrow(vector<vector<int>> &arr){
            if(arr.empty())
                return 0;
            sort(begin(arr),end(arr));
            int ans=1, arrow=arr[0][1];
            for(auto &b:arr){
                if(b[0]<=arrow){
                    arrow=min(arrow,b[1]);
                }
                else{
                    arrow=b[1];
                    ++ans;
                }
            }    
        }
        return ans;
};
int main(){
    int arr[]={10,16,2,8,1,6,7,12};
    Balloons balloon;
    balloon.minArrow(arr);
    return 0;
}