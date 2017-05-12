#include "./RPSGame.h"
#include<string>
#include<stdlib.h>
#include<iostream>

using namespace std;
/************************************************************
 * Function: Default constructor
 * Description: Initializes RPSGame class members
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * **********************************************************/

RPSGame::RPSGame() {
	player_t = NULL;			//CHANGE BACK TO NULL
	comp_t = NULL;
	player_wins = 0;
	comp_wins = 0;
	draws = 0;

}

/*********************************************************
 * Function: Desctructor
 * Description: Deletes out-of-scope members
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * ******************************************************/

RPSGame::~RPSGame() {
	delete [] player_t;
	delete [] comp_t;
}

/***********************************************************
 * Function: Print
 * Description: Prints player wins, computer wins, and draws
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * *********************************************************/

void RPSGame::print_stuff() {
	cout << "\nPlayer wins: " << get_player_wins() << endl;
	cout << "Computer wins: " << get_comp_wins() << endl;
	cout << "Draws: " << get_draws() << endl;

}

/***************************************************************************
 * Function: Fight
 * Description: Determines who wins
 * Parameters: Player and computer tool arrays, Rock, Paper, Scissor objects
 * Pre-conditions: Everything hasn't broken down yet
 * Post-conditions: Everything still hasn't broken down yet
 * ************************************************************************/

void RPSGame::fight(Tool player_t, Tool comp_t, Rock r, Paper p, Scissors s) {
	cout << "\nPlayer chose " << player_t.get_type() << " with strength " << player_t.get_strength() << endl;
	cout << "Computer chose " << comp_t.get_type() << " with strength " << comp_t.get_strength() << endl << endl;

	if(player_t.get_type() == comp_t.get_type()) draws++;
	if((player_t.get_type() == 'r' && comp_t.get_type() == 'p') || (player_t.get_type() == 'p' && comp_t.get_type() == 's') || (player_t.get_type() == 's' && comp_t.get_type() == 'r')) {
		if(player_t.get_strength() / 2 > comp_t.get_strength()) {
			cout << "\nYOU WIN!" << endl;
			player_wins++;
		}
		else if(player_t.get_strength() / 2 < comp_t.get_strength()) {
			cout << "\nCOMPUTER WINS!" << endl;
			comp_wins++;
		}
		else {
			cout << "\nIT'S A DRAW!" << endl;
			draws++;
		}
	}
	
	else if((player_t.get_type() == 'r' && comp_t.get_type() == 's') || (player_t.get_type() == 's' && comp_t.get_type() == 'p') || (player_t.get_type() == 'p' && comp_t.get_type() == 'r')) {
		if(player_t.get_strength() * 2 > comp_t.get_strength()) {	
			cout << "\nYOU WIN!" << endl;
			player_wins++;
		}	
		else if(player_t.get_strength() * 2 < comp_t.get_strength()) {
			cout << "\nCOMPUTER WINS!" << endl;
			comp_wins++;
		}
		else {
			cout << "\nIT'S A DRAW!" << endl;
			draws++;
		}
	}
	print_stuff();
	
} 

/***************************************************************************
 * Function: Set
 * Description: Set player tool choice and AI tool choice
 * Parameters: Player-chosen tool choice and Rock, Paper, Scissor objects
 * Pre-conditions: -
 * Post-conditions: -
 * ************************************************************************/


void RPSGame::set_player_and_comp_t(int i, char x, Rock r, Paper p, Scissors s) {
	player_t = new Tool;
	comp_t = new Tool;
	
	if(x == 'r') {
		player_t[0] = r;	//Upcasting?
		player_t[0].set_type('r');
	}
	else if(x == 'p') {
		player_t[0] = p;
		player_t[0].set_type('p');
	}
	else if(x == 's') {
		player_t[0] = s;
		player_t[0].set_type('s');
	}


	int ai;
	ai = rand() % 3 + 1;		//Random from 1 to 3
	if(ai == 1) {
		comp_t[0] = r;
		comp_t[0].set_type('r');
	}	
	else if(ai == 2) {
		comp_t[0] = p;
		comp_t[0].set_type('p');
	}
	else if(ai == 3) {
		comp_t[0] = s;
		comp_t[0].set_type('s');
	}
	

	fight(player_t[0], comp_t[0], r, p, s);

	delete [] player_t;
	delete [] comp_t;
}	
