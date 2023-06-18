#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "TIntNumber2.h"
#include "TIntNumber16.h"

void readBinaryNumbers(TIntNumber2& binarySum, int m);
void readHexadecimalNumbers(TIntNumber16& hexSum, int n);
void printResults(const TIntNumber2& binarySum, const TIntNumber16& hexSum);

#endif // FUNCTIONS_H
