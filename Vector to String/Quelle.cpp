#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

struct Date {

	int day, month, year;
};

struct Verbrauch {

	Date day, month, year;
	double zaehlerstand;
	double preis;
};

vector <Verbrauch> Abbrechnung;

ostream& operator << (ostream& output, const Date& d)
{
	output << d.day << ' ' << d.month << ' ' << d.year;
	return output;
}

ostream& operator << (ostream& output, Verbrauch& v)
{
	output << v.day << ' ' << v.month << ' ' << v.year << ' ' << v.zaehlerstand << ' ' << v.preis;
	return output;
}

string Umwandlung( vector <Verbrauch>& Abbrechnung)
{
	stringstream ss;
	for (int i = 0; i < Abbrechnung.size(); i++)
	{
		ss << Abbrechnung[i];
	}

	return ss.str();
}


int main()
{ 
	fstream Liste;
	Liste.open("Test.txt", ios::app | ios::out | ios::in);

	if (Liste.is_open())
	{
		Verbrauch added = { 14, 3, 2023, 100, 50 };

		Abbrechnung.push_back(added);

		string str = Umwandlung(Abbrechnung);

		cout << str << endl;
		Liste.write(str.c_str(), str.size());
	}
	
	else
	{
		cout << "unable to open file" << endl;
	}	
}