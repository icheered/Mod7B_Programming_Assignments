#include "heartrate_monitor.hpp"

// Constructor. Get all the information and call its own setters.
//              Returns if all the information could be set succesfully
Human::Human(std::string firstname, std::string lastname, int birthday, int birthmonth, int birthyear)
{
    bool success_name = setName(firstname, lastname);
    bool success_birthdate = setBirthdate(birthday, birthmonth, birthyear);
    bool success = (success_name && success_birthdate);
    m_succesfully_set_parameters = success;
};
    
// Setters
bool Human::setName(std::string first, std::string last)
{
    m_firstname = first;
    m_lastname = last;
    return true;
};

bool Human::setBirthdate(int day, int month, int year)
{
    if((day > 0 && day < 32)) { m_birthday = day;}
    else{ return false; }

    if((month > 0 && month < 13)) { m_birthmonth = month;}
    else{ return false; }

    m_birthyear = year;
    return true;
};

// Getters
std::string Human::getFirstname(){ return m_firstname; }
std::string Human::getFullName() { return (m_firstname+m_lastname); }
bool Human::dataIsValid() {return m_succesfully_set_parameters; }


// Methods that calculate things
int Human::getAge()
{
    // Using ctime to get local date and time
    std::time_t now = std::time(0);
    std::tm *ltm = std::localtime(&now);

    // Year since 1900 so adding 1900 to get current year
    // ltm is a C structure, use arrow operator to access structure members
    int current_year = 1900 + ltm->tm_year;
    
    int current_month = ltm->tm_mon;
    int current_day = ltm->tm_mday;

    int age_years = current_year - m_birthyear;
    if(current_month < m_birthmonth)
    {
        age_years -= 1;
    }
    else if((current_month == m_birthmonth) && (current_day < m_birthday))
    {
        age_years -= 1;
    }
    m_ageyears = age_years;
    return age_years;
};


int Human::calculateMaximumHeartRate()
{
    int age = getAge();
    int maxheartrate = 220 - age;
    m_maxheartrate = maxheartrate;
    return maxheartrate;
};

// Returns a pointer to an array storing the min and max value
double* Human::calculateTargetHeartRates()
{
    double high = (double)(m_maxheartrate * 0.5);
    double low = (double)(m_maxheartrate) * 0.85;
    double arr[2] = { high, low };
    double *parr = arr;
    m_target_heartrate = parr;
    return parr;
};



// Methods that return things
void Human::printHumanInfo()
{
    int age = getAge();
    int maxHeartrate = calculateMaximumHeartRate();
    double* TargetHeartrate = calculateTargetHeartRates();
    float low = *TargetHeartrate;
    float high = *(TargetHeartrate + 1);

    std::cout << "Your name: " << m_firstname << " " << m_lastname << std::endl;
    std::cout << "Your birthdate: " << std::to_string(m_birthday) << "-" << std::to_string(m_birthmonth) << "-" << std::to_string(m_birthyear) << std::endl;
    std::cout << "Your age: " << age << std::endl;
    std::cout << "Your Maximum Heartrate: " << maxHeartrate << std::endl;
    std::cout << "Your Target Heartrate: " << std::to_string(low) << " - " << std::to_string(high) << " BPM " <<std::endl;
}