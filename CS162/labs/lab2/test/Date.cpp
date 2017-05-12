#include "./Date.h"

Date::Date() {
	month = 1;
	day = 1;
	year = 2001;
}

Date::Date(int m, int d, int y) {
	month = m;
	day = d;
	year = y;

}



int Date::get_month() {
	return month;
}

int Date::get_day() {
	return day;
}

int Date::get_year() {
	return year;
}

