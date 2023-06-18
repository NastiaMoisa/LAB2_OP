#ifndef CLASSES_H
#define CLASSES_H

template <typename T>
class SetOperations {
private:
    unordered_set<T> set;
    typename unordered_set<T>::iterator iterator;

public:
    void clearSet() {
        set.clear();
        cout << "Set is cleared" << endl;
    }

    void checkMembership(const T& element) {
        if (set.count(element) > 0) {
            cout << "Element " << element << " belongs to the set" << endl;
        } else {
            cout << "Element " << element << " does not belong to the set" << endl;
        }
    }

    void insertElement(const T& element) {
        set.insert(element);
        cout << "Element " << element << " was added to the set" << endl;
    }

    void setIteratorToBegin() {
        iterator = set.begin();
    }

    bool isIteratorAtEnd() {
        return iterator == set.end();
    }

    const T& getCurrentElement() {
        return *iterator;
    }

    void moveToNextElement() {
        ++iterator;
    }

    void printSet() {
        cout << "Set:";
        for (const T& element : set) {
            cout << element << " ";
        }
        cout << endl;
    }

    unordered_set<T> getSet() const {
        return set;
    }

    unordered_set<T> unionSets(const unordered_set<T>& otherSet) {
        unordered_set<T> resultSet = set;
        resultSet.insert(otherSet.begin(), otherSet.end());
        return resultSet;
    }


};
#endif