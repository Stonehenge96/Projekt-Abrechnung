#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

struct Date {								//vielleicht überflüssig? bzw Sinn ist das Datum als eigenes Struct 
											//fest zusammen zu haben, allerdings probleme bei dem Schreiben in 
	int day, month, year;					//die Textfile mit wahrscheinlich der memory allocation.
};

struct Verbrauch {

	int day, month, year;
	double zaehlerstand;
	double preis;
};

vector <Verbrauch> Abrechnung;

/*ostream& operator << (ostream& output, const Date& d)
{
	output << d.day << ' ' << d.month << ' ' << d.year;
	return output;
}*/

ostream& operator << (ostream& output, Verbrauch& v)
{
	output << v.day << ' ' << v.month << ' ' << v.year << ' ' << v.zaehlerstand << ' ' << v.preis;
	return output;
}

/*istream& operator >> (istream& input, Verbrauch& v)
{
	input << v.day << ' ' << v.month << ' ' << v.year << ' ' << v.zaehlerstand << ' ' << v.preis;
	return input;
}*/

string Umwandlung( vector <Verbrauch>& Abrechnung)
{
	stringstream ss;
	
	for (unsigned i = 0; i < Abrechnung.size(); i++)
	{
		ss << Abrechnung[i];
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

		Abrechnung.push_back(added);
		
		string str = Umwandlung(Abrechnung);

		Liste.write(str.c_str(), str.size());
	}
	
	else
	{
		cout << "unable to open file" << endl;
	}	
	Liste.close();

	for (unsigned i = 0; i < Abrechnung.size(); i++)
	{
		//cout << Abrechnung[i] << endl;
	}

	Abrechnung.clear();

	Liste.open("Test.txt", ios::app | ios::out | ios::in);

	if (Liste.is_open())
	{
		istringstream ss;
		ss >> Liste.rdbuf();
		string str = ss.str();

		cout << str << endl;
	}
} 