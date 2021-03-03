#include "Package.h"

//m_cost hast to be called individually in every constructor as otherwise not the correct virtual func is used

//Package
Package::Package(std::string send_firstName, std::string send_lastName, std::string rec_firstName, std::string rec_lastName, std::string send_address, std::string send_city, int send_zip, std::string send_state, std::string rec_address, std::string rec_city, int rec_zip, std::string rec_state, double weight) :
	m_send_firstName(send_firstName), m_send_lastName(send_lastName), m_rec_firstName(rec_firstName), m_rec_lastName(rec_lastName),
	m_rec_zip(rec_zip), m_send_zip(send_zip), m_send_address(send_address), m_rec_address(rec_address), m_send_city(send_city),
	m_rec_city(rec_city), m_send_state(send_state), m_rec_state(rec_state), m_weight(weight)
{
	m_cost = calculateCosts();
	setType("Package");
}

double Package::calculateCosts()
{
	return m_weight * 0.5; 
}

double Package::getCost()
{
	return m_cost;
}

std::string Package::getType()
{
	return m_type;
}

void Package::setType(std::string type)
{
	m_type = type;
}

//TwoDayPackage
TwoDayPackage::TwoDayPackage(std::string send_firstName, std::string send_lastName, std::string rec_firstName, std::string rec_lastName, std::string send_address, std::string send_city, int send_zip, std::string send_state, std::string rec_address, std::string rec_city, int rec_zip, std::string rec_state, double weight)
	: Package(send_firstName, send_lastName, rec_firstName, rec_lastName, send_address, send_city, send_zip, send_state, rec_address, rec_city, 
		rec_zip, rec_state, weight)
{
	setType("TwoDayPackage");
	m_cost = calculateCosts();
}

double TwoDayPackage::calculateCosts()
{
	return m_weight*2.5 + 5;
}

//OvernightPackage
OvernightPackage::OvernightPackage(std::string send_firstName, std::string send_lastName, std::string rec_firstName, std::string rec_lastName, std::string send_address, std::string send_city, int send_zip, std::string send_state, std::string rec_address, std::string rec_city, int rec_zip, std::string rec_state, double weight)
	: TwoDayPackage(send_firstName, send_lastName, rec_firstName, rec_lastName, send_address, send_city, send_zip, send_state, rec_address, rec_city,
		rec_zip, rec_state, weight)
{
	setType("OvernightPackage");
	m_cost = calculateCosts();
}

double OvernightPackage::calculateCosts()
{
	return TwoDayPackage::calculateCosts() + 1.1*m_weight*m_weight;
}

//FragilePackage
FragilePackage::FragilePackage(std::string send_firstName, std::string send_lastName, std::string rec_firstName, std::string rec_lastName, std::string send_address, std::string send_city, int send_zip, std::string send_state, std::string rec_address, std::string rec_city, int rec_zip, std::string rec_state, double weight)
	: Package(send_firstName, send_lastName, rec_firstName, rec_lastName, send_address, send_city, send_zip, send_state, rec_address, rec_city,
		rec_zip, rec_state, weight)
{
	setType("FragilePackage");
	m_cost = calculateCosts();
}

double FragilePackage::calculateCosts()
{
	return Package::calculateCosts() + 10;
}

//Airdrop
AirdropPackage::AirdropPackage(std::string send_firstName, std::string send_lastName, std::string rec_firstName, std::string rec_lastName, std::string send_address, std::string send_city, int send_zip, std::string send_state, std::string rec_address, std::string rec_city, int rec_zip, std::string rec_state, double weight, int distance)
	: OvernightPackage(send_firstName, send_lastName, rec_firstName, rec_lastName, send_address, send_city, send_zip, send_state, rec_address, rec_city,
		rec_zip, rec_state, weight) , m_distance(distance)
{
	setType("Airdrop");
	m_cost = calculateCosts();
}

double AirdropPackage::calculateCosts()
{
	return OvernightPackage::calculateCosts() + m_distance*m_weight/100;
}
