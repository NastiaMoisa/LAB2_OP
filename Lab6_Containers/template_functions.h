#include "classes.h"
#include "functions.h"

template <typename T>
void inputElements(SetOperations<T>& setOperations, size_t setSize) {
    cout << endl << "Enter " << setSize << " elements for the set:" << endl;
    for (size_t i = 0; i < setSize; ++i) {
        T element;
        cin >> element;
        setOperations.insertElement(element);
    }
    setOperations.printSet();
}

template <typename T>
void performMenuOperation(SetOperations<T>& setOperations, int choice) {
    switch (choice) {
        case 1:
            setOperations.clearSet();
            break;
        case 2: {
            cout << endl << "Enter the element to check:";
            T element;
            cin >> element;
            setOperations.checkMembership(element);
            break;
        }
        case 3: {
            cout << endl << "Enter new element:";
            T element;
            cin >> element;
            setOperations.insertElement(element);
            break;
        }
        case 4: {
            size_t setSize = getInputSize();
            string dataType = getInputDataType();
            SetOperations<T> otherSetOperations;  // Оновлено тип об'єкта
            inputElements(otherSetOperations, setSize);
            unordered_set<T> resultSet = setOperations.unionSets(otherSetOperations.getSet());
            cout << endl << "Result of the union of two sets:";
            for (const T& element : resultSet) {
                cout << element << " ";
            }
            cout << endl;
            break;
        }
        case 5:
            setOperations.setIteratorToBegin();
            cout << endl << "Iterator is set to the beginning of the set" << endl;
            break;
        case 6: {
            bool isEnd = setOperations.isIteratorAtEnd();
            if (isEnd) {
                cout << endl << "Iterator is at the end of the set" << endl;
            } else {
                cout << endl << "Iterator is not at the end of the set" << endl;
            }
            break;
        }
        case 7: {
            const T& currentElement = setOperations.getCurrentElement();
            cout << endl << "Current element from iterator:" << currentElement << endl;
            break;
        }
        case 8:
            setOperations.moveToNextElement();
            cout << "Moved to the next element with the iterator" << endl;
            break;
        case 0:
            cout << "Exit..." << endl;
            break;
        default:
            cout << "Invalid number of the operation. Try again" << endl;
            break;
    }
    setOperations.printSet();

}
