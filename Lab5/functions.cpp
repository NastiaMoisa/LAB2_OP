#include <iostream>
#include <string>
#include "TIntNumber2.h"
#include "TIntNumber16.h"

void readBinaryNumbers(TIntNumber2& binarySum, int m) {
    cout << "\n--- Binary Numbers ---\n";
    for (int i = 0; i < m; i++) {
        string binaryNum;
        cout << "Enter binary number " << i + 1 << ": ";
        cin >> binaryNum;

        binarySum.add(binaryNum);
    }
}

void readHexadecimalNumbers(TIntNumber16& hexSum, int n) {
    cout << "\n--- Hexadecimal Numbers ---\n";
    for (int i = 0; i < n; i++) {
        string hexNum;
        cout << "Enter hexadecimal number " << i + 1 << ": ";
        cin >> hexNum;

        hexSum.add(hexNum);
    }
}

void printResults(const TIntNumber2& binarySum, const TIntNumber16& hexSum) {
    string binarySumStr = binarySum.getNumber();
    string hexSumStr = hexSum.getNumber();

    cout << "\nSum of binary numbers:" << binarySumStr << endl;
    cout << "Sum of hexadecimal numbers:" << hexSumStr << endl;

    // Convert hexSum to binary
    string binarySumFromHex = hexSum.convertNumber(hexSumStr, 16, 2);
    cout << "Sum of hexadecimal numbers in binary:" << binarySumFromHex << endl;

    if (binarySumStr.length() > hexSumStr.length())
        cout << "Sum of binary numbers is larger" << endl;
    else if (binarySumStr.length() < hexSumStr.length())
        cout << "Sum of hexadecimal numbers is larger" << endl;
    else {
        if (binarySumStr > hexSumStr)
            cout << "Sum of binary numbers is larger" << endl;
        else if (binarySumStr < hexSumStr)
            cout << "Sum of hexadecimal numbers is larger" << endl;
        else
            cout << "Sum of binary numbers and hexadecimal numbers are equal" << endl;
    }
}
