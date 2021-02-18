#include "List.h"
#include <string>
#include <iostream>


bool fillList(List<char>&, std::string);

int main()
{
	std::cout << "started" << std::endl;
	//c
	List<char> List1, List2, List3, List4;
	fillList(List1, "singlylinkedList");
	fillList(List2, "abcdefg");
	std::cout << "List1" << std::endl;
	List1.print();
	std::cout << "List2" << std::endl;
	List2.print();
	//e
	fillList(List3, "hijklmnop");
	fillList(List4, "qrstuvw");
	List2.concatenate(List3);
	std::cout << "List3 after conatenation: " << std::endl;
	List3.print();
	List2.concatenate(List4);
	std::cout << "List4 after conatenation: " << std::endl;
	List4.print();
	std::cout << "List2 concetanted Lit3 and List4" << std::endl;
	List2.print();
	std::cout << "finished" << std::endl;
}

//b: I prefered to use a ref to a list as inpt as there is no need for unnecessary copy operations
// The string is not passed by reference in order to give the user the opportunity to create it in function call
bool fillList(List<char> &Lfill, std::string input) { //only char lists as input allowed
	if (!Lfill.isEmpty()) return false; //If the list is not empty it will not be filled, concetanate could be used instead
	for (auto& ref : input) {  //iterate through string and put every char in list at the end
		Lfill.insertAtBack(ref);
	}
	return true;
}
