#pragma once  //makes sure headers are not copied multiple times
#include <string>
#include <iostream>
#include <ATLComTime.h>

struct date {
	int year = 0;
	int month = 0;
	int day = 0;
};

struct name {
	std::string FirstName = "empty";
	std::string LastName = "empty";
};

class human {
	int m_bmonth, m_cmonth;
	int m_bday, m_cday;
	int m_byear, m_cyear;
	int m_max_heartrate;
	int m_lowertargert, m_uppertarget;
	std::string m_firstName;
	std::string m_lastName;
	int m_age;
	int calcage(date CurrentDate);
	int calcMax(int age);
	int calcLower(int max_heartrate);
	int calcUpper(int max_heartrate);
	date getCurrentDate();
	date getCurrentDateAutomated();
public:
	human(date birthday,name Name);
	void printHeartRateInfo();
};

name getFullName();
date getDateOfBirth();