#include "./Netflix.h"
#include<iostream>
#include<cstring>
#include<string>
#include<stdlib.h>
#include<fstream>


/****************************************************
 * Function: Default constructor
 * Description: Initializes member variables
 * Parameters: - 
 * Pre-conditions: -
 * Post-conditions: -
 * ************************************************/

Netflix::Netflix() {
	m = NULL;
	num_movies = 0;
}

/*****************************************************
 * Function: Destructor
 * Description: Deletes dynamic array if out of scope
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * ****************************************************/


Netflix::~Netflix() {
	delete [] m;
}


/************************************************************************************
 * Functions: Mutators
 * Description: Sets values for dyanmic array of movies and movie objects within it
 * Parameters: Number of movies for cast
 * Pre-conditions: Number of movies needing to be entered must be specified
 * Post-conditions: -
 * ***********************************************************************************/


void Netflix::set_num_movies() {
	int num;
	cout << "How many movies do you want to enter in? ";
	cin >> num;

	num_movies = num;
}



void Netflix::set_m(int num_movs) {
	m = new Movie[num_movs];

	
	for(int i = 0; i < num_movs; i++) {
		cout << endl << "~~MOVIE " << i+1 << " INFO~~ " << endl;
		m[i].set_name();
		m[i].set_stars();
		m[i].set_num_cast();
		m[i].set_cast(m[i].get_num_cast());
		m[i].set_rating();
		m[i].set_copies();
	
		cout << "Movie added!" << endl << endl;		
	}

}


/***********************************************************
 * Function: Output
 * Description: Stores movie information to .dat file
 * Parameters: Movie object array and number of movies
 * Pre-conditions: -
 * Post-conditions: -
 * ********************************************************/



void Netflix::output(Movie* m, int num_movs) {
	ofstream output;

	output.open("catalog.dat", ios::app);

	cout << "Num_movs: " << num_movs  <<endl;

	for(int i = 0; i < num_movs; i++) {
//		output << i+1 << "|";
		output << m[i].get_name() << "|";
		output << m[i].get_stars() << "|";
		output << m[i].get_num_cast() << "|";
		
		for(int j = 0; j < m[i].get_num_cast(); j++) {
			output << m[i].get_cast(j) << "|";
		}
		output << m[i].get_rating() << "|";
		output << m[i].get_copies() << endl; 
	
	}
	output.close();

}

