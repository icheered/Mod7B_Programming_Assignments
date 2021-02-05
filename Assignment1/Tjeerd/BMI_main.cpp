#include <iostream>
#include "src/bmi_calculator.hpp"

int not_main()
{
    Calculator calculator;
    calculator.getInfo();
    calculator.evaluateAndPrintBMI();
    calculator.printInfo();
    return 0;
}