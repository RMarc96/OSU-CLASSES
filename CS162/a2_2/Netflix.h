#ifndef NETFLIX_H
#define NETFLIX_H
#include"./Movie.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Netflix {
	public:
		Netflix(); 	//Default constructor

		void set_m(int);	
		void set_num_movies();
		
		Movie* get_m() { return m; }
		int get_num_movies() { return num_movies; }
		
		void delete_cast();	
		void output(Movie*, int);	
		void prompt_category();
		void search_title(int);
		~Netflix();	//Destructor
	private:
		Movie *m;
		int num_movies;


};



#endif
