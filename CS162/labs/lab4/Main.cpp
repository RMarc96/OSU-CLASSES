#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include "Movie.h"

using namespace std;


void search(string s) {
	string temp, line;

	ifstream search("catalog.dat");
	ofstream add("catalog2.dat");
	
	while(!search.eof()) {
		search >> temp;
		
		if(temp.find(s)) {
			for(int i = temp.length() - 1; i > 0; i--) {
				if(temp[i] == '|') break;
				else{
					char new_temp = temp[i];
					temp[i] = (int)new_temp - 1;
				}
			}
				
		}
		add << temp;
	}

	cout << endl << "\nMovie rented! " << endl;

	remove("catalog.dat");
	rename("catalog2.dat", "catalog.dat");

}






void fun(Movie main_mov) {
	Movie m(9);

	m = main_mov;       //For overload
	
}





int main() {
	Movie m(4);		//For copy

	fun(m);			//For copy

//	fun();


	search("Computer Science 261");

	
	return 0;
}









//a2 = a1       Overload
//Movie a2(a1)	Copy Construct
