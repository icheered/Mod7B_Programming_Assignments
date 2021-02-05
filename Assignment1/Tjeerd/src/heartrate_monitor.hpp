#pragma once
#include <iostream>
#include <string>
#include <ctime>


class Human
{
private:
    bool m_succesfully_set_parameters;

    std::string m_firstname; 
    std::string m_lastname; 
    int m_birthyear;
    int m_birthmonth;
    int m_birthday;

    int m_ageyears;

    int m_maxheartrate;
    double* m_target_heartrate;

public:
    // Constructor
    Human(std::string firstname, std::string lastname, int birthday, int birthmonth, int birthyear);
    
    // Setters
    bool setName(std::string first, std::string last);
    bool setBirthdate(int year, int month, int day);

    // Getters
    std::string getFirstname();
    std::string getFullName();
    bool dataIsValid();

    // Methods that calculate things
    int getAge();
    int calculateMaximumHeartRate();
    double* calculateTargetHeartRates();

    // IO Methods
    void printHumanInfo();
};