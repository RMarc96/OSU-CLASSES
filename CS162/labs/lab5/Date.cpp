#include "./Date.h"
#include<iostream>
#include<string>
using namespace std;

Date::Date() {
	day = 1;
	month = "January";
	year = 2001;
}

void Date::set_day(int d) {
	day = d;
}

void Date::set_month(const string m) {
	month =  m;
}

void Date::set_month(int m) {
	if(m == 1) month = "January";
	else if(m == 2) month = "February";
	else if(m == 3) month = "March";
	else if(m == 4) month = "April";
	else if(m == 5) month = "May";
	else if(m == 6) month = "June";
	else if(m == 7) month = "July";
	else if(m == 8) month = "August";
	else if(m == 9) month = "September";
	else if(m == 10) month = "October";
	else if(m == 11) month = "November";
	else if(m == 12) month = "December";
}

void Date::set_year(int y) {
	year = y;
}

/************************************************/

int Date::get_day() { return day; }
int Date::get_month_int() {
	if(month == "January") return 1;
	if(month == "February") return 2;
	if(month == "March") return 3;
	if(month == "April") return 4;
	if(month == "May") return 5;
	if(month == "June") return 6;
	if(month == "July") return 7;
	if(month == "August") return 8;
	if(month == "September") return 9;
	if(month == "October") return 10;
	if(month == "November") return 11;
	if(month == "December") return 12;
}
string Date::get_month_string() { return month; }
int Date::get_year() { return year; }

/**************************************************/

int Date::get_2digit_year() {
	return year%100;

}

void Date::print_shrt_date() {
	cout << endl << get_month_int() << " / " << get_day() << " / " << get_year() << endl;;


}


/*int Date::get_day_of_week() {
	int year = get_year();

	int leap_year = year%4;

	int month_value = get_month_int();
	int month_sub;

	if(leap_year != 0) {
		if(month_value == 1 || month_value == 10) month_sub = 0;
		else if(month_value == 5) month_sub = 1;
		else if(month_value == 8) month_sub = 2;
		else if(month_value == 2 || month_value == 3 || month_value == 11) month_sub = 3;
		else if(month_value == 6) month_sub = 4;
		else if(month_value == 9 || month_value == 12) month_sub = 5;
		else if(month_value == 4 || month_value == 7) month_sub = 6;
	}
	else if(leap_year == 0) {
		if(month_value == 10) month_sub = 0;
		else if(month_value == 5) month_sub = 1;
		else if(month_value == 2 || month_value == 8) month_sub = 2;
		else if(month_value == 3 || month_value == 11) month_sub = 3;
		else if(month_value == 6) month_sub = 4;
		else if(month_value == 9 || month_value == 12) month_sub = 5;
		else if(month_value == 1 || month_value == 4 || month_value == 7) month_sub = 6;
	}
	
	if(year >= 2000)
		return ( get_day() + month_sub + get_2digit_year() + get_2digit_year()/4 + 6) % 7;
	else if(year < 2000) 
		return ( get_day() + month_sub + get_2digit_year() + get_2digit_year()/4) % 7;



}*/
