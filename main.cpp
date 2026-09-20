// main.cpp
// comp2 lab 3 quinn schuyler
#include <iostream>
#include <iomanip>
#include "Q10p6.h"
using namespace std;

int main(){
    cout << "testing Q10p6 class\n\n";
 
    //constructors and conversions test
    Q10p6 num1(5.1); //int
    Q10p6 num2(2.5f); //float
    

    cout << "num1 (expected 5): " << num1.toInt();
    cout << "\n" << num1.toRaw() << "\n";

    cout << "num2 (expected 2.5): " << num2.toFloat();
    cout << "\n" << num2.toRaw() << "\n";

    // addition
    Q10p6 sum = num1 + num2;
    cout << "addition (5 + 2.5): " << sum.toFloat() << " (expected: 7.5)\n";
    cout << sum.toRaw() << "\n";

    //subtraction
    Q10p6 diff = num1 - num2;
    cout << "subtraction (5 - 2.5): " << diff.toFloat() << " (expected: 2.5)\n";
    cout << diff.toRaw() << "\n";

    //multiplication
    Q10p6 prod = num1 * num2;
    cout << "multiplication (5 * 2.5): " << prod.toFloat() << " (expected: 12.5)\n";
    cout << prod.toRaw() << "\n";


    // division
    Q10p6 quot = num1 / num2;
    cout << "division (5 / 2.5): " << quot.toFloat() << " (expected: 2)\n";
    cout << quot.toRaw() << "\n";


    // == / comparison
    Q10p6 num3(5); // another 5
    if (num1 == num3) {
        cout << "equality (num1 == num3): passed\n";
    } else {
        cout << "equality (num1 == num3): failed\n";
    }
    cout << "\ndone \n";
}