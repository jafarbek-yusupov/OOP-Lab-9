#include <iostream>
#include "List.h"
using namespace std;
int main() {
    List<int> myList;

    myList.addFront(10);
    myList.addTail(20);
    myList.addFront(5);
    myList.addTail(30);

    cout << "List (Forward): ";
    myList.displayForward();

    cout << "List (Backward): ";
    myList.displayTail();
    cout << "Front Element: " << myList.getFront() << endl;
    cout << "Back Element: " << myList.getTail() << endl;

    return 0;
}
