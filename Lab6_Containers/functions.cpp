#include <iostream>
#include <iterator>
#include "functions.h"
using namespace std;

size_t getInputSize() {
    size_t setSize;
    cout << endl << "Enter the size for the set:";
    cin >> setSize;
    return setSize;
}

string getInputDataType() {
    string dataType;
    cout << "Enter the data type for the set:";
    cin >> dataType;
    return dataType;
}

int getMenuChoice() {
    int choice;
    cout << "\nMenu:" << endl;
    cout << "1. Clear the set" << endl;
    cout << "2. Check whether an element belongs to the set" << endl;
    cout << "3. Add a new element to the set" << endl;
    cout << "4. Unite the set with another set" << endl;
    cout << "5. Set iterator to the beginning" << endl;
    cout << "6. Check if iterator is at the end" << endl;
    cout << "7. Get current element from iterator" << endl;
    cout << "8. Move to the next element with the iterator" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter the number of the operation:";
    cin >> choice;
    return choice;
}
//
//template <typename T>
//void performMenuOperation(SetOperations<T>& setOperations, int choice) {
//    switch (choice) {
//        case 1:
//            setOperations.clearSet();
//            break;
//        case 2: {
//            cout << "Enter the element to check: ";
//            T element;
//            cin >> element;
//            setOperations.checkMembership(element);
//            break;
//        }
//        case 3: {
//            cout << "Enter new element: ";
//            T element;
//            cin >> element;
//            setOperations.insertElement(element);
//            break;
//        }
//        case 4: {
//            size_t setSize = getInputSize();
//            string dataType = getInputDataType();
//            SetOperations<string> otherSetOperations;
//            inputElements(otherSetOperations, setSize);
//            unordered_set<T> resultSet = setOperations.unionSets(otherSetOperations.getSet());
//            cout << "Result of the union of two sets:" << endl;
//            for (const T& element : resultSet) {
//                cout << element << endl;
//            }
//            cout << endl;
//            break;
//        }
//        case 5:
//            setOperations.setIteratorToBegin();
//            cout << "Iterator is set to the beginning of the set" << endl;
//            break;
//        case 6: {
//            bool isEnd = setOperations.isIteratorAtEnd();
//            if (isEnd) {
//                cout << "Iterator is at the end of the set" << endl;
//            } else {
//                cout << "Iterator is not at the end of the set" << endl;
//            }
//            break;
//        }
//        case 7: {
//            const T& currentElement = setOperations.getCurrentElement();
//            cout << "Current element from iterator: " << currentElement << endl;
//            break;
//        }
//        case 8:
//            setOperations.moveToNextElement();
//            cout << "Moved to the next element with the iterator" << endl;
//            break;
//        case 0:
//            cout << "Exit..." << endl;
//            break;
//        default:
//            cout << "Invalid number of the operation. Try again" << endl;
//            break;
//    }
//    setOperations.printSet();
//}
