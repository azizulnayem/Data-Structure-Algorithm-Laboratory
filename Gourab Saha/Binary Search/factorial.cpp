#include<bits/stdc++.h>

using namespace std;

int factorial(int n);

int main(){
    int n, fact;
    cin >> n ;

    fact = factorial(n);
    cout << fact << endl;
}

int factorial(int n){
    if (n==0) return 1;
    if (n==1) return 1;
    return n*factorial(n-1);
}

