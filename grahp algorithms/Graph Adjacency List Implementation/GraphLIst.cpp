#include "GraphList.h"
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

GraphList::GraphList(int numberOfVertices, int nullEdgeIndex) {
    this->v = numberOfVertices;
    this->nullEdgeIndex = nullEdgeIndex;
    adj.resize(v);
    
}

GraphList::~GraphList() {
    vertex.clear(); // Clear the vertex list
    adj.clear(); // Clear the adjacency list
}

void GraphList::insertVertex(TypeItem item1) {

    if (isFull()) {
        cout << "Erro: o grafo está cheio." << endl;
        return;
    }
   vertex.push_back(item1); // Add the vertex to the vertex list
   adj.resize(vertex.size()); // Resize the adjacency list to accommodate the new vertex
}

int GraphList::getIndex(TypeItem item) {
    for (int i = 0; i < vertex.size(); i++) {
        if (vertex[i] == item) {
            return i; // Return the index of the vertex
        }
    }
    return -1; // Return -1 if the vertex is not found
}

void GraphList::insertEdge(TypeItem item1, TypeItem item2) {
    int index1 = getIndex(item1); // Get the index of the first vertex
    int index2 = getIndex(item2); // Get the index of the second vertex

    if (index1 == -1 || index2 == -1) {
        cout << "Error: vertex not found." << endl;
        return;
    } // Check if both vertices exist
    adj[index1].push_back(item2); // Add the second vertex to the adjacency list of the first vertex
    adj[index2].push_back(item1); // Add the first vertex to the adjacency list of the second vertex
}

bool GraphList::isEmpty() {
    return vertex.empty(); // Check if the vertex list is empty
}

bool GraphList::isFull() {
    return vertex.size() == v; // Check if the vertex list is full
}
void GraphList::printGraph() {
    for (int i = 0; i < vertex.size(); i++) {
        cout << vertex[i] << " -> "; // Print the vertex name
        for (auto it = adj[i].begin(); it != adj[i].end(); ++it) {
            cout << *it << " "; // Print the adjacent vertices
        }
        cout << endl; // Move to the next line after printing all adjacent vertices
    }
}

void GraphList::PrinterAdjacencyList(){
    for(int i = 0 ; i < vertex.size(); i++){
        cout<< adj[i].front() << "  "; // Print the vertex name
    }  
    
}

int GraphList::getvertexDegree(TypeItem item) {
    int index = getIndex(item); // Get the index of the vertex
    if (index != -1) {
        return adj[index].size(); // Return the degree of the vertex
    }
    return -1; // Return -1 if the vertex is not found
}

void GraphList::bfs(TypeItem startVertex) {
    int startIndex = getIndex(startVertex);
    if (startIndex == -1) {
        cout << "Vertex not found.\n";
        return;
    }

    vector<bool> visited(vertex.size(), false);
    queue<int> q;

    visited[startIndex] = true;
    q.push(startIndex);

    cout << "BFS traversal starting from '" << startVertex << "': ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << vertex[current] << " ";

        for (const auto& neighborName : adj[current]) {
            int neighborIndex = getIndex(neighborName);
            if (neighborIndex != -1 && !visited[neighborIndex]) {
                visited[neighborIndex] = true;
                q.push(neighborIndex);
            }
        }
    }
    cout << endl;
}

void GraphList::dfsUtil(int currentIndex, vector<bool>& visited, vector<TypeItem>& result) {
    visited[currentIndex] = true;
    result.push_back(vertex[currentIndex]);

    for (const auto& neighborName : adj[currentIndex]) {
        int neighborIndex = getIndex(neighborName);
        if (neighborIndex != -1 && !visited[neighborIndex]) {
            dfsUtil(neighborIndex, visited, result);
        }
    }
}

vector<TypeItem> GraphList::dfs(TypeItem startVertex) {
    int startIndex = getIndex(startVertex);
    vector<TypeItem> result;

    if (startIndex == -1) {
        cout << "Vertex not found.\n";
        return result;
    }

    vector<bool> visited(vertex.size(), false);
    dfsUtil(startIndex, visited, result);
    return result;
}





