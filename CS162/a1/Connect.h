#ifndef CONNECT_H
#define CONNECT_H

using namespace std;

struct game {
	char **board;
	int r, c, p;
	char p1;
	char p2;
};
bool is_valid_arguments(char* info[]);
void set_game_info(game *, char *info[]);
char** create_table(int, int);
void play_game(game *);
bool check_winner(game);
void delete_table(game *);
void print_junk(char**, int, int);
bool filled_column(game*, int);
int more_than(int, int);
void place_piece(game*, int, char);
bool check_winner(game);
bool check_diagonals_two(game current);
bool check_diagonals_one(game current);
bool check_horizontals(game current);
bool check_verticals(game current);
bool all_arguments(char* argv[]);



#endif
