/**************************************************************
 * Filename: Room/Floor/Roomba/AI Class+ Implementation
 * Author: Ronald Salinas
 * Date: 05/26/2015
 * Description: Class declarations and definitions
 * Input: Command-line arguments in main, integer for Roomba type
 * Output: A sequence of a 2d vector changing
 * *************************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<cstdlib>
#include<cstring>
#include<vector>

using namespace std;

/****************************************************************
 * Function: Class Floor
 * Description: Holds Roomba's row and column and the 2d vector
 * *************************************************************/

class Floor {
	public:
		Floor();
		void set_floor(const char*);
		vector < vector<char> > get_v() { return v; }
		void set_row(int);
		void set_col(int);
		void set_view(int);
		
		void move_row(int);		
		void move_col(int);

		int get_obj_row() { return obj_row; }
		int get_obj_col() { return obj_col; }
		int get_view() { return view; }
	
		void place_roomba();
	private:
		vector < vector<char> > v;	//2-Dimensional vector matrix
		int obj_row;	//Holds an object's current row position
		int obj_col;	//Holds an object's current column position
		int view;
};
/*******************************************
 * Function: Default constructor
 * Description: u kno....
 * Parameters: -
 * Pre-conditions: -
 * Post_conditions: -
 * *****************************************/
Floor::Floor() {
	vector < vector<char> > A(0, vector<char>(0));
	obj_row = 0;
	obj_col = 0;
	view = 0;
}

/****************************************************************
 * Functions: Mutator functions
 * Description: Changes values of private members in Floor
 * Parameters: Integers
 * Pre-conditions: Members should have been initialized to 0
 * Post-conditions: Members will have the same/different values
 * **************************************************************/
void Floor::set_row(int row) {
	obj_row = row;
}
void Floor::set_col(int col) {
	obj_col = col;
}

void Floor::set_view(int v) {
	view = v;
}

void Floor::set_floor(const char* filename) {
	ifstream inFile;
	string temp;
//	inFile.exceptions(ifstream::failbit);
	vector <char> row;
	vector < vector <char> > rowcol;

	if(inFile.fail()) {
		cout << "File name doesn't exist!" << endl;
		exit(EXIT_FAILURE);
	}
	else if(!inFile.fail()) {
		inFile.open(filename, std::ios::in);
		while(getline(inFile, temp)) {
			for(int i = 0; i < temp.length(); i++) {
				row.push_back(temp.at(i));	
			}
			rowcol.push_back(row);
		}
		v = rowcol;
		place_roomba();			//Where should I put this?
		inFile.close();
	}
}

/**********************************************************************
 * Function: Place roomba
 * Description: Places an 'r' in 2d vector depending on given arguments
 * Parameters: -
 * Pre-conditions: 2d vector properly established
 * Post-conditions: 2d modified with 'r'
 * **********************************************************************/

void Floor::place_roomba() {
	//Catch / exception here
	cout << "obj_row = " << obj_row << "\nobj_col = " << obj_col << endl;
	
	if(v[obj_row][obj_col] == 'f') {
		v[obj_row][obj_col] = 'r';
	}
}

/**************************************************************************
 * Function: Move row/col
 * Description: Gets modified depending on move
 * Parameters: Ints
 * Pre-conditions: -
 * Post-conditions: -
 * ***************************************************************************/
void Floor::move_row(int r) {
	obj_row += r;
}

void Floor::move_col(int c) {
	obj_col += c;
}


/***********************************************************************/

template <typename T>
class Room {
	public:
		Room();
		Floor *get_floor() { return &f; }
		~Room();

		virtual void set_roomba(T*);
		T* get_obj() { return obj; }
	

		void clean_room() {
			if(obj != NULL)
				obj->clean_floor(f);	
		}
	private:
		Floor f;
		T *obj;		//obj is the type of Roomba used 
};	

template<typename T>
Room<T>::Room() {
	Floor();
	obj = NULL;
}

/**************************************************************************
 * Function: Set roomba type
 * Description: Dynamically binds a Roomba type to obj
 * Parameters: Roomba Type
 * Pre-conditions: obj is defaulted to NULL
 * Post-conditions: obj will have a  Roomba type
 * ***************************************************************************/
