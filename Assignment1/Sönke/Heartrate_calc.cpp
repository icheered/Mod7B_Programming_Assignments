//This file includes the sourcecode for the interface Heartrate_calc


#include "Heartrate_calc.h"



//constructor for class human taking in a date structure containing the birth date of the user and a name struct with the users full name.
human::human(date birthday, name Name) : m_bday(birthday.day), m_bmonth(birthday.month), m_byear(birthday.year), m_firstName(Name.FirstName), m_lastName(Name.LastName)
{
	//initializes member variables
	m_age = calcage();
	m_max_heartrate = calcMax(m_age);
	m_lowertargert = calcLower(m_max_heartrate);
	m_uppertarget = calcUpper(m_max_heartrate);
}

int human::calcage()
{
	date currentDate = getCurrentDateAutomated(); //gets Date from Systemtime info
	int age;
	int yearDiff = currentDate.year - m_byear;
	int monthDiff = currentDate.month - m_bmonth;
	int dayDiff = currentDate.day - m_bday;
	if (monthDiff > -1 && dayDiff > -1) age = yearDiff; //check if person allready had birthday this year
	else age = --yearDiff; //if person did not have birthday this year its age is the year difference minus one
	return age;
}

int human::calcMax(int age)
{
	return 220 - age;
}

int human::calcLower(int max_heartrate)
{
	return floor(0.85 * max_heartrate);
}


int human::calcUpper(int max_heartrate)
{
	return floor(0.5 * max_heartrate);
}

void human::printHeartRateInfo()
{
	std::cout << m_firstName << " " << m_lastName << " your maximum heart rate is " << m_max_heartrate <<
		"bpm. Thereby your target heart rate is inbetween " << m_lowertargert << "bpm and " << m_uppertarget << "bpm." << std::endl;

}

name getFullName()
{
	name n;
	using namespace std;
	string dump;
	getline(cin, dump); //clears the cin and discards everything that might be in it before reading the name
	cout << "Please enter your first and last Name: " << endl;
	cout << "First Name:";
	getline(cin, n.FirstName);
	cout << "Last Name:";
	getline(cin, n.LastName);
	return n;
}

// gets the birthday date by asking the user to manually enter values for date, month and year and returns a date structure
date getDateOfBirth()
{
	date b;
	using namespace std;
	int localDay, localMonth, localYear;
	cout << "Please enter your Birth Date: " << endl;
	cout << "Year:";
	cin >> localYear;
	cout << "Month (in range of 1-12): ";
	cin >> localMonth;
	cout << "Day (in range of 1-31): ";
	cin >> localDay;
	if (localMonth > 0 && localMonth < 13 && localDay > 0 && localDay < 32) { //checks that the entered values are in valid ranges before assigning them
		b.day = localDay;
		b.month = localMonth;
		b.year = localYear;
	}
	else cout << "There is something wrong with the date you entered. Did you use the full year e.g. 2021 and not only 21" << endl;
	return b;
}

// gets the current Date by asking the user to manually enter values for date, month and year and returns a date structure
date human::getCurrentDate()
{
	date d;
	using namespace std;
	int localDay, localMonth, localYear;
	cout << "Please enter todays date: " << endl;
	cout << "Year:";
	cin >> localYear;
	cout << "Month (in range of 1-12): ";
	cin >> localMonth;
	cout << "Day (in range of 1-31): ";
	cin >> localDay;
	if (localMonth > 0 && localMonth < 13 && localDay > 0 && localDay < 32) { //checks that the entered values are in valid ranges before assigning them
		d.year = localYear;
		d.month = localMonth;
		d.day = localDay;
	}
	else cout << "There is something wrong with the date you entered. Did you use the full year e.g. 2021 and not only 21" << endl; //error message if the date is not valid
	return d;
}

// uses the ColeDateTime Class in order to read the system time and then extracts the needed information as a date structure
date human::getCurrentDateAutomated()
{
	date d;
	COleDateTime time;
	time = COleDateTime::GetCurrentTime(); //reads system time
	d.day = time.GetDay();
	d.month = time.GetMonth();
	d.year = time.GetYear();
	return d;
}



