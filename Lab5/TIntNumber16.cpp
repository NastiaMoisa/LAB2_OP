#include "TIntNumber16.h"

TIntNumber16::TIntNumber16(const string& num) : TIntNumber(num, 16) {}

void TIntNumber16::add(const string& num) {
    number = addNumbers(number, num);
}

string TIntNumber16::getNumber() const {
    return number;
}

string TIntNumber16::addNumbers(const string& num1, const string& num2) const {
    int len1 = num1.length();
    int len2 = num2.length();

    int carry = 0;
    string sum;

    int i = len1 - 1, j = len2 - 1;
    while (i >= 0 || j >= 0 || carry != 0) {
        int digit1 = (i >= 0) ? convertToBase10(num1[i--]) : 0;
        int digit2 = (j >= 0) ? convertToBase10(num2[j--]) : 0;

        int digitSum = digit1 + digit2 + carry;
        carry = digitSum / base;
        digitSum %= base;

        sum = convertToBaseX(digitSum) + sum;
    }

    return sum;
}
