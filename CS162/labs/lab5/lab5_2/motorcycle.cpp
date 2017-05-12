#include "./motorcycle.h"


motorcycle::motorcycle(): vehicle() {}



motorcycle::motorcycle(int x): vehicle(x) {}




int motorcycle::get_toll(int day) {
	if(day == 0) 
		return 10*get_seats();
	else return 20*get_seats();
}
