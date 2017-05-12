#ifndef MOVIE_H
#define MOVIE_H
#include<string>
#include<iostream>


using namespace std;


class Movie {
	public:
		Movie();	//Default Constructor
		Movie(int); 	//Non-default constructor
		~Movie();	//Destructor


		Movie(const Movie& mov);	//Copy constructor
		
		Movie& operator=(const Movie &mov); //Operator overload



		//Accessors
		string get_name() { return name; }
		int get_stars() { return stars; }
		int get_num_cast() { return num_cast; }
		string get_cast(int c) { 
			return cast[c];
		}
		string get_rating() { return rating; }
		int get_copies() { return copies; }
		
		//Mutators		
		void set_name();
		void set_stars();
		void set_num_cast();
		void set_cast(int);
		void set_rating();
		void set_copies();

	private:
		string name;
		int stars;
		int num_cast;
		string *cast;
		string rating;
		int copies;
};

#endif
