#include <iostream>

// Grafo simples não direcionado ponderado  com matriz de adjacência
using namespace std;

typedef string TypeItem;


class Graph{
    private:
    int NullEdgeIndex;
    int maxVertexCount;
    int numberOfVertex; 
    TypeItem *vertexList; // List of vertices
    int **adjacencyMatrix; // Adjacency matrix   

    public: 
    Graph(int max, int nullvalue);
    ~Graph();	
    int getIndex(TypeItem item);
    bool isFull();
    void insertVertex(TypeItem item);
    void insertEdge(TypeItem NodeIn, TypeItem NodeOut, int weight);
    int  getWeight(TypeItem NodeIn, TypeItem NodeOut);
    int getvertexDegree(TypeItem item);
    void printVertex();
    void printAdjacencyMatrix();
    

};