#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

double enterFloatNum(string message){
    double num;
    string dummy;
    while (true) {
        cout << message;
        cin >> num;
        if (cin.fail()) {
            cout << "Error. Enter an integer number\n";
            cin.clear();
            getline(cin, dummy);
        } else {
            getline(cin, dummy);
            break;
        }
    }
    return num;
}



int enterNum(string message){
    int num;
    while (true) {
        cout << message;
        cin >> num;

        if (cin.fail()) {
            cout << "Error. Enter an integer number\n";
            cin.clear();  // скидання стану потоку
            cin.sync(); // очищення буфера вводу
        } else {
            cin.sync(); // очищення буфера вводу
            break;
        }
    }
    return num;
}


void input(int counter, int n, ArithmeticProgression progressions[]){
    for (int j = counter; j < n; j++) {
        cout << "Enter data for " << j + 1 << " progression:\n";
        double first = enterFloatNum("The first element:");
        double diff = enterFloatNum("Difference:");
        int count = enterNum("Number of elements:");
        progressions[j] = ArithmeticProgression(first, diff, count);
    }
}


int inputProgressions(ArithmeticProgression progressions[]) {
    int c, n;
    n = enterNum("\nEnter number of progressions:");
    input(0, n, progressions);

    do{
        c = enterNum("\nDo you want to add info?\n1 - yes\n2 - no\n");

        if(c==1){
            int n1 = enterNum("\nEnter number of progressions:");
            n1 += n;
            input(n, n1, progressions);
        }
    }while(c==1);

    return n;
}


void maxSumProgression(ArithmeticProgression progressions[], int n) {
    double max_sum = 0;
    int max_index = -1;
    for (int i = 0; i < n; i++) {
        double s = progressions[i].sum();
        if (s > max_sum) {
            max_sum = s;
            max_index = i;
        }
    }
    if (max_index != -1) {
        printProgressionInfo(progressions[max_index], max_index);
    } else {
        cout << "Array is empty or all progressions have sum of els = 0.\n";
    }
}


void printProgressionInfo(ArithmeticProgression progressions, int index) {
    cout << "Number of progression with the greatest sum:" << index + 1 << endl;
    cout << "Summa:" << progressions.sum()<< endl;
    cout << "The first element:" << progressions.getFirst() << endl;
    cout << "Difference: " << progressions.getDiff() << endl;
    cout << "Number of elements:" << progressions.getCount() << endl;
}
