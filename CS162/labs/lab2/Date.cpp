#include "./Date.h"


Date::Date() {
	month = 1;
	day = 1;
	year = 2001;
}


Date::Date(int m, int d, int y) {
	if(m < 1 || m > 12) month = 1;
	else month = m;
	
	if(m == 2 && d > 28 || d < 1) day = 1;
	else if((m == 4 || m == 6 || m == 9 || m == 11) && d > 30 || d < 1) day = 1;
	else if((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 31 || d < 1) day = 1;
	else day = d;

	year = y;

}

void Date::set_month(int m) {
	month = m;
}

void Date::set_day(int d) {
	day = d;
}

void Date::set_year(int y) {
	year = y;
}



string Date::convert(int m) {
	if(m == 1) return "January";
	else if(m == 2) return "February";
	else if(m == 3) return "March";
	else if(m == 4) return "April";
	else if(m == 5) return "May";
	else if(m == 6) return "June";
	else if(m == 7) return "July";
	else if(m == 8) return "August";
	else if(m == 9) return "September";
	else if(m == 10) return "October";
	else if(m == 11) return "November";
	else if (m == 12) return "December";
	else return "N/A";
}	

int Date::ask_format() {
	int choice;
	
	cout << "Choose a date format to print: " << endl << "1 - MM/DD/YYY\t 2 - MMMM DD, YYYYY\t 3 - DD MMMM, YYYY ";
	cout << endl << "Enter format: ";
	cin >> choice;

	return choice;

}




void Date::format_one(int m, int d, int y) {
	cout << m << " / " << d << " / " << y << endl;
}

void Date::format_two(string m, int d, int y) {
	cout << m << " " << d << ", " << y << endl;
}

void Date::format_three(int d, string m, int y) {
	cout << d << " " << m << " " << y << endl;
}

