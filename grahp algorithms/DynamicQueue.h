typedef int TypeItem;


class Node{
    public:
    TypeItem data;
    Node* next;
};


class DynamicQueue
{
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue
public:
DynamicQueue();
~DynamicQueue();
bool isEmpty();
bool isFull();
void push(TypeItem item);
TypeItem pop();
void printQueue();
};
