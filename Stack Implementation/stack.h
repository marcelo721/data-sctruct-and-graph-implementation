typedef int TipeItem;
const int MAX_ITEM = 100;
class stack{
    private:
    int size;
    TipeItem* structure;

    public:
    stack();
    ~stack(); 
    bool isFull();
    bool isEmpty();
    void push(TipeItem item);
    TipeItem pop();
    void print();
    int lenghtOfStack();

};
