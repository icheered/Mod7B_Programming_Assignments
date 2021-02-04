#include <iostream>
#include "src/bmi_calculator.hpp"

int main()
{
    Calculator calculator;
    calculator.getInfo();
    calculator.evaluateAndPrintBMI();
    calculator.printInfo();
}