#include<iostream>
#include<string>
#include "./Date.h"

using namespace std;

int main(){
	int month, day, year;


	cout << "Enter month: ";
	cin >> month;
	
	cout << "Enter day: ";
	cin >> day;
	
	cout << "Enter year: ";
	cin >> year;

	Date pancakes(month, day, year);

	cout << endl << "Month: " << pancakes.get_month() << endl;
	cout << "Day: " << pancakes.get_day() << endl;
	cout << "Year: " << pancakes.get_year() << endl;
	
	


	return 0;
}
