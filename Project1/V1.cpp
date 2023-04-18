#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>


using namespace std;

struct Verbrauch {

	int day = 0;
	int month = 0;
	int year = 0;
	double zaehler = 0.0;
	double preis = 0.0;
};

vector <Verbrauch> Abbrechnung;

/*ofstream out_file("Abbrechnung.txt");
		ostream_iterator*/

int main()
{
	/*Verbrauch added;
	cout << "Bitte geben Sie ein Datum ein: " << endl;
	cin >> added.day;
	cin >> added.month;
	cin >> added.year;

	cout << "Bitte geben Sie den Zaehlerstand an: " << endl;
	cin >> added.zaehler;

	cout << "Bitte geben Sie den aktuellen Preis an: " << endl;
	cin >> added.preis;

	Abbrechnung.push_back(added);

	for (int i = 0; i < Abbrechnung.size(); i++)
	{
		cout << Abbrechnung[i].day << ".";
		cout << Abbrechnung[i].month << ".";
		cout << Abbrechnung[i].year << endl;
		cout << Abbrechnung[i].zaehler << endl;
		cout << Abbrechnung[i].preis << endl;
	}*/

	fstream Liste;
	Liste.open("Abbrechnung.txt", ios::app | ios::out | ios::in);

	if (Liste.is_open())
	{
		Verbrauch added;
		cout << "Bitte geben Sie ein Datum ein: " << endl;
		cin >> added.day;
		cin >> added.month;
		cin >> added.year;

		cout << "Bitte geben Sie den Zaehlerstand an: " << endl;
		cin >> added.zaehler;

		cout << "Bitte geben Sie den aktuellen Preis an: " << endl;
		cin >> added.preis;

		Abbrechnung.push_back(added);

		string str(Abbrechnung.begin(), Abbrechnung.end());
		
		Liste.write(str.c_str(), str.size());
	}

	else
	{
		cout << "unable to open file" << endl;
	}

	


}