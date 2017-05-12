#ifndef RPSGAME_H
#define RPSGAME_H

#include "./rps_class.h"
#include<string>

class RPSGame {
	public:
		RPSGame();
		~RPSGame();
		

		int get_player_wins() { return player_wins; }	
		int get_comp_wins() { return comp_wins; }
		int get_draws() { return draws; }

		void print_stuff();

		void set_player_and_comp_t(int, char, Rock, Paper, Scissors);

		void fight(Tool, Tool, Rock, Paper, Scissors);

	
		Tool* get_player_t() { return player_t; }
		Tool* get_comp_t() { return comp_t; }
	private:
		Tool* player_t;
		Tool* comp_t;


		int player_wins;
		int comp_wins;
		int draws;
	





};












#endif