template <typename T>
void Room<T>::set_roomba(T* vec) {
	obj = vec;
}

template <typename T>
Room<T>::~Room() {
	delete obj;
}


/***********************************************************************/

class Roomba {
	public:
		Roomba();
		//The Roomba need to be able to clean a floor and
		//move left, right up, and down
		
			
		void move_up(Floor *f, vector< vector<char> > &floor, int &i);
		void move_down(Floor *f, vector< vector<char> > &floor, int &i);
		void move_left(Floor *f, vector< vector<char> > &floor, int &i);
		void move_right(Floor *f, vector < vector<char> > &floor, int &i);	

		void set_battery(int);
		int get_battery() { return battery; }
		void charge() {	battery--; }	
		
		virtual void clean_floor(Floor f) = 0;	//Pure virtual


		void print_floor(vector< vector<char> > floor, Floor f, int i);
		bool check_floor(vector< vector<char> > floor);
	protected:
		int battery;
		int total_moves;
};

Roomba::Roomba() {
	battery = 0;
	total_moves = 0;
}
/**************************************************************************
 * Function: Print floor
 * Description: Prints 2d vector when called
 * Parameters: 2d vector of chars, Floor-type object, iteration count
 * Pre-conditions: -
 * Post-conditions: -
 * ***************************************************************************/
