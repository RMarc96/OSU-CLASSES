#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>
#include"./Connect.h"

using namespace std;
bool is_valid_arguments(char* info[]) {
	for(int i = 0; i < 7; i++) {
		if((strcmp(info[i],"-r")) == 0|| strcmp(info[i], "-c") == 0 || strcmp(info[i] , "-p") == 0) {
			for(int j = 0; j < strlen(info[i+1]); j++) {
				while(!(info[i+1][j] >= '0' && info[i+1][j] <= '9') || info[i+1] == "0") {
					cout << "Invalid succeeding argument after " << info[i] << ". Enter a new non-zero integer: ";
					cin >> info[i+1];
				}
			 }
		}
	}
	return true;				
}

bool all_arguments(char* argv[]) {
	bool dash_r ,dash_c, dash_p;
	dash_r = dash_c = dash_p = false;
	for(int i = 0; i < 7; i++) {
		if(argv[i] == "-r") dash_r = true;
		else if(argv[i] == "-c") dash_c = true;
		else if(argv[i] == "-p") dash_p = true;
	}
	if(dash_r && dash_c && dash_p) return true;
	else return false;
}
void set_game_info(game *current, char* info[]) {
	for(int i = 0; i < 7; i++) {
		if(strcmp(info[i], "-r") == 0) (*current).r = atoi(info[i+1]);
		else if(strcmp(info[i], "-c") == 0) (*current).c = atoi(info[i+1]);
		else if(strcmp(info[i], "-p") == 0) (*current).p = atoi(info[i+1]);
	}
	while((*current).p1 != 'r' || (*current).p1 != 'y') {
		cout << "Player 1, do you want red or yellow (r or y)? ";
		cin >> (*current).p1;
		if((*current).p1 == 'r' || (*current).p2 == 'y') break;
	}

	if((*current).p1 == 'r') (*current).p2 = 'y';
	else (*current).p2 = 'r';
}	

char** create_table(int r, int c) {
	char** pancakes;
	pancakes = new char*[r];
	
	for(int i = 0; i < r; i++) {
		pancakes[i] = new char[c];
	}
	return pancakes;
}

void print_junk(char **table, int r, int c) {
	for(int i = 0; i < r; i++) {
		cout << "|\t"; 
		for(int j = 0; j < c; j++) {
			cout << table[i][j] << "\t|\t";
		}
		cout << endl;
	}
	cout << " _______________________________" << endl;
}

bool filled_column(game* current, int column_choice) {
	for(int i = (*current).r - 1; i >= 0; i--) {
		if((*current).board[i][column_choice] != 'r' && (*current).board[i][column_choice] != 'y')
			return true;
	}
	return false;
}
int more_than(int r, int column_choice) {
	if(column_choice - 1 > r) {
		cout << "That column doesn't exist! Choose a new column: ";
		cin >> column_choice;
	}
	return column_choice;
}
void place_piece(game* current, int column_choice, char turn_player) {
	int j = column_choice;
	bool fill = filled_column(current, j);	
	
	while(!fill) {
		cout << "That column is filled! Choose a new column: ";
		cin >> j;
		fill = filled_column(current, j);
		j = j - 1;
	}
	while(column_choice - 1> (*current).r) {
		column_choice = more_than((*current).r, *&column_choice);
	}
	
	for(int i = (*current).r - 1; i >= 0; i--) {
		if(!((*current).board[i][j] == 'r' || (*current).board[i][j] == 'y')) {
			(*current).board[i][j] = turn_player;
			break;
		}
		else column_choice = column_choice - 1;
		cout << endl;
	}

	print_junk((*current).board, (*current).r, (*current).c);
}

bool check_winner(game current) {
	bool v = check_verticals(current), h = check_horizontals(current), d_one = check_diagonals_one(current), d_two = check_diagonals_two(current);
	
	cout << "v = " << v << endl;
	cout << "h = " << h << endl;
	cout << "d_one = " << d_one << endl;
	cout << "d_two = " << d_two << endl;
	if(v == false || h == false || d_one == false || d_two == false) {
		return false;
	}
	else return true;
}

