#include <iostream>
#include "Graph.h"

using namespace std;

    Graph::Graph(int max, int nullvalue){

        numberOfVertex = 0;
        maxVertexCount = max;
        NullEdgeIndex = nullvalue;

        vertexList = new TypeItem[maxVertexCount];
        adjacencyMatrix = new int*[maxVertexCount];

        for(int i = 0; i < maxVertexCount; i++){
            adjacencyMatrix[i] = new int[maxVertexCount];
        }

        for (int i = 0; i < maxVertexCount; i++){
            for(int j = 0; j < maxVertexCount; j++){
                adjacencyMatrix[i][j] = NullEdgeIndex;
            }
        }
    }

    Graph::~Graph(){
        delete [] vertexList;
        for(int i = 0; i < maxVertexCount; i++){
           delete [] adjacencyMatrix[i];
        }
        delete [] adjacencyMatrix; 
    }	

    int Graph::getIndex(TypeItem item){
        int index = 0;
        
        while (item != vertexList[index]){
            index++;
        }
        if (item == vertexList[index]){
            return index;
        } else {
            return -1;
        } 
    }

    bool Graph::isFull(){
        return numberOfVertex == maxVertexCount;
    }

    void Graph::insertVertex(TypeItem item){
        if (isFull()){
            cout << "Graph is full" << endl;
            return;
        } else {
            vertexList[numberOfVertex] = item;
            numberOfVertex++;
        }
    }

    void Graph::insertEdge(TypeItem NodeIn, TypeItem NodeOut, int weight){
        int line = getIndex(NodeOut);
        int column = getIndex(NodeIn);

        if(line == -1 || column == -1){
            cout << "Vertex not found" << endl;
            return;
        } else if (line == column){// não contém laços 
            cout << "Cannot insert edge to itself" << endl;
            return;
        } else if (adjacencyMatrix[line][column] != NullEdgeIndex){
            cout << "Edge already exists" << endl;
            return;
        }

        adjacencyMatrix[line][column] = weight;
        adjacencyMatrix[column][line] = weight;
    }

    int Graph::getWeight(TypeItem NodeIn, TypeItem NodeOut){

        int line = getIndex(NodeOut);
        int column = getIndex(NodeIn);

        if(line == -1 || column == -1){
            cout << "Vertex not found" << endl;
            return -1;
        } else if (line == column){// não contém laços 
            cout << "Cannot insert edge to itself" << endl;
            return -1;
        } else if (adjacencyMatrix[line][column] == NullEdgeIndex){
            cout << "Edge does not exist" << endl;
            return -1;
        }
        return adjacencyMatrix[line][column];
    }

    int Graph::getvertexDegree(TypeItem item){
        int index = getIndex(item);
        if (index == -1){
            cout << "Vertex not found" << endl;
            return -1;
        } else {
            int degree = 0;
            for (int i = 0; i < numberOfVertex; i++){
                if (adjacencyMatrix[index][i] != NullEdgeIndex){
                    degree++;
                }
            }
            return degree;
        }
    }

    void Graph::printVertex(){
        for (int i = 0; i < numberOfVertex; i++){
            cout << vertexList[i] << " ";
        }
        cout << endl;
    }

    void Graph::printAdjacencyMatrix(){
        for (int i = 0; i < numberOfVertex; i++){
            for (int j = 0; j < numberOfVertex; j++){
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }