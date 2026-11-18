#include <iostream>
using namespace std;

class Date {
public:
	int day;
	int month;
	int year;
	void Print()
	{
		cout << "Date: " << day << "/" << month << "/" << year << endl;
	}
};

int main()
{
	const int size = 5;
	const int month[3]{ 31, 31, 28 };

	Date holidayDate{ 25, 10, 2026 };
	holidayDate.Print();

	holidayDate.day = 31;
	holidayDate.Print();

	Date independencyDay{ 24,8,2027 };
	independencyDay.Print();
	independencyDay.day = 25;
	independencyDay.Print();
}