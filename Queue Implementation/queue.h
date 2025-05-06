typedef int Typeitem;
const int MAX = 100;

class queue{
    private:
    int first, last;
    Typeitem* structure;

    public:
    queue();
    ~queue();
    bool isEmpty();
    bool isFull();
    void add(Typeitem item);
    Typeitem remove();
    void printQueue();
};