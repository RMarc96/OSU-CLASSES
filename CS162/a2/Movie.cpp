#include<iostream>
#include<stdlib.h>
#include<string>
#include"./Movie.h"
#include"./Netflix.h"

using namespace std;

Movie::Movie() {
	name = "--";
	stars = 0;
	num_cast = 0;
	cast = NULL;
	rating = "--";
	copies = 0;
}

Movie::~Movie() {}


void ask_stuff() {
	string n, *c, rat;
	int s, n_c, cop;

	cout << "Enter title of movie: ";
	cin >> n;

	cout << "Enter stars: ";
	cin >> s;
	
	cout << "Enter number of cast members: ";
	cin >> n_c;

	
}

void Movie::set_name(string n) {
	name = n;
}

void Movie::set_stars(int s) {
	stars = s;
//	cout << "Enter stars: ";
//	cin >> stars;
}

void Movie::set_num_cast(int n_c) {
	num_cast = n_c;
//	cout << "Enter number of cast members: ";
//	cin >> num_cast;
}

void Movie::set_cast(int num) {
	cast = new string[num];
	for(int i = 0; i < num; i++) {
		cout << "Enter cast member " << i+1 << ": ";
		cin >> cast[i];
	}
}

void Movie::set_rating() {
	cout << "Enter movie rating: ";
	cin >> rating;

	
}

void Movie::set_copies() {
	int quantity;
	cout << "How many copies of this movie: ";
	cin >> quantity;

	copies = quantity;
}
	
