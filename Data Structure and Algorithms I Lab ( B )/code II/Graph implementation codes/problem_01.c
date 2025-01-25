//Problem 01

#include <stdio.h>
#include<stdlib.h>
#define CAPACITY 100
#define SUCCESS_VAL 99999
#define FAIL_VAL -99999

int adjMatrix[CAPACITY][CAPACITY];

int n_vertices=0;

void initAdjMatrix(int n)
{

    // Initialise all value to this
    // Adjacency list to zero
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    n_vertices=n;

}

int addEdge(int i, int j, int w){

    if(i>=n_vertices || j>=n_vertices){
        printf("Invalid vertices\n");
        return FAIL_VAL;
    }
    adjMatrix[i][j]=w;
    return SUCCESS_VAL;

}
void addVertex(){
    int n,i;
    for(i=0; i<n; i++){
        adjMatrix[i][n-1]=0;
        adjMatrix[n-1][i]=0;
    }
}
int hasEdge(int i, int j){

    if(i>=n_vertices || j>=n_vertices){
        printf("Invalid vertices\n");
        return FAIL_VAL;
    }
    if(adjMatrix[i][j]){
        printf("edge exists from node %d to %d\n",i,j);
        return 1;
    }
    else{
        printf("No edge exists from node %d to %d\n", i, j);
        return 0;
    }

}
void getNetWeight(int v){
    int cnt=0;
    for(int i=1; i<=v; i++){

    }
}
void printAdjMatrix()
{

   printf("   ");
    for (int i = 0; i < n_vertices; i++) {
        printf("(%d) ", i);
    }
    printf("\n");

    for (int i = 0; i < n_vertices; i++) {
            printf("(%d)",i);
        for (int j = 0; j < n_vertices; j++) {

            // Print the value at Adj[i][j]
            printf(" %d  ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Driver Code
int main()
{
    initAdjMatrix(5);
    addEdge(0,1 , 6);
    addEdge(0,2 , 4);
    addEdge(2,3 , 4);

    printAdjMatrix();


}

