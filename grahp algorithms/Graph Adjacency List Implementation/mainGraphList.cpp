#include <iostream>
#include "GraphList.h"

using namespace std;

int main() {
    int maxVertices, nullEdgeValue;
    cout << "Enter the maximum number of vertices: ";
    cin >> maxVertices;

    cout << "Enter the null edge value (if not used, enter 0): ";
    cin >> nullEdgeValue;

    GraphList graph(maxVertices, nullEdgeValue);

    TypeItem vertex1, vertex2;
    int option, degree;

    do {
        cout << "\n--- Graph Menu ---\n";
        cout << "0 - Exit\n";
        cout << "1 - Insert a vertex\n";
        cout << "2 - Insert an edge\n";
        cout << "3 - Get vertex degree\n";
        cout << "4 - Print graph\n";
        cout << "5 - Print adjacency list\n";
        cout << "6 - verify is Graph is connected\n";
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
                cout << "Adjacency List:\n";
                graph.PrinterAdjacencyList();
                break;
            case 6:
                if (graph.isConnected()) {
                    cout << "The graph is connected.\n";
                } else {
                    cout << "The graph is not connected.\n";
                }
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid option! Try again.\n";
        }

    } while (option != 0);

    return 0;
}
