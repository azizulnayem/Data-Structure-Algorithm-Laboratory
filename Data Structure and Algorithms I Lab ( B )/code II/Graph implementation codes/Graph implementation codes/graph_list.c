// Adjascency List representation in C

#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  int weight;
  struct node* next;
};

int n_vertices=0;

struct node** adjLists;


struct node* createNode(int v, int w) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->weight = w;
  newNode->next = NULL;
  return newNode;
}


void initGraph(int n) {
  adjLists = malloc(n * sizeof(struct node*));

  int i;
  for (i = 0; i < n; i++)
    adjLists[i] = NULL;

  n_vertices=n;

}

int hasEdge(int i, int j){

    struct node* temp = adjLists[i];

    while (temp) {
        if(temp->vertex==j){
            printf("edge exists from node %d to %d\n",i,j);
            return 1;
        }
        temp = temp->next;
    }
    printf("No edge exists from node %d to %d\n", i, j);
    return 0;
}
int removeEdge(int i, int j){
        //write your code here
}

void addEdge(int i, int j, int w) {

  struct node* newNode = createNode(j,w);
  newNode->next = adjLists[i];
  adjLists[i] = newNode;

}

int getDegree(int i){
    //write your code here
}


void printGraph() {
  int v;

  for (v = 0; v < n_vertices; v++) {
    struct node* temp = adjLists[v];
    printf("\n%d", v);

    while (temp) {
      printf(" -> %d (%d)", temp->vertex, temp->weight);
      temp = temp->next;
    }

    printf("\n");
  }
}


int main() {
  initGraph(4);

  addEdge(0, 1, 5 );
  addEdge(0, 2, 6);
  addEdge(0, 3, 7);
  addEdge(1, 2, 3);

  printGraph();

  return 0;
}
