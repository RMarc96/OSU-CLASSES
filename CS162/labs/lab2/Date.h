#ifndef DATE_H
#define DATE_H

#include<iostream>
#include<string>

using namespace std;

class Date{
	private:
		int month;
		int day;
		int year;

	public:
		Date();	//Default constructor
		Date(int, int, int); // Non-default Constructor
	
		int get_month() {return month;} //Accessors
		int get_day() {return day;}
		int get_year() {return year;}
		
	
		void set_month(int); //Mutators
		void set_day(int);
		void set_year(int);
		void set_month_name(string);

		string convert(int);

	
		int ask_format();

		
		void format_one(int, int, int);
		void format_two(string, int, int);
		void format_three(int, string, int);

};


#endif
