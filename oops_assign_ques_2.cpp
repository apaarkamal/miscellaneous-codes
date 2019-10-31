// Author : Apaar
// Built  : 20-10-2019 21:32:44

#include <bits/stdc++.h>

using namespace std;

class Package
{
private:
	string sender_name;
	string sender_address;
	string sender_city;
	string sender_state;
	string sender_ZIP;

	string recipient_name;
	string recipient_address;
	string recipient_city;
	string recipient_state;
	string recipient_ZIP;

	double weight;
	double costperounce;
public:


	Package(string sender_n, string sender_addr, string sender_c,
	        string sender_s, string sender_Z, string recipient_n, string recipient_addr,
	        string recipient_c, string recipient_s, string recipient_Z, double wei,
	        double cost);

	void setsender_name(string sender_n);
	string getsender_name();

	void setsender_address(string sender_addr);
	string getsender_address();

	void setsender_city(string sender_c);
	string getSendCity();

	void setsender_state(string sender_s);
	string getsender_state();

	void setsender_ZIP(string sender_Z);
	string getsender_ZIP();

	void setrecipient_name(string recipient_n);
	string getrecipient_name();

	void setrecipient_address(string recipient_addr);
	string getrecipient_address();

	void setrecipient_city(string recipient_c);
	string getrecipient_city();

	void setrecipient_state(string recipient_s);
	string getrecipient_state();

	void setrecipient_ZIP(string recipient_Z);
	string getrecipient_ZIP();

	void setweight(double w);
	double getweight();

	void setcostperounce(double cost);
	double getcostperounce();

	double calculateCost();
};

Package::Package(string sender_n, string sender_addr, string sender_c, string
                 sender_s, string sender_Z, string recipient_n, string recipient_addr, string
                 recipient_c, string recipient_s, string recipient_Z, double wei, double cost)
{
	sender_name = sender_n;
	sender_address = sender_addr;
	sender_city = sender_c;
	sender_state = sender_s;
	sender_ZIP = sender_Z;

	recipient_name = recipient_n;
	recipient_address = recipient_addr;
	recipient_city = recipient_c;
	recipient_state = recipient_s;
	recipient_ZIP = recipient_Z;

	if (wei > 0.0 && cost > 0.0)
	{
		weight = wei;
		costperounce = cost;
	}
	else
	{
		weight = 0.0;
		costperounce = 0.0;
	}

}

void Package::setsender_name(string sender_n)
{
	sender_name = sender_n;
}
string Package::getsender_name()
{
	return sender_name;
}

void Package::setsender_address(string sender_addr)
{
	sender_address = sender_addr;
}
string Package::getsender_address()
{
	return sender_address;
}

void Package::setsender_city(string sender_c)
{
	sender_city = sender_c;
}

string Package::getSendCity()
{
	return sender_city;
}

void Package::setsender_state(string sender_s)
{
	sender_state = sender_s;
}
string Package::getsender_state()
{
	return sender_state;
}

void Package::setsender_ZIP(string sender_Z)
{
	sender_ZIP = sender_Z;
}
string Package::getsender_ZIP()
{
	return sender_ZIP;
}

void Package::setrecipient_name(string recipient_n)
{
	recipient_name = recipient_n;
}
string Package::getrecipient_name()
{
	return recipient_name;
}

void Package::setrecipient_address(string recipient_addr)
{
	recipient_address = recipient_addr;
}
string Package::getrecipient_address()
{
	return recipient_address;
}

void Package::setrecipient_city(string recipient_c)
{
	recipient_city = recipient_c;
}
string Package::getrecipient_city()
{
	return recipient_city;
}

void Package::setrecipient_state(string recipient_s)
{
	recipient_state = recipient_s;
}
string Package::getrecipient_state()
{
	return recipient_state;
}

void Package::setrecipient_ZIP(string recipient_Z)
{
	recipient_ZIP = recipient_Z;
}
string Package::getrecipient_ZIP()
{
	return recipient_ZIP;
}

void Package::setweight(double w)
{
	weight = (w < 0.0 ) ? 0.0 : w;
}
double Package::getweight()
{
	return weight;
}

void Package::setcostperounce(double cost)
{
	costperounce = ( cost < 0.0) ? 0.0 : cost;
}

double Package::getcostperounce()
{
	return costperounce;
}

double Package::calculateCost()
{
	double result;

	result = weight * costperounce;

	return result;
}


class TwoDayPackage : public Package
{
private:
	double two_day_delivery_fee;
public:
	TwoDayPackage(string sender_n, string sender_addr, string
	              sender_c, string sender_s, string sender_Z, string recipient_n,
	              string recipient_addr, string recipient_c, string recipient_s,
	              string recipient_Z, double wei, double cost, double delivery_fee);

