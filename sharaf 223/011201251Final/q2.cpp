#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ///ifstream inputFile("input2.txt");

    int v, e;
    inputFile >> v >> e;

    vector<vector<int>> adjacencyMatrix(v, vector<int>(v, 0));

    for (int i = 0; i < e; ++i) {
        int u, w;
        inputFile >> u >> w;
        adjacencyMatrix[u][w] = 1;
        adjacencyMatrix[w][u] = 1;
    }

    inputFile.close(); // Close the input file

    int maxAdjacentNodes = 0;
    int vertexWithMaxAdjacentNodes = -1;

    for (int i = 0; i < v; ++i) {
        int adjacentNodes = 0;
        for (int j = 0; j < v; ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                ++adjacentNodes;
            }
        }
        if (adjacentNodes > maxAdjacentNodes) {
            maxAdjacentNodes = adjacentNodes;
            vertexWithMaxAdjacentNodes = i;
        }
    }

    cout << "Vertex with the highest number of adjacent nodes: " << vertexWithMaxAdjacentNodes << endl;

    return 0;
}
