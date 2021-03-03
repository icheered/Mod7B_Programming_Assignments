#pragma once //ensures no multiple includes
#include <string>

//base class for all packages,
//costs 50ct per kg
class Package {
private:
	std::string m_type;
protected:
	std::string m_send_firstName, m_send_lastName, m_rec_firstName, m_rec_lastName;
	int m_rec_zip, m_send_zip;
	std::string m_send_address, m_rec_address, m_send_city, m_rec_city, m_send_state, m_rec_state;
	double m_weight, m_cost;
public:
	Package(std::string send_firstName, std::string send_lastName, std::string rec_firstName, std::string rec_lastName, std::string
		    send_address, std::string send_city, int send_zip, std::string send_state, std::string rec_address, std::string rec_city,
			int rec_zip, std::string rec_state, double weight);		
	virtual double calculateCosts();
	double getCost();
	std::string getType();
	void setType(std::string type);
};

//package with two day delivery,
//costs 5$ + weight*2.5$
class TwoDayPackage : public Package {
public:
	TwoDayPackage(std::string send_firstName, std::string send_lastName, std::string rec_firstName, std::string rec_lastName, std::string
		send_address, std::string send_city, int send_zip, std::string send_state, std::string rec_address, std::string rec_city,
		int rec_zip, std::string rec_state, double weight);
	double calculateCosts() override;
};

//package with overnight delivery,
//costs as much as twoDayDelivery with additional 1.1$/kg^2
class OvernightPackage : public TwoDayPackage {
public:
	OvernightPackage(std::string send_firstName, std::string send_lastName, std::string rec_firstName, std::string rec_lastName, std::string
		send_address, std::string send_city, int send_zip, std::string send_state, std::string rec_address, std::string rec_city,
		int rec_zip, std::string rec_state, double weight);
	double calculateCosts() override;
};

//package with fragile care delivery,
//costs as much as normale package plus 10$
class FragilePackage : public Package {
public:
	FragilePackage(std::string send_firstName, std::string send_lastName, std::string rec_firstName, std::string rec_lastName, std::string
		send_address, std::string send_city, int send_zip, std::string send_state, std::string rec_address, std::string rec_city,
		int rec_zip, std::string rec_state, double weight);
	double calculateCosts() override;
};

//airdrop,
//costs as much as overnight delivery plus weight*distance(in km)/100 in $
//it has an extra variable distance which the other packages dont have, therby its constructor is a bit different
class AirdropPackage : public OvernightPackage {
private:
	int m_distance;
public:
	AirdropPackage(std::string send_firstName, std::string send_lastName, std::string rec_firstName, std::string rec_lastName, std::string
		send_address, std::string send_city, int send_zip, std::string send_state, std::string rec_address, std::string rec_city,
		int rec_zip, std::string rec_state, double weight, int distance);
	double calculateCosts() override;
};

