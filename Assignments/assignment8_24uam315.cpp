#include <iostream>
using namespace std;

// Template function to find the maximum of two values
template <typename T>
T findMax(T a, T b) {
    // Turnery Operator is used
    return (a > b) ? a : b;
}

// Template class for the Calculator
template <typename T>
class Calculator {
private:
    T num1, num2; // Two numbers to perform calculations on

public:
    // Constructor to initialize the numbers
    Calculator(T n1, T n2) : num1(n1), num2(n2) {}

    // Addition function
    T add() {
        return num1 + num2;
    }

    // Subtraction function
    T subtract() {
        return num1 - num2;
    }

    // Multiplication function
    T multiply() {
        return num1 * num2;
    }

    // Division function
    T divide() {
        if (num2 != 0)
            return num1 / num2;
        else
            throw "Division by zero is not allowed!";
    }
};

int main() {
    // Testing findMax with integers, floats, and doubles
    int int1 = 9, int2 = 10;
    cout << "Max of " << int1 << " and " << int2 << " is: " << findMax(int1, int2) << endl;

    float float1 = 3.5, float2 = 2.2;
    cout << "Max of " << float1 << " and " << float2 << " is: " << findMax(float1, float2) << endl;

    double double1 = 6.4, double2 = 15.6;
    cout << "Max of " << double1 << " and " << double2 << " is: " << findMax(double1, double2) << endl;

    // Testing Calculator class with integers
    Calculator<int> intCalc(int1, int2);
    cout << "Integer Operations: " << int1 << " + " << int2 << " = " << intCalc.add() << endl;
    cout << int1 << " - " << int2 << " = " << intCalc.subtract() << endl;
    cout << int1 << " * " << int2 << " = " << intCalc.multiply() << endl;

    // Testing Calculator class with floats
    Calculator<float> floatCalc(float1, float2);
    cout << "Float Operations: " << float1 << " + " << float2 << " = " << floatCalc.add() << endl;
    cout << float1 << " - " << float2 << " = " << floatCalc.subtract() << endl;
    cout << float1 << " * " << float2 << " = " << floatCalc.multiply() << endl;
    

    // Testing Calculator class with doubles
    Calculator<double> doubleCalc(double1, double2);
    cout << "Double Operations: " << double1 << " + " << double2 << " = " << doubleCalc.add() << endl;
    cout << double1 << " - " << double2 << " = " << doubleCalc.subtract() << endl;
    cout << double1 << " * " << double2 << " = " << doubleCalc.multiply() << endl;

    return 0;
}
