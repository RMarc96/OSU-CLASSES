/**********************************************************
 * Filename: Assignment 3 "Is A" Relationship/Inheritance
 * Author: Ronald Salinas
 * Date: May 9, 2015
 * Description: Plays a classic/modified game of rock,paper,scissors
 * Input: Tool strengths and tool type
 * Output: Computer-chosen tool choice
 * ********************************************************/

#include<iostream>
#include<string>
#include<stdlib.h>
#include<cstring>
#include<sstream>
#include "./rps_class.h"
#include "./RPSGame.h"

using namespace std;

void check_input(string &, string &, string &, int &, int &, int &);

/***************************************************************
 * Function: Set strengths
 * Description: 3-in-1 function which sets strength values
 * Parameters: References of Rock, Paper, Scissor objects
 * Pre-conditions: -
 * Post-conditions: -
 * ***********************************************************/

void set(Rock &r, Paper &p, Scissors &s) {
	string rock, paper, scissor;
	int rock_checked, paper_checked, scissor_checked;
	
	cout << "Enter rock strength: ";
	cin >> rock;
	cout << "Enter paper strength: ";
	cin >> paper;
	cout << "Enter scissor strength: ";
	cin >> scissor;
	
	check_input(rock, paper, scissor, rock_checked, paper_checked, scissor_checked);

	r.setStrength(rock_checked);
	p.setStrength(paper_checked);
	s.setStrength(scissor_checked);
		
}

/**************************************************************
 * Function: Check input
 * Description: Error checks input for strengths
 * Parameters: References of rock, paper, scissor orbjects
 * Pre-conditions: Something must be inputted from function call
 * Post-condition: Returns proper integers
 * ************************************************************/

void check_input(string &rock, string &paper, string &scissor, int &rock_checked, int &paper_checked, int &scissor_checked) {
	stringstream ss;

	for(int i = 0; i < rock.length(); i++) {
		if(!(rock[i] >= '0' && rock[i] <= '9')) {
			cout << "Invalid rock strength value. Enter new integer: ";
			cin >> rock;
			i = 0;
		}
	}
	for(int j = 0; j < paper.length(); j++) {
		if(!(paper[j] >= '0' && paper[j] <= '9')) {
			cout << "Invalid paper strength value. Enter new integer: ";
			cin >> paper;
			j = 0;
		}
	}
	for(int k = 0; k < scissor.length(); k++) {
		if(!(scissor[k] >= '0' && scissor[k] <= '9')) {
			cout << "Invalid scissor strength value. Enter new integer: ";
			cin >> scissor;
			k = 0;
		}
	}
	ss << rock;
	ss >> rock_checked;
	ss << paper;
	ss >> paper_checked;
	ss << scissor;
	ss >> scissor_checked;	

}

/*******************************************************************
 * Function: Play
 * Description: Prompts user for tool type for playing
 * Parameters: RPSGame, Rock, Paper, and Scissors objects
 * Pre-conditions: Rock, Paper, Scissors initialized/modified properly
 * Post-conditions: -
 * *****************************************************************/

void play_game(RPSGame current, Rock r, Paper p, Scissors s) {
	int i = 0;
	while(true) {
		char toss = NULL;
		
		cout << "Choose your tool (r-rock, p-paper, s-scissors, e-exit): ";
		cin >> toss;
	
		if(toss == 'r' || toss == 'p' || toss == 's') {
			current.set_player_and_comp_t(i, toss, r, p, s);
			i++;
		}
		else if(toss == 'e') {
			cout << "\nGOOD GAME!" << endl;
			break;
		}
		else cout << "\nInvalid input\n" << endl;
	}
}

/**************************************************************
 * Functions: Main
 * Description: Asks user for normal or modified game
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Normal termination
 * ***********************************************************/ 

int main() {
	RPSGame current;
	Rock r;
	Paper p;
	Scissors s;
	string tool_strength;

	while(tool_strength != "y" && tool_strength != "n") {
		cout << "\nWelcome to Rock, Paper, Scissors! Do you want to choose different strengths for the tools? (y-yes, n-no):   ";
		cin >> tool_strength;
		if(tool_strength == "y") {
			set(r,p,s);
			break;
		}
		else if(tool_strength == "n")
			break;
		else
			cout << "Invalid input." << endl;
	}

	play_game(current, r, p, s);


	return 0;
}
