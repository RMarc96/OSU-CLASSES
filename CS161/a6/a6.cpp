/****************************************************************************
 * Program Filename: Assignment 6 - Struct of Netflix Data
 * Author: Ronald Salinas
 * Date: 15 March 2015
 * Description: Prompts user to fill in fields of a struct for movie data
 * Input: Movie name, stars, bast number, cast number, cast name(s), rating
 * Output: List of previous input
 * ***************************************************************************/

#include<iostream>
#include<cstring>
#include<string>
#include<stdlib.h>
#include<sstream>

using namespace std;

//Declare struct
struct netflix {
	string name;
	int star;
	string *cast;
	string rating;
};

/*************************************************************
 * Function: Cast number info
 * Description: Checks for a valid cast number
 * Parameters: Address of cast_number
 * Input: Valid or invalid cast number
 * Output: Valid int
 * ***********************************************************/
void num_and_check(int &cast_num) {
	string num;
	while(1) {
		cin.ignore();
		cout << "How many cast members? ";
		cin >> num;
		
		for(int i = 0; i < num.length(); i++) {
			if(num.at(i) != '0' && num.at(i) != '1'&& num.at(i) != '2' && num.at(i) != '3' && num.at(i) != '4' && num.at(i) != '6' && num.at(i) != '7' && num.at(i) != '8' && num.at(i) != '9') {
				cin.clear();
				cout << "Invalid input. " << endl;
				break;

			}
			else{
				istringstream ss(num);
				ss >> cast_num;
				return;
			}
		}	
	}	
}

/**************************************************************************
 * Function: Stars info
 * Description: Checks for a valid star number
 * Parameters: Address of netflix movie.star
 * Input: Valid on invalid integer
 * Output: If invalid, error message
 * ***********************************************************************/

void stars_and_check(int &star) {
	string num;
	while(1) {
		cout << "Enter stars: ";
		cin >> num;
		
		for(int i = 0; i < num.length(); i++) {
			if(num.at(i) != '0' && num.at(i) != '1'&& num.at(i) != '2' && num.at(i) != '3' && num.at(i) != '4' && num.at(i) != '6' && num.at(i) != '7' && num.at(i) != '8' && num.at(i) != '9') {
				cin.clear();
				cout << "Invalid input. " << endl;
				break;

			}
			else{
				istringstream ss(num);
				ss >> star;
				return;
			}
		}	
	}	
}

/*******************************************************************************
 * Function: Get all info
 * Description: Gathers info on a movie
 * Parameters: Contents of netflix movie, address of cast number
 * Input: Movie name, cast name(s), rating
 * Output: -
 * *****************************************************************************/
void get_info(netflix *movie, int &cast_num) {

	cout << "Enter name: ";
	getline(cin, (*movie).name);
	
	stars_and_check((*movie).star);
	
	num_and_check(cast_num);
		
	(*movie).cast = new string[cast_num];
	for(int i = 0; i < cast_num; i++) {
		cin.ignore();
		cout << "Enter cast member " << i+1 << ": ";
		cin >> (*movie).cast[i];
	}

	cout << "Enter rating: ";
	cin >> (*movie).rating;


}

/********************************************************
 * Function: Print info
 * Description: Prints all obtained info in struct
 * Parameters: Contents of netflix movie, cast number
 * Input: - 
 * Output: Struct contents
 * *****************************************************/
void print_info(netflix *movie, int cast_num) {
	
	cout << endl << "Title: " << (*movie).name << endl;
	cout << "Stars: " << (*movie).star << endl;
	cout << "Cast members: ";
	for(int j = 0; j < cast_num; j++)
		cout << (*movie).cast[j] << "    ";
	cout << endl << "Rating: " << (*movie).rating << endl;
	


}
/*********************************************************************************
 * Function: Main
 * Description: Prompts (or reprompts) user whether or not to enter into a struct
 * Parameters: -
 * Input: "Yes" or "No"
 * Output: Prompt message, Invalid input error
 * *******************************************************************************/

int main() {
	struct netflix movie;
	int cast_num;
	string answer;

	while(1) {
	cout << "Do you want to enter a movie into the database? ";
	cin >> answer;
		
	if(answer == "Yes" || answer == "yes" || answer == "YES") {
		cin.ignore();
		get_info(&movie, cast_num);
		print_info(&movie, cast_num);
	}
	else if(answer == "No" || answer == "no" || answer == "NO") exit(0);
	
	else{
		cin.clear();
		cout << "Invalid input. " << endl;
	}
}



	return 0;
}
