#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include "./Netflix.h"
#include "./Movie.h"

int main() {
	Netflix pizza;
	Movie movie1;


	
	int choice, quantity;

	cout << "Do you want to enter a movie to the database or find a movie to rent? ( 1 - enter, 2 - find, or 0 - exit) : ";
	cin >> choice;


	if(choice == 1) {
		cout << "How many movies do you want to enter? ";
		cin >> quantity;
		pizza.add_movie(movie1, quantity);
		
	}



	cout << "This movie title: " << movie1.get_name() << endl;
	


//	string* members = movie1.get_cast();
	
/*	ofstream output;
	output.open("catalog.dat");
	output << 1 << "|" << movie1.get_name() << "|" << movie1.get_stars() << "|" << movie1.get_num_cast() << "|";
	for(int i = 0; i < movie1.get_num_cast(); i++) {
		output << members[i] << "|";
	}
	output << movie1.get_rating() << "|" << movie1.get_copies() << endl;
		
	output.close();	
*/









	return 0;
}
