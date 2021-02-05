//==============================================================
// Filename:
// Authors:
// Version:
// License:
// Description:
//==============================================================

#pragma once
#include <iostream>
#include <string>

class Calculator
{
private:
    double m_weight; 
    double m_height; 
    double m_bmi;


public:
    Calculator();

    void getInfo();
    void evaluateAndPrintBMI();
    void printBMICategory(double bmi);
    void printInfo();
};