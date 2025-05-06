#include <iostream>
#include "queue.h"

using namespace std;

int main(int argc, char const *argv[]){

    queue q;
    int option;
    Typeitem item;

    cout << "Queue Implementation" << endl;

    do
    {
        cout << "1. Add item to queue" << endl;
        cout << "2. Remove item from queue" << endl;
        cout << "3. Print queue" << endl;
        cout << "4. Check if queue is empty" << endl;
        cout << "5. Check if queue is full" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        std::cin >> option;

        switch (option)
        {
            case 1:
                std::cout << "Enter item to add: ";
                std::cin >> item;
                q.add(item);
                break;
            case 2:
                item = q.remove();
                if (item != -1) {
                    std::cout << "Removed item: " << item << std::endl;
                }
                break;
            case 3:
                q.printQueue();
                break;
            case 4:
                if (q.isEmpty()) {
                    std::cout << "Queue is empty." << std::endl;
                } else {
                    std::cout << "Queue is not empty." << std::endl;
                }
                break;
            case 5:
                if (q.isFull()) {
                    std::cout << "Queue is full." << std::endl;
                } else {
                    std::cout << "Queue is not full." << std::endl;
                }
                break;
            case 0:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid option, please try again." << std::endl;
        }
    } while (option != 0);

    return 0;
}
