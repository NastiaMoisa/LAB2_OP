#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

double enterFloatNum(string message){
    double num;

    string s;
    while (true) {
        cout << message;
        cin >> num;
        if (cin.fail()) {
            cout << "Error. Enter an integer number\n";
            cin.clear();
            getline(cin, s);
        } else {
            getline(cin, s);
            break;
        }
    }

    return num;
}

void calculate(){
    double p1 = enterFloatNum("Enter p1:");
    double fi1 = enterFloatNum("Enter fi1:");
    double p2 = enterFloatNum("Enter p2:");
    double fi2 = enterFloatNum("Enter fi2:");

    Complex k1(p1, fi1);
    Complex k2(p2, fi2);
    Complex k3;

    ++k1;
    k2--;
    k3 = k1 + k2;

    k3.toAlgebraic();
    k3.toAlgebraicCalcForm();
}
