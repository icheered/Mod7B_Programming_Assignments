#include <iostream>
#include <string.h>
#include "BMI_calc.h"
#include "Heartrate_calc.h"

int main() {
	BMI_calc c;
	c.printInfo();
	c.evaluateAndPrintBMI();
}

