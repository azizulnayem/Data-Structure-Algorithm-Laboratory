#include<bits/stdc++.h>
using namespace std;


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

struct Edge{
    int u, v;
};


void connected_components(int p[], int V, vector<Edge> edges){
    /// implement this
}

bool same_component(int p[], int u, int v){
    /// implement this
}

int main(){
    /// This code is for an undirected graph

    int V, E;
    /// take the number of vertices V and
    /// the number of edges E as input from user
    ...

    /// take the E edges as input from the user
    vector<Edge> edges;
    for (int i=0;i<E;i++){
        ...
    }

    /// create the parent array for a disjoint set of V elements
    int p[V];

    /// call the function connected_components
    connected_components(p, V, edges);


    while(1){
        /// take an integer "option" as input.
        int option;
        ...

        /// if "option" is 1, take another integer x as input,
        /// check if x is an element of the disjoint set or not, and
        /// if it is then print the root/representative-element of x
        if (option==1){
            ...
        }

        /// if "option" is 2, take integers x and y as input,
        /// check if x and y are elements of the disjoint set or not, and
        /// if they are, print whether they belong to the
        /// same connected component or not
        else if (option==2){
            ...
        }

        /// if "option" is 3, take integers x and y as input,
        /// check if x and y are elements of the disjoint set or not, and
        /// if they are, print if there is a path from x to y or not.
        else if (option==3){
            ...
        }

        /// if "option" is 4, print all the roots of this disjoint set
        else if (option==4){
            ...
        }

        /// if "option" is 5, print the vertices of each connected components
        /// in each line
        else if (option==5){
            ...
            /// 0 1 5
            /// 2 3
            /// 4
        }

        else {
            return 0;
        }
    }

}
