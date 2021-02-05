//==============================================================
// Filename: main.cpp
// Authors: Soenke Van Loh and Tjeerd Bakker 
// Version: V0.1
// License: GNU GENERAL PUBLIC LICENSE
// Description: Assignment 1
//==============================================================

#include <iostream>
#include <string.h>
#include "BMI_calc.h"
#include "Heartrate_calc.h"

void heartrate(); //can be called in main to use the heartrate_calc class
void BMI(); // can be called in main in order to use the BMI_calc class

int main() {
	BMI();
	heartrate();
	std::cin.get(); //waits for user input before closing the console
}

// Execute the heartrate assignment
void heartrate()
{
	std::cout << "Welcome to your personal heart rate advisor, we will first need some personal data in order to proceed: " << std::endl;
	date birthday = getDateOfBirth();
	name Name = getFullName();
	human h = human(birthday, Name);
	h.printHeartRateInfo();
}

// Execute the BMI calculator assignment
void BMI()
{
	std::cout << "Welcome to your personal BMI calculator. First a table of the used BMI values is showen and after that you can calculate yoour own BMI value." << std::endl;
	BMI_calc c;
	c.printInfo();
	c.evaluateAndPrintBMI();
}
