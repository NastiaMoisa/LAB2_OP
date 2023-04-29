class ArithmeticProgression {
public:
    ArithmeticProgression(double first, double diff, double count) {         //class constructor
        this->first = first;
        this->diff = diff;
        this->count = count;
    }

    double sum() {
        double s = 0;
        for (double i = 0; i < count; i++) {
            s += first + i * diff;
        }
        return s;
    }

    double getFirst() const {
        return first;
    }

    double getDiff() const {
        return diff;
    }

    double getCount() const {
        return count;
    }

private:
    double first;
    double diff;
    double count;
};