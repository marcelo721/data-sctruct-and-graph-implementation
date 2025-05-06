typedef int TypeItem;


struct Node{
    TypeItem data;
    Node* next;
};

class StackDynamic{

    private:
    Node* top;

    public:
    StackDynamic();
    ~StackDynamic(); 
    bool isFull();
    bool isEmpty();
    void push(TypeItem item);
    TypeItem pop();
    void print();
    int lenghtOfStack();
};