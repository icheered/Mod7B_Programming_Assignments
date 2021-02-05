//==============================================================
// Filename: BMI_calc.hpp
// Authors: Soenke Van Loh and Tjeerd Bakker 
// Version: V0.1
// License: GNU GENERAL PUBLIC LICENSE
// Description: Assignment 1
//==============================================================

#pragma once  //makes sure headers are not copied multiple times
#include <iostream>
#include <string>
//header for the class used in order to calculate the BMI of a person

class BMI_calc { // Interface for the BMI calculator
	float m_bmi;
	float m_height;
	float m_weight;
	const std::string m_infotable = "BMI VALUES: \nUnderweight: less than 18.5 \nNormal: between 18.5 and 24.9 \nOverweight: between 25 and 29.9 \nObese: 30 or greater"; //bmi values table
	float calculateBMI();
	void getHeightAndWeight();
public:
	BMI_calc() : m_bmi(0.0f), m_height(0.0f), m_weight(0.0f) {};
	void printInfo();
	void evaluateAndPrintBMI();
	float getHeight();
	float getWeight();
	void  setHeight(float new_height);
	void  setWeight(float new_weight);
};