bool check_diagonals_two(game current) {
	char **matrix = current.board;
	for(int i = current.r - 1; i > current.r - current.p + 1; i--)
		for(int j = 0; j < current.c - current.p + 1; j++) {
			if(matrix[i][j] == 'r' && matrix[i - current.p + 1][j + current.p - 1] == 'r') {
				for(int k = 0; k < current.p; k++)
					if(matrix[i-k][j+k] != 'r') return true;
				cout << "RED PLAYER WINS!" << endl;
				return false;
			}
			if(matrix[i][j] == 'y' && matrix[i - current.p + 1][j + current.p - 1] == 'y') {
				for(int k = 0; k < current.p; k++)
					if(matrix[i-k][j+k] != 'y') return true;
				cout << "YELLOW PLAYER WINS!" << endl;
				return false;
			}
		
		}
	return true;
}


bool check_diagonals_one(game current) {
	char **matrix = current.board;
	for(int i = 0; i < current.r - current.p + 1; i++)
		for(int j = 0; j < current.c - current.p + 1; j++) {
			if(matrix[i][j] == 'r' && matrix[i + current.p - 1][j + current.p - 1] == 'r') {
				for(int k = 0; k < current.p; k++)
					if(matrix[i+k][j+k] != 'r') return true;
				cout << "RED PLAYER WINS!" << endl;
				return false;
			}
			if(matrix[i][j] == 'y' && matrix[i + current.p - 1][j + current.p - 1] == 'y') {
				for(int k = 0; k < current.p; k++)
					if(matrix[i+k][j+k] != 'y') return true;
				cout << "YELLOW PLAYER WINS!" << endl;
				return false;
			}
		
		}
	return true;
}


bool check_horizontals(game current) {
	char **matrix = current.board;
	for(int j = 0; j < current.c - current.p + 1; j++)
		for(int i = 0; i < current.r; i++) {
			if(matrix[i][j] == 'r' && matrix[i][j + current.p - 1] == 'r') {
				for(int k = 0; k < current.p; k++)
					if(matrix[i][j+k] != 'r') return true;
				cout << "RED PLAYER WINS!" << endl;
				return false;
			}
			if(matrix[i][j] == 'y' && matrix[i][j + current.p - 1] == 'y') {
				for(int k = 0; k < current.p; k++)
					if(matrix[i][j+k] != 'y') return true;
				cout << "YELLOW PLAYER WINS!" << endl;
				return false;
			}
		
		}
	return true;
}



bool check_verticals(game current) {
	char **matrix = current.board;
	for(int i = 0; i < current.r - current.p + 1; i++)
		for(int j = 0; j < current.c; j++) {
			if(matrix[i][j] == 'r' && matrix[i + current.p - 1][j] == 'r') {
				for(int k = 0; k < current.p; k++)
					if(matrix[i+k][j] != 'r') return true;
				cout << "RED PLAYER WINS!" << endl;
				return false;
			}
			if(matrix[i][j] == 'y' && matrix[i + current.p - 1][j] == 'y') {
				for(int k = 0; k < current.p; k++)
					if(matrix[i+k][j] != 'y') return true;
				cout << "YELLOW PLAYER WINS!" << endl;
				return false;
			}
		
		}
	return true;
}

	
void play_game(game* current) {
	bool go_on = true;
	int i = 0;

	while(go_on != false) {
		int turn_switch = i%2, column_choice;
		if(turn_switch == 0) {
			i = i + 1;
			cout << endl << "Player 1, what column do you want to put your piece? ";
			cin >> column_choice;
			
			place_piece(*&current, column_choice - 1, (*current).p1);
			go_on = check_winner(*current);
		}
		else if(turn_switch == 1) {
			i = i + 1;
			cout << endl << "Player 2, what column do you want to put your piece? ";
			cin >> column_choice;

			place_piece(*&current, column_choice - 1, (*current).p2);
			go_on = check_winner(*current);
		}
	}
}


void delete_table(game *current) {
	for(int i = 0; i < (*current).r; i++)
		delete [] (*current).board[i];

	delete [] (*current).board;

	(*current).board = NULL;
}
	