	double gettwo_day_delivery_fee();
	void settwo_day_delivery_fee(double delivery_fee);
	double calculateCost();
};

TwoDayPackage::TwoDayPackage(string sender_n, string sender_addr,
                             string sender_c, string sender_s, string sender_Z, string recipient_n,
                             string recipient_addr, string recipient_c, string recipient_s,
                             string recipient_Z, double wei, double cost, double delivery_fee)
	: Package(sender_n, sender_addr, sender_c, sender_s, sender_Z, recipient_n,
	          recipient_addr, recipient_c, recipient_s, recipient_Z, wei, cost)
{
	settwo_day_delivery_fee(delivery_fee);

}


double TwoDayPackage::gettwo_day_delivery_fee()
{
	return two_day_delivery_fee;
}
void TwoDayPackage::settwo_day_delivery_fee(double delivery_fee)
{
	two_day_delivery_fee = delivery_fee;
}

double TwoDayPackage::calculateCost()
{
	double result;
	result = Package::calculateCost() + two_day_delivery_fee;
	return result;
}

class OvernightPackage : public Package
{
private:
	double overnight_delivery_fee;
public:

	OvernightPackage(string sender_n, string sender_addr, string sender_c,
	                 string sender_s, string sender_Z, string recipient_n, string recipient_addr,
	                 string recipient_c, string recipient_s, string recipient_Z, double wei,
	                 double cost, double delivery_fee);

	double calculateCost();
	double getovernight_delivery_fee();
	void setovernight_delivery_fee(double delivery_fee);

};

OvernightPackage::OvernightPackage(string sender_n, string sender_addr,
                                   string sender_c, string sender_s, string sender_Z, string recipient_n,
                                   string recipient_addr, string recipient_c, string recipient_s,
                                   string recipient_Z, double wei, double cost, double delivery_fee)
	: Package(sender_n, sender_addr, sender_c, sender_s, sender_Z, recipient_n,
	          recipient_addr, recipient_c, recipient_s, recipient_Z, wei, cost)
{
	setovernight_delivery_fee(delivery_fee);
}

double OvernightPackage::getovernight_delivery_fee()
{
	return overnight_delivery_fee;
}
void OvernightPackage::setovernight_delivery_fee(double delivery_fee)
{
	overnight_delivery_fee = delivery_fee;
}

double OvernightPackage::calculateCost()
{
	double result;
	result =  (getcostperounce() + overnight_delivery_fee) * getweight();
	return result;
}

int main(int argc, char *argv[])
{
	OvernightPackage item1("Tom Brown", "123 Main Street", "Phoenix",
	                       "Arizona", "89754", "John", "123 bent street", "Hartford", "Connecticut",
	                       "87540", 12.00, 1.50, 1.10);
	TwoDayPackage item2("Monique Smith", "987 1st Street", "Sacramento",
	                    "California", "87654", "Paul", "833 palm Street", "Miami", "Florida",
	                    "98763", 18.00, 1.05, 8.00);

	cout << fixed << setprecision(2);
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout << "Overnight Delivery\n";
	cout << "Sender        " << item1.getsender_name() << "\n";
	cout << "              " << item1.getsender_address() << "\n";
	cout << "              " << item1.getSendCity() << " " <<
	     item1.getsender_state() << " " << item1.getsender_ZIP() << "\n";
	cout << "\n";
	cout << "Recipient     " << item1.getrecipient_name() << "\n";
	cout << "              " << item1.getsender_address() << "\n";
	cout << "              " << item1.getrecipient_city() << " " <<
	     item1.getrecipient_state() << " " << item1.getrecipient_ZIP() << "\n";
	cout << "Cost          $ " << item1.calculateCost() << "\n";
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

	cout << "\n\n";
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout << "2 Day Delivery\n";
	cout << "Sender        " << item2.getsender_name() << "\n";
	cout << "              " << item2.getsender_address() << "\n";
	cout << "              " << item2.getSendCity() << " " <<
	     item2.getsender_state() << " " << item2.getsender_ZIP() << "\n";
	cout << "\n";
	cout << "Recipient     " << item2.getrecipient_name() << "\n";
	cout << "              " << item2.getsender_address() << "\n";
	cout << "              " << item2.getrecipient_city() << " " <<
	     item2.getrecipient_state() << " " << item2.getrecipient_ZIP() << "\n";
	cout << "Cost          $ " << item2.calculateCost() << "\n";
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

	return 0;
}