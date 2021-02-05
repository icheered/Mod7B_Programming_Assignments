//==============================================================
// Filename:
// Authors:
// Version:
// License:
// Description:
//==============================================================



#include <iostream>
#include <string>
#include "src/heartrate_monitor.hpp"

int also_not_main()
{
    std::string firstname;
    std::string lastname;
    int birthyear;
    int birthmonth;
    int birthday;

    while(true)
    {

        
        std::cout << "Enter your first name: ";
        std::getline(std::cin, firstname);
        std::cout << "Enter your last name: ";
        std::getline(std::cin, lastname);

        std::cout << "Enter your year of birth: ";
        std::cin >> birthyear;
        std::cout << "Enter your month of birth: ";
        std::cin >> birthmonth;
        std::cout << "Enter your day of birth: ";
        std::cin >> birthday;

        Human human(firstname, lastname, birthday, birthmonth, birthyear);
        // Check if the data is valid. If it is not, get new input.
        if(!human.dataIsValid())
        {
            std::cout << "Entered data was not valid. Try again " << std::endl;
            continue;
        }

        human.printHumanInfo();
    }
    return 0;
}