//Maximum Subarray Implementation

// Using divide and conquer

#include<iostream>
#include<climits>
using namespace std;

//compare 2 item
int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
//compare 3 item
int max(int a, int b, int c){
    return max(max(a,b),c);
}
//maximum possible sum
int maxCrossSum(int array[], int low, int mid, int high)
{
    
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = mid; i >= low; i--) {
        sum = sum + array[i];
        if (sum > left_sum)
            left_sum = sum;
    }
 
  
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= high; i++) {
        sum = sum + array[i];
        if (sum > right_sum)
            right_sum = sum;
    }
 
    return max(left_sum + right_sum, left_sum, right_sum);
}
 

int maxSubarraySum(int array[], int low, int high)
{
    
    if (low == high)
        return array[low];
 

    int mid = (low + high) / 2;
 
   
    return max(maxSubarraySum(array, low, mid),
               maxSubarraySum(array, mid + 1, high),
               maxCrossSum(array, low, mid, high));
}
 
int main()
{
    // int array[] = {-2,1,-3,4,-1,2,1,-5,4};
    // int n = sizeof(array) / sizeof(array[0]);
    int array[50],n;
    cout<<"Give n input: ";
    cin>>n;
    cout<<endl<<"Elements: ";
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    int maximum_sum = maxSubarraySum(array, 0, n - 1);
    cout<<endl<<"Output : "<<maximum_sum;
    
    return 0;
}


// Not using divide and conquer 

/*
#include<iostream>
using namespace std;
int maxSubarray(int a[],int n){
    int sum=0;
    int current=0;
    for(int i=0; i<n; i++){
            current=current+a[i];
            if(current<0)
                current=0;
            if(sum<current)
                sum=current;

    }
    return sum;
}
int main(){
    int a[]={2, 3, 4, 5, 7};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum=maxSubarray(a,n);
    cout<<"Output: "<<max_sum<<endl;
    return 0;
}
*/