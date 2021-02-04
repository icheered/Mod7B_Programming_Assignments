#include "BMI_calc.h"

// implementation of the functions used in the BMI calculator

void BMI_calc::printInfo()
{
	std::cout << m_infotable << std::endl;
}

void BMI_calc::evaluateAndPrintBMI()
{
	getHeightAndWeight();
	m_bmi = calculateBMI();
	std::cout << "Your BMI is: " << m_bmi << std::endl;
	if (m_bmi <= 0) std::cout << "error: invalid bmi value" << std::endl;
	else if (m_bmi <= 18.5) std::cout << "You are underweight" << std::endl;
	else if (m_bmi <= 24.9) std::cout << "You are normalweight" << std::endl;
	else if (m_bmi <= 29.9) std::cout << "You are overweight" << std::endl;
	else if (m_bmi >= 30)   std::cout << "You are obese" << std::endl;
}

float BMI_calc::getHeight()
{
	return m_height;
}

float BMI_calc::getWeight()
{
	return m_weight;
}

void BMI_calc::setHeight(float new_height)
{
	m_height = new_height;
}

void BMI_calc::setWeight(float new_weight)
{
	m_weight = new_weight;
}

float BMI_calc::calculateBMI()
{
	if (m_weight > 0 && m_height > 0) return m_weight / (m_height * m_height);
	else return 0.0f;
}

void BMI_calc::getHeightAndWeight()
{
	std::cout << "Please enter your height in m and weight in kg in order to calculate your bmi" << std::endl;
	std::cout << "weight: ";
	std::cin >> m_weight;
	std::cout << "height: ";
	std::cin >> m_height;
}
