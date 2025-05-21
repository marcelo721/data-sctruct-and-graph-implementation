#include <iostream>
#include "GraphList.h"

using namespace std;

int main() {

    int typeGraph; 

    cout << "nos informe se seu grafo eh direcionado o n \n";
    cout << "1 - Grafo direcionado \n";
    cout << "2 - Grafo nao direcionado \n";

    cin>> typeGraph;
    int maxVertices, nullEdgeValue;
    cout << "Enter the maximum number of vertices: ";
    cin >> maxVertices;

    cout << "Enter the null edge value (if not used, enter 0): ";
    cin >> nullEdgeValue;

    GraphList graph(maxVertices, nullEdgeValue, typeGraph);

    TypeItem vertex1, vertex2;
    int option, degree;

    do {
        cout << "\n--- Graph Menu ---\n";
        cout << "0 - Exit\n";
        cout << "1 - Insert a vertex\n";
        cout << "2 - Insert an edge\n";
        cout << "3 - Get vertex degree\n";
        cout << "4 - Print graph\n";
        cout << "5 - Print vertex list\n";
        cout << "6 - verify is Graph is connected\n";
        cout << "7 - verify is Graph is bipartite\n";
        cout << "8 - verify is Graph is tree\n";
        cout<< "9 - verify is Graph is cycle\n";
        cout << "10 - verify is Graph is topological sort\n";
        if (typeGraph == 1){
            cout << "11 - See topological Sort";
        }
        
        cout << "Choose an option: ";
        cin >> option;

        switch(option) {
            case 1:
                if (graph.isFull()) {
                    cout << "Graph is full! Cannot insert more vertices.\n";
                    break;
                }
                cout << "Enter vertex name to insert: ";
                cin >> vertex1;
                graph.insertVertex(vertex1);
                break;

            case 2:
                cout << "Enter the first vertex: ";
                cin >> vertex1;
                cout << "Enter the second vertex: ";
                cin >> vertex2;
                graph.insertEdge(vertex1, vertex2);
                break;

            case 3:
                cout << "Enter the vertex to get its degree: ";
                cin >> vertex1;
                degree = graph.getvertexDegree(vertex1);
                if (degree != -1)
                    cout << "Degree of vertex '" << vertex1 << "' is: " << degree << "\n";
                else
                    cout << "Vertex not found!\n";
                break;

            case 4:
                cout << "\n--- Graph Structure ---\n";
                graph.printGraph();
                break;
            case 5:
                cout << "Vertex List:\n";
                graph.printVertex();
                break;
            case 6:
                if (graph.isConnected()) {
                    cout << "The graph is connected.\n";
                } else {
                    cout << "The graph is not connected.\n";
                }
                break;
            
            case 7:
                if (graph.isBipartite()) {
                    cout << "The graph is bipartite.\n";
                } else {
                    cout << "The graph is not bipartite.\n";
                }
                break;
            case 8:
                if (graph.isTree()) {
                    cout << "The graph is a tree.\n";
                } else {
                    cout << "The graph is not a tree.\n";
                }
                break;

            case 9: 
                if (graph.hasCycle()) {
                    cout << "The graph has a cycle.\n";
                } else {
                    cout << "The graph does not have a cycle.\n";
                }
                break;
            case 10:
                if(graph.isTopological()){
                    cout<< "O grafo admite uma ordenacao topologica";
                }else {
                    cout<< "O grafo n admite uma ordenacao topologica";
                }

            case 11:
                graph.isTopologicalSort();
                
            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid option! Try again.\n";
        }

    } while (option != 0);

    return 0;
}
