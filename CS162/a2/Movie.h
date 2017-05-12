#ifndef MOVIE_H
#define MOVIE_H
#include<string>
#include<iostream>


using namespace std;


class Movie {
	public:
		Movie();	//Default Constructor
		~Movie();	//Destructor


		void ask_stuff();

		//Accessors
		string get_name(string) { return name; }
		int get_stars(int) { return stars; }
		int get_num_cast(int) { return num_cast; }
		string *get_cast() { return cast; }
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
