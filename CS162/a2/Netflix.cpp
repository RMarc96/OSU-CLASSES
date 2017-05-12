#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>
#include"./Movie.h"
#include"./Netflix.h"


using namespace std;


Netflix::Netflix() {
	m = NULL;
	num_movies = 0;
}






Netflix::~Netflix() {


}

/*void Netflix::set_movies(Movie* catalog) {
	if(m != NULL) {
		for(int i = 0; i < sizeof(m)/sizeof(Movie); i++)
			delete [] m[i];
	
		delete [] m;
	}
	m = catalog;
}
*/

void Netflix::add_movie(Movie m, int num) {
	cout << "You entered " << num << " movies." << endl;	
	
	m.set_name();
	m.set_stars();
	m.set_num_cast();
	m.set_cast(m.get_num_cast());
	m.set_rating();
	m.set_copies();

}

	


 
	
