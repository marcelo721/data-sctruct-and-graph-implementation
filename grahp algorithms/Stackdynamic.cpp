#include<iostream>
#include "stackDynamic.h"
#include <cstddef>

using namespace std;

    StackDynamic::StackDynamic(){
        top = NULL;
    }
    StackDynamic::~StackDynamic(){
        Node* current = top;
        Node* nextNode;
        while(current != NULL){
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        top = NULL; 
    }

    bool StackDynamic::isFull(){
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
    bool StackDynamic::isEmpty(){
        return top == NULL;
    }
    void StackDynamic::push(TypeItem item){
        if(isFull()){
            cout << "Stack is full. Cannot push item." << endl;
            return;
        }else{
            Node* newNode = new Node;
            newNode->data = item;
            newNode->next = top;
            top = newNode;
        }   

    }
    TypeItem StackDynamic::pop(){
        if(isEmpty()){
            cout << "Stack is empty. Cannot pop item." << endl;
            return -1; // or some other error value
        }else{
            Node* temp = top;
            TypeItem item = top->data;
            top = top->next;
            delete temp;
            return item;
        }
    }
    void StackDynamic::print(){
        Node* current = top;
        while(current != NULL){
            cout << current->data << ", ";
            current = current->next;
        }
        cout << endl;
    }
    int StackDynamic::lenghtOfStack(){
        Node* current = top;
        int count = 0;
        while(current != NULL){
            count++;
            current = current->next;
        }
        return count;
    }