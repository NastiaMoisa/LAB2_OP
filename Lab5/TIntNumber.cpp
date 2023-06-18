#include "TIntNumber.h"

TIntNumber::TIntNumber(const string& num, int b) : number(num), base(b) {}

int TIntNumber::convertToBase10(char digit) const {
    if (digit >= '0' && digit <= '9')
        return digit - '0';
    else if (digit >= 'A' && digit <= 'F')
        return 10 + digit - 'A';
    else if (digit >= 'a' && digit <= 'f')
        return 10 + digit - 'a';
    return 0;
}

std::string TIntNumber::convertToBaseX(int decimal, int newBase) const {
    if (decimal == 0)
        return "0";

    string converted;
    while (decimal > 0) {
        int remainder = decimal % newBase;
        char digit = convertToBaseX(remainder);
        converted = digit + converted;
        decimal /= newBase;
    }
    return converted;
}

char TIntNumber::convertToBaseX(int decimal) const {
    if (decimal >= 0 && decimal <= 9)
        return '0' + decimal;
    else
        return 'A' + decimal - 10;
}

string TIntNumber::convertNumber(const string& num, int oldBase, int newBase) const {
    int decimal = convertToDecimal(num, oldBase);
    string converted = convertToBaseX(decimal, newBase);
    return converted;
}

int TIntNumber::convertToDecimal(const string& num, int oldBase) const {
    int decimal = 0;
    int power = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        int digit = convertToBase10(num[i]);
        decimal += digit * power;
        power *= oldBase;
    }
    return decimal;
}
