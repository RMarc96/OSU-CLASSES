#ifndef DATE_H
#define DATE_H

class Date{
	public:
		Date();
		void set_day(int);
		void set_month(int);
		void set_month(const_string);
		void set_year(int);
		
		string get_month_string();
		int get_year();
		
		void print_shrt_date();
		void print_long_date();
		int get_2digit_year();
		int get_day_of_week();

	private:
		int day;
		string month;
		int year();


};


#endif
