#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;
typedef string  TypeItem; // Type of the vertex name
class GraphList {

    private:
    int v;
    int nullEdgeIndex;
    vector<TypeItem> vertex; // Array to store the vertices
    vector<list<TypeItem>> adj;
    void dfsUtil(int currentIndex, vector<bool>& visited,vector<TypeItem>& result);
    int typeGraph;
    vector<int> color; // Vector to store colors for bipartite checking

    public:
    GraphList(int v, int nullEdgeIndex, int typeGraph); // Constructor to initialize the graph with a given number of vertices
    ~GraphList(); // Destructor to clean up the graph
    void insertVertex(TypeItem); // Function to insert a vertex into the graph
    int getIndex(TypeItem); // Function to get the index of a vertex
    void insertEdge(TypeItem, TypeItem); // Function to insert an edge between two vertices
    void printGraph(); // Function to print the adjacency list representation of the graph
    bool isEmpty(); // Function to check if the graph is empty
    bool isFull(); // Function to check if the graph is full
    int getvertexDegree(TypeItem); // Function to get the degree of a vertex
    void printVertex(); // Function to print the adjacency list of the graph
    void bfs(TypeItem startVertex);
    vector<TypeItem> dfs(TypeItem startVertex);
    bool isConnected(); // Function to check if the graph is connected
    int numeroDeComponentesConexas();
    bool isBipartiteUtil(int v);
    bool isBipartite(); // Function to check if the graph is bipartite
    bool isTree(); // Function to check if the graph is a tree
    bool hasCycle();
    bool hasCycleUtil(int currentIndex, vector<bool>& visited, vector<bool>& inStack);
    void isTopologicalSort();
    void isTopologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack, vector<list<TypeItem>>& adj);
    bool isTopological();
};