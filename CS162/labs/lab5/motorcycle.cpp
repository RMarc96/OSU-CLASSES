#include "./motorcycle.h"

motorcycle::motorcycle(): vehicle() {}

motorcycle::motorcycle(int m): vehicle(m) {}

int motorcycle::get_toll() {
	return 20*get_seats();
	
}
