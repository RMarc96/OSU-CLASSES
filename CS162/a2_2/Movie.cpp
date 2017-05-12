#include<iostream>
#include<stdlib.h>
#include<string>
#include"./Movie.h"

using namespace std;

/***********************************************************
 * Function: Movie default constructor
 * Descprition: Initializes members for a movie object
 * Parameters: - 
 * Pre-conditions: -
 * Post-conditions: -
 * ********************************************************/


Movie::Movie() {
	name = "--";
	stars = 0;
	num_cast = 0;
	cast = NULL;
	rating = "--";
	copies = 0;
}



/*************************************************************
 * Function: Movie destructor
 * Description: Deletes movie object's cast if out of scope
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * ***********************************************************/

Movie::~Movie() {

	delete [] cast;

}
	

/**************************************************************
 * Function: Movie mutator functions
 * Description: Sets each member in an object
 * Parameters: Number of cast members for cast
 * Pre-conditions: set_num_cast() must run before set_cast()
 * Post-conditions: -
 * ************************************************************/


void Movie::set_name() {
	cout << "Enter movie title: ";
	cin >> name;
}

void Movie::set_stars() {

	cout << "Enter stars: ";
	cin >> stars;
}

void Movie::set_num_cast() {
	cin.clear();
	cin.ignore();

	cout << "Enter number of cast members: ";
	cin >> num_cast;
}

void Movie::set_cast(int num_cast) {
	cast = new string[num_cast];
	
	for(int i = 0; i < num_cast; i++) {
		cout << "Enter cast member " << i+1 << ": ";
		cin >> cast[i];
	}
}

void Movie::set_rating() {
	cout << "Enter movie rating: ";
	cin  >> rating;	
}

void Movie::set_copies() {
	cout << "Enter number of copies: ";
	cin >> copies;
}


