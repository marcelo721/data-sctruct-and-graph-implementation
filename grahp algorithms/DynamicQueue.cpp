#include <iostream>
 #include "DynamicQueue.h"
 #include <cstddef>
 #include <new>

 using namespace std;

 DynamicQueue::DynamicQueue(){
        front = NULL; // Initialize front to NULL
        rear = NULL;  // Initialize rear to NULL
 }
 DynamicQueue::~DynamicQueue(){
    Node* current;
    while (front != NULL) {
        current = front;
        front = front->next; 
        delete current;
    }
    rear = NULL; // Set rear to NULL after deleting all nodes
    cout << "Queue destroyed." << endl; 
 }
 bool DynamicQueue::isEmpty(){
    return front == NULL; // Check if the queue is empty
 }
 bool DynamicQueue::isFull(){
    Node* newNode;
        try{
            newNode = new Node;
            delete newNode;
            return false; // Stack is not full
        }
        catch(bad_alloc exception){
            return true; // Stack is full
        }
 }
 void DynamicQueue::push(TypeItem item){
    if(isFull()){
        cout << "Queue is full. Cannot push item." << endl;
        return;
    }else{
        Node* newNode = new Node; // Create a new node
        newNode->data = item; // Assign data to the new node
        newNode->next = NULL;
        if (front == NULL){
            front = newNode; // If the queue is empty, set front to the new node
              // Set rear to the new node
        }else{
            rear->next = newNode; // Link the new node to the end of the queue
        }
        rear = newNode;
        
    }
 }
 TypeItem DynamicQueue::pop(){
    if(isEmpty()){
        cout << "Queue is empty. Cannot pop item." << endl;
        return -1; // Return a sentinel value or throw an exception
    }else{
        Node* temp = front;
        TypeItem item = front->data; // Get the data from the front node
        front = front->next; // Move front to the next node
        if(front == NULL){
            rear = NULL; // If the queue is empty after popping, set rear to NULL
        }
        delete temp; // Delete the old front node
        return item; // Return the popped item
    }
 }
void DynamicQueue::printQueue(){
    Node* current = front; // Start from the front of the queue
    if (isEmpty()){
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    while (current != NULL) {
        cout << current->data << " "; // Print the data of each node
        current = current->next; // Move to the next node
    }
    cout << endl; // Print a newline at the end
}