#ifndef NETFLIX_H
#define NETFLIX_H
#include"./Movie.h"
#include<iostream>
#include<string>

using namespace std;

class Netflix {
	public:
		Netflix(); 	//Default constructor
		
		//string search_text_file();
		void add_movie(Movie, int);     //Make static?
	
		//void set_movies(Movie*);
	
		Movie* get_movies() {
	//		Movie *movies = m;
			return m;
		}

		~Netflix();	//Destructor
	private:
		Movie *m;
		int num_movies;


};



#endif
