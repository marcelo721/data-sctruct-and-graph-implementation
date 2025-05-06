#include <iostream>
#include <vector>
#include <list>
using namespace std;
typedef string  TypeItem; // Type of the vertex name
class GraphList {

    private:
    int v;
    int nullEdgeIndex;
    vector<TypeItem> vertex; // Array to store the vertices
    vector<list<TypeItem>> adj;
    void dfsUtil(int currentIndex, vector<bool>& visited,vector<TypeItem>& result);//  void dfsUtil(int currentIndex, vector<bool>& visited);Adjacency list representation of the graph

    public:
    GraphList(int v, int nullEdgeIndex); // Constructor to initialize the graph with a given number of vertices
    ~GraphList(); // Destructor to clean up the graph
    void insertVertex(TypeItem); // Function to insert a vertex into the graph
    int getIndex(TypeItem); // Function to get the index of a vertex
    void insertEdge(TypeItem, TypeItem); // Function to insert an edge between two vertices
    void printGraph(); // Function to print the adjacency list representation of the graph
    bool isEmpty(); // Function to check if the graph is empty
    bool isFull(); // Function to check if the graph is full
    int getvertexDegree(TypeItem); // Function to get the degree of a vertex
    void PrinterAdjacencyList(); // Function to print the adjacency list of the graph
    void bfs(TypeItem startVertex);
    vector<TypeItem> dfs(TypeItem startVertex);


};