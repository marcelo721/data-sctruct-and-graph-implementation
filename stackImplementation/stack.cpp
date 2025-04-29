#include <iostream>
#include "stack.h"

using namespace std;


    // Constructor
    stack::stack(){
        size = 0;
        structure = new TipeItem[MAX_ITEM];
    }

    stack::~stack(){
        delete[] structure;
    }

    bool stack::isFull(){
        return size == MAX_ITEM;
    }

    bool stack::isEmpty(){
        return size == 0;
    }

    void stack::push(TipeItem item){
        if(isFull()){
            cout << "Stack is full" << endl;
            return;
        }
        structure[size] = item;
        size++;
    }

    TipeItem stack::pop(){
       if(isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        size--;
        return structure[size];
    }

    void stack::print(){
        for(int i = size - 1; i >= 0; i--){
            cout << structure[i] << " ";
        }
        cout << endl;   
    }

    int stack::lenghtOfStack(){
        return size;
    }