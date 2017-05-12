#include<iostream>
#include<string>
#include<stdlib.h>
#include "./rps_class.h"
#include "./RPSGame.h"

using namespace std;


void print_stuff(RPSGame current) {
	cout << "\nPlayer wins: " << current.get_player_wins() << endl;
	cout << "Computer wins: " << current.get_comp_wins() << endl;
	cout << "Draws: " << current.get_draws() << endl;

}






int main() {
	RPSGame current;


	current.play_game(current);
	print_stuff(current);
/*	while(true) {
		char toss = NULL;
		cout << "Choose your tool (r-rock, p-paper, s-scissor, e-exit): "; 
		cin >> toss;
	
		if(toss == 'r' || toss == 'p' || toss == 's'){
			cout << "You chose: " << toss << endl;
			print_stuff(current);
			break;
		}
		else if(toss == 'e') break;
		else cout << "Invalid input. " << endl;
	}
*/


/*	while(tool_strength != "y" && tool_strength != "n") {
		cout << "\nWelcome to Rock, Paper, Scissors! Do you want to choose different strengths for the tools? (y-yes, n-no):   ";
		cin >> tool_strength;
		if(tool_strength == "y")
			cout << "COMING SOON" << endl;
		else if(tool_strength == "n")
			cout << "COMING SOON AGAIN" << endl;
		else
			cout << "Invalid input." << endl;
	}
*/



	return 0;
}
