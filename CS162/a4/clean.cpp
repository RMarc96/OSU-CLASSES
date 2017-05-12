#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<string.h>
#include<stdlib.h>
#include "./room.hpp"

using namespace std;

/*****************************************************************
 * Function: Choose roomba
 * Description: Chooses a Roomba-type object to bind to Floor::obj
 * Parameters: Reference of Room-type object of class Roomba
 * Pre-conditions: -
 * Post-conditions: -
 * ****************************************************************/

void choose_roomba(Room <Roomba> &r) {
	int choice;
	cout << "Which Roomba (1 - Random, 2 - Cleanerator, 3 - Roomba 9100)? ";
	cin >> choice;

	if(choice == 1) r.set_roomba(new RandomRoomba);
	if(choice == 2) r.set_roomba(new Roomba1);
	else if(choice == 3) r.set_roomba(new Roomba2);

}

/************************************************************************
 * Function: Main
 * Description: Assigns values for filename, battery, row, col, and view
 * Parameters: Argument count, argument vector
 * Pre-conditions: -
 * Post-conditions: -
 * ****************************************************************/


int main(int argc, char* argv[]) {
	Room <Roomba> r;
	string filename;
	choose_roomba(r);
	
	
	for(int i = 0; i < argc; i++) {
		if(!strcmp(argv[i], "-b")) { 
			r.get_obj()->set_battery(atoi(argv[i+1]));
		}
		else if(!strcmp(argv[i], "-f")) {
			filename = argv[i+1];
		}
		else if(!strcmp(argv[i], "-r")) {
			r.get_floor()->set_row(atoi(argv[i+1]));
		}
		else if(!strcmp(argv[i], "-c")) {	
			r.get_floor()->set_col(atoi(argv[i+1]));
		}
		else if(!strcmp(argv[i], "-v")) {
			r.get_floor()->set_view(atoi(argv[i+1]));
		}
			
	}
	cout << "BATTERY LIFE: " << r.get_obj()->get_battery() << endl;

	r.get_floor()->set_floor(filename.c_str());



	r.clean_room(); //Now clean it after everything is set up
		
	return 0;
}


