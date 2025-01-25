// 0-1 knapsack problem
#include<iostream>
#include<vector>
using namespace std;
int knapsack(int total, int weight[], int value[],int m){
        int i,w;
        vector<vector<int>> K(m+1,vector<int>(total+1));
        for(i = 0; i <= m; i++){
            for(w = 0; w <= total; w++){
                if (i == 0 || w == 0)
                    K[i][w] = 0;
                else if (weight[i - 1] <= w)
                    K[i][w] = min(value[i - 1] +
                                K[i - 1][w - weight[i - 1]],
                                K[i - 1][w]);
                else
                    K[i][w] = K[i - 1][w];
        }
    }
    return K[m][total];
}
int main(){
    // int value[]={10,40,30,50};
    // int weight[]={5,4,6,3};
    // int total=10;
    int total,m,i,j;
    cout<<"total weight and value: ";
    cin>>m;
    cout<<"Capacity: ";
    cin>>total;
    int value[m],weight[m];
    for(i=0; i<m; i++){
        cout<<"value "<<i+1<<": ";
        cin>>value[i];
    }
    for(j=0; j<m; j++){
        cout<<"weight "<<j+1<<": ";
        cin>>weight[j];
    }
    //int n=sizeof(value)/sizeof(value[0]);
    cout<<"Maximum Profit: "<<knapsack(total,weight,value,m)<<endl;
    return 0;
}
