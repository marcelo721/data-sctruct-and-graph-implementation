#include <iostream>
#include "queue.h"

using namespace std;

queue::queue(){
    first = 0;
    last = 0;
    structure = new Typeitem[MAX];
}

queue::~queue(){
    delete[] structure;
}

bool queue:: isEmpty(){
    return first == last;
}
bool queue:: isFull(){
    return (first - last== MAX);
}
void queue:: add(Typeitem item){
    if (isFull()){
        cout << "Queue is full" << endl;
        return;
    }
    structure[last & MAX] = item;
    last += 1;
}
void queue:: printQueue(){
    for (int i = first; i < last; i++){
        cout << structure[i % MAX] << " ";
    }
    cout << endl;
}

Typeitem queue:: remove(){
    if (isEmpty()){
        cout << "Queue is empty" << endl;
        return -1; // or some other error value
    }
    Typeitem item = structure[first % MAX];
    first += 1;
    return item;
}