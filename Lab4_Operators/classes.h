#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double p;
    double fi;

public:
    Complex(double p, double fi) {
        this->p = p;
        this->fi = fi;
    }

    Complex() {
        this->p = 0;
        this->fi = 0;
    }

    Complex(double a, double b, bool isRectangular) {
        if (isRectangular) {
            this->p = sqrt(a * a + b * b);
            this->fi = atan2(b, a);
        }
        else {
            this->p = a;
            this->fi = b;
        }
    }

    double getReal() const {
        return p * cos(fi);
    }

    double getImag() const {
        return p * sin(fi);
    }

    Complex operator++() {
        p++;
        return *this;
    }

    Complex operator--(int) {           // постфіксний декримент
        Complex temp(*this);            // конструктор копіювання
        fi--;
        return temp;
    }

    Complex operator+(Complex other) {
        double a = getReal() + other.getReal();
        double b = getImag() + other.getImag();
        return Complex(a, b, true);
    }

    void toAlgebraic() const {
        cout << "Algebraic form: " << p << " * (cos(" << fi << ") + i*sin(" << fi << "))" << endl;
    }

    void toAlgebraicCalcForm() const {
        double x = p*cos(fi);
        double y = p*sin(fi);

        if (y < 0){
            cout << "After calculation: " << x << " - i*" << y << endl;
        } else {
            cout << "After calculation: " << x << " + i*" << y << endl;
        }
    }

};
