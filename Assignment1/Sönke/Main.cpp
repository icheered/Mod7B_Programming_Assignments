#include <iostream>
#include <string.h>
#include "BMI_calc.h"
#include "Heartrate_calc.h"

void heartrate(); //can be called in main to use the heartrate_calc class
void BMI(); // can be called in main in order to use the BMI_calc class

int main() {
	BMI();
}

void heartrate()
{
	std::cout << "Welcome to your personal heart rate advisor, we will first need some personal data in order to proceed: " << std::endl;
	date birthday = getDateOfBirth();
	//date birthday = { 2000, 7, 20 };
	name Name = getFullName();
	//name Name = { "Soenke", "van Loh" };
	human h = human(birthday, Name);
	h.printHeartRateInfo();
}

void BMI()
{
	BMI_calc c;
	c.printInfo();
	c.evaluateAndPrintBMI();
}
