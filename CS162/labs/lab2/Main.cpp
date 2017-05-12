#include<iostream>
#include<string>
#include"./Date.h"

using namespace std;

int main() {
	
	int choice;

	Date pancakes(3,5,2003);



	string month_name = pancakes.convert(pancakes.get_month());

	choice = pancakes.ask_format();

	if(choice == 1) pancakes.format_one(pancakes.get_month(), pancakes.get_day(), pancakes.get_year());
	else if(choice == 2) pancakes.format_two(month_name, pancakes.get_day(), pancakes.get_year());
	else if(choice == 3) pancakes.format_three(pancakes.get_day(), month_name, pancakes.get_year());
	else cout << "Y U DO DIS?" << endl;


	return 0;
}
