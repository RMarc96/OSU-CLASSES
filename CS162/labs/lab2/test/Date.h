#include<iostream>
#include<string>

using namespace std;

#ifndef DATE_H
#define DATE_H


class Date {
	public:
		Date(); //Default constructor
		
		Date(int, int, int); //Overloaded constructor	
	
		int get_month(); //Accessors
		int get_day();
		int get_year();	

		void set_month(); //Mutators
		void set_day();
		void set_year();

	private:
		int month;
		int day;
		int year;





};

















#endif