void Roomba::print_floor(vector< vector<char> > floor, Floor f, int i) {
	if(i % f.get_view() == 0) {	
		cout << "Move: " << i << endl;
		cout << "Battery life: " << battery << endl;
		for(int j = 0; j < floor.size(); j++) {
			for(int k = 0; k < floor[0].size(); k++) {
				cout << floor[j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	else return;
}
/**************************************************************************
 * Function: Check clean floor
 * Description: Checks if floor is clean. If not, program continues
 * Parameters: 2d vector of chars
 * Pre-conditions: 2d vector could be clean/dirty
 * Post-conditions: -
 * ***************************************************************************/

bool Roomba::check_floor(vector < vector<char> > floor) {	
	for(int i = 0; i < floor.size(); i++) {
		for(int k = 0; k < floor[0].size(); k++) {
			if(floor[i][k] == 'f') return true;
		}
	}	
	return false;
}

/********************************************************************************************
 * Functions: Directional movements
 * Description: Moves Roomba's place either up, down, left, or right
 * Parameters: Pointer to floor class object, reference 2d vector, reference iteration count
 * Pre-conditions: -
 * Post-conditions: -
 * ******************************************************************************************/

void Roomba::move_up(Floor *f, vector< vector<char> > &floor, int &i) {
	if(f->get_obj_row() - 1 >= 0) {
		i++;
		floor[f->get_obj_row()][f->get_obj_col()] = 'c';
		f->move_row(-1);
		floor[f->get_obj_row()][f->get_obj_col()] = 'r';
		charge();
		print_floor(floor, *f, i);
	}
	else return;
}
void Roomba::move_down(Floor *f, vector< vector<char> > &floor, int &i) {
	if(f->get_obj_row() + 1 <= f->get_v().size() - 1) {
		i++;
		floor[f->get_obj_row()][f->get_obj_col()] = 'c';
		f->move_row(1);
		floor[f->get_obj_row()][f->get_obj_col()] = 'r';
		charge();
		print_floor(floor, *f, i);
	}
	else return;
}
void Roomba::move_left(Floor *f, vector< vector<char> > &floor, int &i) {
	if(f->get_obj_col() - 1 >= 0) {
		i++;
		floor[f->get_obj_row()][f->get_obj_col()] = 'c';
		f->move_col(-1);	
		floor[f->get_obj_row()][f->get_obj_col()] = 'r';
		charge();
		print_floor(floor, *f, i);
	}
	else return;
}
void Roomba::move_right(Floor *f, vector< vector<char> > &floor, int &i) {
	if(f->get_obj_col() + 1 <= f->get_v()[0].size() - 1) {
		i++;
		floor[f->get_obj_row()][f->get_obj_col()] = 'c';
		f->move_col(1);
		floor[f->get_obj_row()][f->get_obj_col()] = 'r';
		charge();
		print_floor(floor, *f, i);
	}
	else return;
}


/**************************************************************************
 * Function: Set battery
 * Description: Sets battery life member
 * Parameters: Int
 * Pre-conditions: battery initialized to 0
 * Post-conditions: -
 * ***************************************************************************/

void Roomba::set_battery(int b) { 
	battery = b; 
}


/**************************************************************************/


/**************************************************************************
 * Function: Random Roomba class
 * Description: Roomba moves around floor randomly
 * Parameters: Floor type object
 * Pre-conditions: 2d vector is dirty
 * Post-conditions: 2d vector is clean
 * ***************************************************************************/

class RandomRoomba : public Roomba {
	public: 
		RandomRoomba() { cout << "You chose random. " << endl;	}
		
		virtual void clean_floor(Floor f) {
			srand(time(NULL));
			vector< vector<char> > floor = f.get_v();
			Floor class_f = f;
			int i = 0;
			while(check_floor(floor) && battery != 0) {
				int random = rand()%4 + 1;
				if(random == 1) move_up(&class_f, floor, i);
				else if(random == 2) move_down(&class_f, floor, i);
				else if(random == 3) move_left(&class_f, floor, i);
				else if(random == 4) move_right(&class_f, floor, i);
			}
			if(!check_floor(floor)) cout << "\nROOM CLEANED IN " << i << " MOVES! " << endl;
			else cout << "\nOUT OF BATTERY! " << endl;
		}


};
/**************************************************************************
 * Function: Roomba 1 (Roomba 9100)
 * Description: Roomba moves up and down every single column
 * Parameters: Floor type object
 * Pre-conditions: 2d vector is dirty
 * Post-conditions: 2d vector is clean
 * ***************************************************************************/


class Roomba1 : public Roomba {
	public:
		Roomba1() { cout << "You chose the Cleanerator. " << endl; }		

		virtual void clean_floor(Floor f) {
			vector< vector<char> > floor = f.get_v();
			Floor class_f = f;
			int i = 0;
		
			//Begins by going to the leftern most edge	
			while(class_f.get_obj_col() != 0 && battery != 0) move_left(&class_f, floor, i);
			while(check_floor(floor) && battery != 0) {
				while(class_f.get_obj_row() != 0 && battery != 0) move_up(&class_f, floor, i);
				while(class_f.get_obj_row() != floor.size() - 1 && battery != 0) move_down(&class_f, floor, i);
				if(battery != 0) move_right(&class_f, floor, i);
			}
			if(!check_floor(floor)) cout << "\nROOM CLEANED IN " << i << " MOVES! " << endl;
			else cout << "\nOUT OF BATTERY! " << endl;
		}

};

/**************************************************************************
 * Function: Roomba 2 (Cleanerator)
 * Description: Roomba moves horizontally for each row
 * Parameters: Floor type object
 * Pre-conditions: 2d vector is dirty
 * Post-conditions: 2d vector is clean
 * ***************************************************************************/


class Roomba2 : public Roomba {
	public:
		Roomba2() { cout << "You chose the Roomba 9100. " << endl; }

		virtual void clean_floor(Floor f) {
			vector< vector<char> > floor = f.get_v();
			Floor class_f = f;
			int i = 0;

			//Begins by moving to the very top left of the floor
			while(class_f.get_obj_col() != 0 && battery != 0) move_left(&class_f, floor, i);
			while(class_f.get_obj_row() != 0 && battery != 0) move_up(&class_f, floor, i);
				
			while(check_floor(floor) && battery != 0) {
				while((class_f.get_obj_col() != floor[0].size() - 1) && battery != 0) move_right(&class_f, floor, i);
				if(battery != 0) move_down(&class_f, floor, i);
				while((class_f.get_obj_col() != 0 && battery != 0)) move_left(&class_f, floor, i);	
				if(battery != 0) move_down(&class_f, floor, i);
			}
			if(!check_floor(floor)) cout << "\nROOM CLEANED IN " << i << " MOVES! " << endl;
			else cout << "\nOUT OF BATTERY! " << endl;
		}
};

#endif
