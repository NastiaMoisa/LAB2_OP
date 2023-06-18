#ifndef TINTNUMBER_H
#define TINTNUMBER_H

#include <string>
using namespace std;

class TIntNumber {
protected:
    string number;
    int base;

public:
    TIntNumber(const string& num, int b);
    virtual ~TIntNumber() {}

    virtual void add(const string& num) = 0;
    virtual string getNumber() const = 0;

    int convertToBase10(char digit) const;
    string convertToBaseX(int decimal, int newBase) const;
    char convertToBaseX(int decimal) const;
    string convertNumber(const string& num, int oldBase, int newBase) const;
    int convertToDecimal(const string& num, int oldBase) const;
};

#endif
