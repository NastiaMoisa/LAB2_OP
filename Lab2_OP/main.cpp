#include <iostream>
#include "functions.h"

int main() {

    string filename = "breaks.dat";
    createFile(filename);
    readFile(filename);
    fullCheckUp(filename);

    return 0;
}