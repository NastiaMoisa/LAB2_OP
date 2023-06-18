#include <iostream>
#include <unordered_set>
#include <iterator>
#include "functions.h"
#include "template_functions.h"

int main() {
    size_t setSize = getInputSize();
    string dataType = getInputDataType();

    SetOperations<string> setOperations;

    inputElements(setOperations, setSize);

    while (true) {
        int choice = getMenuChoice();
        if (choice == 0) {
            break;
        }
        performMenuOperation(setOperations, choice);
    }

    return 0;
}

