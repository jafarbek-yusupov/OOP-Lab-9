#include <iostream>
#include "List.h"
using namespace std;

/*********** PART 2 ***********/
int main() {
    List<int> myList;
    // Adding elements to the list
    myList.addFront(10);
    myList.addFront(20);
    myList.addTail(30);
    myList.addTail(40);

    cout << "Initial List: ";
    myList.displayForward();
    // Testing getAt()
    try{ cout << "Element at index 2: " << myList.getAt(2) << endl;}
    catch (const exception& e) { cerr << "Error: " << e.what() << endl;}
    // Testing insertAt()
    try{ cout << "Inserting 99 at index 2..." << endl; myList.insertAt(2,99); myList.displayForward();}
    catch (const exception& e) { cerr << "Error: " << e.what() << endl;}
    // Testing removeAt()
    try { cout << "Removing element at index 3..." << endl; myList.removeAt(3); myList.displayForward();}
    catch (const exception& e) { cerr << "Error: " << e.what() << endl;}
    // Testing removeFront()
    try { cout << "Removing front element..." << endl; myList.removeFront(); myList.displayForward();}
    catch (const exception& e) { cerr << "Error: " << e.what() << endl;}
    // Testing removeTail()
    try { cout << "Removing tail element..." << endl; myList.removeTail(); myList.displayForward();}
    catch (const exception& e) { cerr << "Error: " << e.what() << endl;}
    return 0;
}


/*********** PART 1 ***********/
// int main() {
//     List<int> myList;
//
//     myList.addFront(10);
//     myList.addTail(20);
//     myList.addFront(5);
//     myList.addTail(30);
//
//     cout << "List (Forward): ";
//     myList.displayForward();
//
//     cout << "List (Backward): ";
//     myList.displayTail();
//     cout << "Front Element: " << myList.getFront() << endl;
//     cout << "Back Element: " << myList.getTail() << endl;
//
//     return 0;
// }
