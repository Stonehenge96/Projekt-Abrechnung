#include <iostream>

using namespace std;

struct Date
{
	int day, month, year;
};

const int DaysPerMonth[12]
= { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int CountLeapYears(Date d)
{
	int years = d.year;

	if (d.month <= 2)
	{
		years--;
	}

	return years / 4 - years / 100 + years / 400;
}

int getDifference(Date dt1, Date dt2)
{
	long int n1 = dt1.year * 365 + dt1.day;

	for (int i = 0; i < dt1.month - 1; i++)
		n1 += DaysPerMonth[i];

	n1 += CountLeapYears(dt1);


	long int n2 = dt2.year * 365 + dt2.day;

	for (int i = 0; i < dt2.month - 1; i++)
		n2 += DaysPerMonth[i];

	n2 += CountLeapYears(dt2);

	return (n2 - n1);
}

/*int main()										// Beispiel das der Code funktioniert
{
	Date dt1 = { 28, 2, 2023 };
	Date dt2 = { 13, 3, 2023 };

	cout << "Difference between the dates is "
		<< getDifference(dt1, dt2) << " days";
}*/

istream& operator >> (istream& input, Date& dt)
{
	input >> dt.day >> dt.month >> dt.year;
	return input;
}


int main()
{
	Date dt1;
	Date dt2;

	cout << "Bitte Geben Sie 2 unterschiedliche Daten ein: " << endl;
	cin >> dt1;
	cin >> dt2;

	cout << "Zwischen den Daten liegen " << getDifference(dt1, dt2) << " Tage" << endl;
}