#include<bits/stdc++.h>

using namespace std;

//#define INT_MAX 99999;

struct Graph{
    int num_vertex;
    list<int>* adjList;
    bool* isVisited;
    int* level;

    Graph(int vertices)
    {
        num_vertex = vertices;
        adjList = new list<int>[vertices];
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void BFS(int source_vertex)
    {
        isVisited = new bool[num_vertex];
        level = new int[num_vertex];

        for(int i=0; i<num_vertex; i++)
        {
            isVisited[i] = false;
            level[i] = INT_MAX;
        }

        list<int> Queue;

        isVisited[source_vertex] = true;
        level[source_vertex] = 0;
        Queue.push_back(source_vertex);

        while(Queue.empty()==false)
        {
            int cur_vertex = Queue.front();
            Queue.pop_front();

            cout << "Vertex: " << cur_vertex << "    Level: " << level[cur_vertex] << endl;

            list<int>::iterator i;
            for(i=adjList[cur_vertex].begin(); i!=adjList[cur_vertex].end(); i++)
            {
                int adj_vertex = *i;
                if(isVisited[adj_vertex]==false)
                {
                    Queue.push_back(adj_vertex);
                    level[adj_vertex] = level[cur_vertex] + 1;
                    isVisited[adj_vertex] = true;
                }
            }
        }
    }

    void DFS(int source_vertex)
    {
        isVisited = new bool[num_vertex];
        for(int i=0; i<num_vertex; i++)
        {
            isVisited[i] = false;
        }
        DFS_visit(source_vertex);
    }

    void DFS_visit(int vertex)
    {
        isVisited[vertex] = true;
        cout << "Vertex: " << vertex << endl;
        list<int>::iterator i;
        for(i=adjList[vertex].begin(); i!=adjList[vertex].end(); i++)
        {
            int adj_vertex = *i;
            if(isVisited[adj_vertex]==false)
            {
                DFS_visit(adj_vertex);
            }
        }
    }
};

int main()
{
    Graph *graph = new Graph(8);

    graph->addEdge(0, 1);
    graph->addEdge(0, 3);

    graph->addEdge(1, 2);

    graph->addEdge(3, 4);
    graph->addEdge(3, 6);

    graph->addEdge(4, 5);
    graph->addEdge(4, 6);

    graph->addEdge(6, 7);

    graph->addEdge(5, 7);

    graph->DFS(0);
}