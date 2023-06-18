#ifndef TINTNUMBER16_H
#define TINTNUMBER16_H

#include "TIntNumber.h"
using namespace std;

class TIntNumber16 : public TIntNumber {
public:
    TIntNumber16(const string& num);

    void add(const string& num) override;
    string getNumber() const override;

private:
    string addNumbers(const string& num1, const string& num2) const;
};

#endif
