
#include "bmi_calculator.hpp"

Calculator::Calculator()
{
    m_weight = 0;
    m_height = 0;
    m_bmi = 0;
}

void Calculator::getInfo()
{
    std::cout << "Enter your height [m]:  ";
    std::cin >> m_height;
    std::cout << "Enter your weight [kg]: ";
    std::cin >> m_weight;
}

void Calculator::evaluateAndPrintBMI()
{
    if(m_weight <= 0)
    {
        std::cout << "Impossible weight" << std::endl;
        return;
    }
    if(m_height <= 0)
    {
        std::cout << "Impossible weight" << std::endl;
        return;
    }

    m_bmi = m_weight / (m_height * m_height);
    printBMICategory(m_bmi);
}

void Calculator::printBMICategory(double bmi)
{
    if(bmi < 18.5) { std::cout << "You are underweight" << std::endl; return;}
    if(bmi < 24.9) { std::cout << "Your weight is normal" << std::endl; return;}
    if(bmi < 29.9) { std::cout << "You are underweight" << std::endl; return;}
    if(bmi > 29.9) { std::cout << "You are underweight" << std::endl; return;}
}

void Calculator::printInfo()
{
    std::string info = "\n"
        "BMI VALUES:\n"
        "Underweight: less than 18.5\n"
        "Normal: between 18.5 and 24.9\n"
        "Overweight: between 25 and 29.9\n"
        "Obese: 30 or greater\n";
    
    std::cout << info << std::endl;
}