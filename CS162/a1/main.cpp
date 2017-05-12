/*******************************************************************************
 * Filename: Assignment 1 - Connect Any
 * Author: Ronald Salinas
 * Date: 12 April 2015
 * Description: Plays a game of "Connect Four" with any size matrix and pieces
 * Input: Number arguments in command line and column of choice
 * Output: Progressed table of the game
 * *******************************************************************************/
#include<iostream>
#include<stdlib.h>
#include<string>
#include"./Connect.h"


int main(int argc, char* argv[]) {
	game current;
	if(argc < 7 || argc > 7) {
		cout << "Too few/too many arguments." << endl;
		return 0;
	}
	if(all_arguments(argv)) {
		cout << "Missing arguments." << endl;
		return 0;
	}
	is_valid_arguments(argv);

	set_game_info(&current, argv);
	current.board = create_table(current.r, current.c);	
	print_junk(current.board, current.r, current.c);
	play_game(&current);
	delete_table(&current);



	return 0;
}	
