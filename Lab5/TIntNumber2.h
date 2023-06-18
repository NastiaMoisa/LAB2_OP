#ifndef TINTNUMBER2_H
#define TINTNUMBER2_H

#include "TIntNumber.h"
using namespace std;

class TIntNumber2 : public TIntNumber {
public:
    TIntNumber2(const string& num);

    void add(const string& num) override;
    string getNumber() const override;

private:
    string addNumbers(const string& num1, const string& num2) const;
};

#endif
