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
//		Movie *add_movie(int);     //Make static?


		~Netflix();	//Destructor
	private:
		Movie *m;
		int num_movies;


};



#endif
