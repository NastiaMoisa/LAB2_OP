#include "functions.h"

int main() {
    const int MAX_PROGRESSIONS = 3;
    ArithmeticProgression progressions[MAX_PROGRESSIONS] = {
            ArithmeticProgression(0, 0, 0),
            ArithmeticProgression(1, 2, 5),
            ArithmeticProgression(3, 4, 3),
    };

    int n = inputProgressions(progressions);
    maxSumProgression(progressions, n);
    return 0;
}
