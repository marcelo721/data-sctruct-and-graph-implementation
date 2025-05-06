#include <iostream>
#include "stack.h"
using namespace std;

int main(int argc, char const *argv[])
{
    stack stack1;
    TipeItem item;
    int option;
    cout << "Stack Implementation" << endl;

    do {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "4. Is Empty" << endl;
        cout << "5. Is Full" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        if(option < 1 || option > 7) {
            cout << "Invalid option. Please try again." << endl;
            continue;
        }else if (option == 1) {
            cout << "Enter item to push: ";
            cin >> item;
            if(stack1.isFull()) {
                cout << "Stack is full. Cannot push " << item << endl;
            } else {
                stack1.push(item);
                cout << item << " pushed to stack." << endl;
            }
        }else if(option == 2) {
            if(stack1.isEmpty()) {
                cout << "Stack is empty. Cannot pop." << endl;
            } else {
                item = stack1.pop();
                cout << item << " popped from stack." << endl;
            }
        }else if(option == 4) {
            if(stack1.isEmpty()) {
                cout << "Stack is empty." << endl;
            } else {
                cout << "Stack is not empty." << endl;
            }
        }else if(option == 5) {
            if(stack1.isFull()) {
                cout << "Stack is full." << endl;
            } else {
                cout << "Stack is not full." << endl;
            }
        }else if(option == 6) {
            if(stack1.isEmpty()) {
                cout << "Stack is empty." << endl;
            } else {
                cout << "Stack contents: ";
                stack1.print();
            }
        }else{
            cout << "Exiting program." << endl;
        }

    }while(option != 7);


    return 0;
}
