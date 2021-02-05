#pragma once  //makes sure headers are not copied multiple times
#include <string>
#include <iostream>
#include <ATLComTime.h>

//structure in order to save date values for easier usage when dates have to be passed between objects and or functions
struct date {
	int year = 0;
	int month = 0;
	int day = 0;
};

//structure in order to save name values for easier usage when dates have to be passed between objects and or functions
struct name {
	std::string FirstName = "empty";
	std::string LastName = "empty";
};

//class that manages all dates and calculations for the heartrate of a human
class human {
	//private info from human
	int m_bmonth;
	int m_bday;
	int m_byear;
	int m_max_heartrate;
	int m_age;
	int m_lowertargert, m_uppertarget; //lower and upper heartrate
	std::string m_firstName;
	std::string m_lastName;

	//private functions needed in order to calulcate the heartrate information of a human
	date getCurrentDate(); //gets the current Date from the user (unused, implemented for testing purposes)
	date getCurrentDateAutomated(); //gets the current Date from the system time

public:
	human(date birthday,name Name); //initializes the human with its birthday and name
	void printHeartRateInfo(); //prints the users heart rate information
	int calcage(); //calculates age based on todays date and birthday
	int calcMax(int age); //calculates the maximum heartrate based on the persons age, returns integer
	int calcLower(int max_heartrate); //calculates the lower heartrate based on the maximum heartrate
	int calcUpper(int max_heartrate); //calculates the upper heartrate based on the maximum heartrate
};

name getFullName(); //public function in order to fill a name struct, returns name struct
date getDateOfBirth(); //public function that fills a date struct asking for birthdate information returns date
