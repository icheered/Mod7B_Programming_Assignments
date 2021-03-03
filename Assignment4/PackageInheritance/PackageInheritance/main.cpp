#include "Package.h"
#include <iostream>
#include <queue>

//takes any type of package an prints its type and the according costs
void PrintCost(Package& p) {
	std::cout << "cost of the " <<p.getType() << " is: " << p.getCost() << "$" << std::endl;
}


int main() {
	Package p("Soenke", "vanLoh", "Tjeerd", "Bakker", "Ad", "Ac", 1, "As", "Bd", "Bc", 2, "Bs", 10);
	TwoDayPackage tdp("Soenke", "vanLoh", "Tjeerd", "Bakker", "Ad", "Ac", 1, "As", "Bd", "Bc", 2, "Bs", 10);
	OvernightPackage onp("Soenke", "vanLoh", "Tjeerd", "Bakker", "Ad", "Ac", 1, "As", "Bd", "Bc", 2, "Bs", 10);
	FragilePackage fp("Soenke", "vanLoh", "Tjeerd", "Bakker", "Ad", "Ac", 1, "As", "Bd", "Bc", 2, "Bs", 10);
	AirdropPackage ap("Soenke", "vanLoh", "Tjeerd", "Bakker", "Ad", "Ac", 1, "As", "Bd", "Bc", 2, "Bs", 10, 1000);
	std::queue<Package> Packagequeue;
	Packagequeue.push(p);
	Packagequeue.push(tdp);
	Packagequeue.push(onp);
	Packagequeue.push(fp);
	Packagequeue.push(ap);
	while (!Packagequeue.empty()) {
		PrintCost(Packagequeue.front());
		Packagequeue.pop();
	}
}