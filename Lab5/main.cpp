#include <iostream>
#include "TIntNumber2.h"
#include "TIntNumber16.h"
#include "functions.h"

int main() {
    int m, n;
    cout << "Enter the number of binary numbers (m):";
    cin >> m;

    cout << "Enter the number of hexadecimal numbers (n):";
    cin >> n;

    TIntNumber2 binarySum("0");
    TIntNumber16 hexSum("0");

    readBinaryNumbers(binarySum, m);
    readHexadecimalNumbers(hexSum, n);
    printResults(binarySum, hexSum);

    return 0;
}
