/***********************************************************
 * Filename: Assignment 2, CS162
 * Author: Ronald Salinas
 * Date: 04/26/2015
 * Description: Simulates a movie rental from Netflix
 * Input: Movie metadata, search keywords
 * Output: Movie metadata
 * *********************************************************/

#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#include "./Movie.h"
#include "./Netflix.h"

using namespace std;


/***************************************************************
 * Function: Prompt Category
 * Description: Prompts user for a search category
 * Parameters: -
 * Pre-conditions: -
 * Post_conditions: A string of a certain category is returned
 * **************************************************************/


string prompt_category() {
	int choice; 
	string keyword;

	while(choice != 1 && choice != 2 && choice != 3 && choice != 4) {
		cout << "Do you want to find movies based on:\n1 - Title\n2 - Star Rating\n3 - An actor\n4 - MPAA Rating\nChoice: ";
		cin >> choice;
	
		if(choice == 1) {
			cout << endl << "Enter a movie title: ";
			cin.clear();
			cin.ignore();
			getline(std::cin, keyword);
		}
		else if(choice == 2) {
			cout << endl << "Enter star rating: ";
			cin.clear();
			cin.ignore();
			getline(std::cin , keyword);

		}
		else if(choice == 3) {
			cout << endl << "Enter the name of an actor: ";
			cin.clear();
			cin.ignore();
			getline(std::cin , keyword);
		}
		else if(choice == 4) {
			cout << endl << "Enter a movie rating: ";
			cin.clear();
			cin.ignore();
			getline(std::cin , keyword);
		}
		else {
			cout << endl << "Invalid choice." << endl;
		}
	

	}
	return keyword;
}

/***************************************************************************
 * Function: Search file for keyword
 * Description: Search file for every instance of the pre-specified keyword
 * Parameters: String keyword
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************/




bool search_keyword(string k) {
	string temp;
	bool hit = false;
	fstream inFile;

	inFile.open("catalog.dat", ios::in);

	if(inFile.fail()) {
		cout << "Could not find the file!" << endl;

	}

	else if(inFile.is_open()){
		int i = 0;
	
		cout << "Movies found:\n" << endl;

		while(inFile.good()) {	
			getline(inFile, temp, '\n');
			size_t find = temp.find(k);
	
			if(find != std::string::npos){
				cout << "Movie " << i+1 << ": " << endl << "\t" << temp << endl;
				i++;
				hit = true;
			}
		}
	
	}

		
		
	if(inFile.eof()) {
		if(hit == true) {
			return true;			//Needs parameters?
		}
		else if(hit == false) {
			cout << "NO MOVIES FOUND." << endl;
			return false;
		}
	}


	inFile.close();
}

/****************************************************************************************
 * Function: "In and out" function
 * Desciption: Inputs file info and outputs a modified set of information to another file
 * Parameters: - 
 * Pre-conditions: Keyword was present from last function call
 * Post-conditions: -
 * *************************************************************************************/


void transfer() {
	string temp, title;
	int copies;	

	ifstream input("catalog.dat");
	ofstream output("catalog_temp.dat");


	cout << "\nEnter the title of the movie you want to rent: ";
	cin >> title;
	

//	cout << "How many copies do you want to rent? ";
//	cin >> copies;


	while(input >> temp) {
		size_t find = temp.find(title);
		if(find != std::string::npos) {
			for(int i = temp.length()-1; i > 0; i--) {
				if(temp[i] == '|') break;
				
				else{
					char new_temp = temp[i];
					temp[i] = (int)new_temp - 1;
				}
				
			}
		}
			
		output << temp;

	}
	output << endl;

	cout << endl << "Movie rented! " << endl;
	
	remove("catalog.dat");
	rename("catalog_temp.dat", "catalog.dat");

}


/******************************************************************
 * Function: Main
 * Description: Prompts user to enter in or search for a movie
 * Parameters: - 
 * Pre-conditions: -
 * Post-conditions: -
 * *****************************************************************/


	
int main() {
	Netflix pizza;
	bool checkpoint = false;
	
	while(true) {
		int choice = 0, num_movs = 0;
	
		cout << "\nDo you want to enter a movie to the database or find a movie to rent? (1 - enter, 2 - find, or 0 - exit): ";
		cin >> choice;
	
		if(choice == 1) {
			pizza.set_num_movies();
			int num_m = pizza.get_num_movies();
			pizza.set_m(num_m);
			pizza.output(pizza.get_m(), num_m);
		}

		else if(choice == 2) {
			string keyword	= prompt_category();
			checkpoint = search_keyword(keyword);
			if(checkpoint == true) transfer();
		}

		else if(choice == 0) return 0;
		
	}



	return 0;
}

