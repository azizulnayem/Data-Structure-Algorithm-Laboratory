#include<bits/stdc++.h>
using namespace std;

/// Final task: implement path compression and union by rank
void make_set(int p[], int x){
    p[x] = x;
    cout << "making a one-element set of "<<x<< endl;
}

int find_set(int p[], int x){
    if (x!=p[x])
        return find_set(p, p[x]);
    return p[x];
}

void _union(int p[], int x, int y){
    int a = find_set(p, x);
    int b = find_set(p, y);
    p[a] = b;
    cout << "union "<<a << " and "<<b<< endl;
}

int main(){


    int N;
    /// take N input from user

    /// create the parent array for a disjoint set of N elements
    int p[N];
    for (int i=0;i<N;i++){
        make_set(p, i);
    }

    while(1){
        /// take an integer "option" as input.
        int option;


        /// if "option" is 1, take another integer x as input,
        /// check if x is an element of the disjoint set or not, and
        /// if it is then print the root/representative-element of x
        if (option==1){

        }

        /// if "option" is 2, take integers x and y as input,
        /// check if x and y are elements of the disjoint set or not, and
        /// if they are check if they belong to the same set or not
        else if (option==2){


        }

        /// if "option" is 3, take integers x and y as input,
        /// check if x and y are elements of the disjoint set or not, and
        /// if they are then union them
        else if (option==3){

        }

        else {
            return 0;
        }
    }

}
