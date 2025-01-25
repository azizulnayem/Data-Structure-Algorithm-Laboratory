#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return fib(n-1)+ fib(n-2);
}

int pow(int x, int y)
{
    if(y == 0) return 1;

    int a = pow(x, y/2);

    if ( y%2 == 0) // y is even
        return a*a;
    else // y is odd
        return x*a*a;
}

// basecase if array size is 1 then that element is the minimum element
// else rescursive call: min([7,4,5,10]) = min(min([7,4,5]), 10)

int minimum(int arr[], int length)
{
    if (length == 1) return arr[0]; // only a single element in the array itself
    // recursive call here
    int a = minimum(arr, length - 1);

    return a > arr[length - 1] ? arr[length - 1] : a;
}

// basecase: if length == 1: return that element
// recursive case: isnt avg just sum/n? : avg(7,4,5,10) = (10 + 3 * avg(7,4,5))/4

float find_avg(int a[], int length)
{
    float sum,avg;
    if(length==1)
    {
        sum=a[0];
    }
    else
    {
        // Calculate sum of n-1 numbers = (n-1) * (avg of n-1 numbers)
        // and add nth number to it ( i.e. a[n-1])
        float temp_avg = find_avg(a, length-1);
        sum= a[length-1]+ (length-1) * temp_avg;
    }
    avg = sum/length;
    return avg;
}


int main()
{
    // Calculating Average Using Recursion
    int arr[] = {1,2,3,4,5};
    cout<< "Avg: " << find_avg(arr, 5) << endl;
    cout << "Minimum: " << minimum(arr, 5) << endl;

    // Fibonacci
    int f = fib(6);
    cout << "Fibo: " << f << endl;

    // Power
    cout << "Power: " << pow(2, 4) << endl;

}
