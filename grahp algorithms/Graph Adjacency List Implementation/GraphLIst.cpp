#include "GraphList.h"
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

GraphList::GraphList(int numberOfVertices, int nullEdgeIndex, int typeGraph) {
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

    if(typeGraph == 1){// se o grafo n for direcionado 
        adj[index1].push_back(item2);
        adj[index2].push_back(item1);
    }else {
        adj[index1].push_back(item2);
    }
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

void GraphList::printVertex(){
    for(int i = 0 ; i < vertex.size(); i++){
        cout<< vertex[i] << ",  "; // Print the vertex name
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

    for(int i = 0; i < vertex.size(); i++) {
        if (!visited[i]) {
            dfsUtil(i, visited, result); // Visit unvisited vertices
        }
    }
    return result;
}

bool GraphList::isConnected() {
    if (vertex.empty()) return true; // Grafo vazio é considerado conexo

    vector<bool> visited(vertex.size(), false);
    vector<TypeItem> result; // Vetor para armazenar os vértices visitados
    dfsUtil(0, visited, result); // Começa a DFS do primeiro vértice (índice 0)

    // Verifica se todos os vértices foram visitados
    for (bool v : visited) {
        if (!v) return false; // Encontrou vértice não visitado
    }
    return true;
}

int GraphList::numeroDeComponentesConexas(){
    vector<TypeItem> result;
    int count = 0;
    if (!isEmpty()){
        count++;
    }
    
    vector<bool> visited(vertex.size(), false);
    dfsUtil(0, visited, result);

    for(int i = 0; i < vertex.size(); i++) {
        if (!visited[i]) {
            dfsUtil(i, visited, result); // Visit unvisited vertices
            count ++;
        }
    }
    return count;
}

bool GraphList::isBipartiteUtil(int v) {
    for (const auto& neighborName : adj[v]) {
        int neighborIndex = getIndex(neighborName);
        if (neighborIndex != -1) {
            if (color[neighborIndex] == -1) {
                color[neighborIndex] = 1 - color[v]; 
                if (!isBipartiteUtil(neighborIndex)) {
                    return false; 
                }
            } else if (color[neighborIndex] == color[v]) {
                return false;
            }
        }
    }
    return true;
}

bool GraphList::isBipartite() {
        int n = vertex.size();
        color.assign(n, -1);  
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!isBipartiteUtil(i)) {
                    return false;
                }
            }
        }
        return true;
    }

bool GraphList::isTree() {
    if (!isConnected()) {
        return false; // If the graph is not connected, it cannot be a tree
    }

    int edges = 0;
    for (int i = 0; i < vertex.size(); i++) {
        edges += adj[i].size();
    }
    edges /= 2; // Each edge is counted twice in an undirected graph

    return edges == vertex.size() - 1; // A tree has exactly V - 1 edges
}

bool GraphList::hasCycleUtil(int currentIndex, vector<bool>& visited, vector<bool>& inStack) {
    visited[currentIndex] = true;
    inStack[currentIndex] = true;

    for (const auto& neighborName : adj[currentIndex]) {
        int neighborIndex = getIndex(neighborName);
        if (neighborIndex != -1) {
            if (!visited[neighborIndex]) {
                if (hasCycleUtil(neighborIndex, visited, inStack)) {
                    return true;  // ciclo detectado
                }
            }
            else if (inStack[neighborIndex]) {
                return true;  // ciclo detectado
            }
        }
    }

    inStack[currentIndex] = false;
    return false;
}

bool GraphList::hasCycle() {
    int n = vertex.size();
    vector<bool> visited(n, false);
    vector<bool> inStack(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycleUtil(i, visited, inStack)) {
                return true;  // ciclo encontrado
            }
        }
    }
    return false;  // sem ciclos
}

bool GraphList::isTopological(){
    return !hasCycle();
}

void GraphList::isTopologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack, vector<list<TypeItem>>& adj) {
    visited[v] = true;

    for (const auto& neighbor : adj[v]) {
        int neighborIndex = getIndex(neighbor);
        if (!visited[neighborIndex]) {
            isTopologicalSortUtil(neighborIndex, visited, Stack, adj);
        }
    }
    Stack.push(v);
}

void GraphList::isTopologicalSort() {
    stack<int> Stack;
    vector<bool> visited(vertex.size(), false);

    for (int i = 0; i < vertex.size(); i++) {
        if (!visited[i]) {
            isTopologicalSortUtil(i, visited, Stack, adj);
        }
    }

    cout << "Topological Sort: ";
    while (!Stack.empty()) {
        cout << vertex[Stack.top()] << " ";
        Stack.pop();
    }
    cout << endl;
}