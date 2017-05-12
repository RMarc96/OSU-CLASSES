#include<iostream>
#include<stdlib.h>
#include<string>
#include"./Movie.h"
//#include"./Netflix.h"

using namespace std;

Movie::Movie() {
	name = "--";
	stars = 0;
	num_cast = 0;
	cast = NULL;
	rating = "--";
	copies = 0;
}

Movie::Movie(int num) {
	num_cast = num;

	cast = new string[num_cast];	
}
Movie::~Movie() {
//	delete [] cast;	
}
	
Movie::Movie(const Movie& mov) {	//Copy constructor
	name = mov.name;
	stars = mov.stars;
	num_cast = mov.num_cast;
//	cast = mov.cast;
	rating = mov.rating;
	copies = mov.copies;



}

Movie &Movie::operator=(const Movie &mov) {
	if(this == &mov) {
		return *this;
	}
	if(num_cast != 0)
	{
		delete [] cast;
		cast = NULL;
	}

	this->name = mov.name;
	this->stars = mov.stars;
	this->num_cast = mov.num_cast;
	cast = new string[num_cast];
	for(int i=0; i< num_cast; i++)
		this->cast[i] = mov.cast[i];
	
	this->rating = mov.rating;
	this->copies = mov.copies;

	return *this;

}





/********************************************************/


void Movie::set_name() {
	cout << "Enter movie title: ";
	cin >> name;
}

void Movie::set_stars() {
	cout << "Enter stars: ";
	cin >> stars;
}

void Movie::set_num_cast() {
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
	cin >> rating;	
}

void Movie::set_copies() {
	cout << "Enter number of copies: ";
	cin >> copies;
}
	
