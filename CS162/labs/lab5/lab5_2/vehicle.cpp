#include"./vehicle.h"
#include "./Date.h"

vehicle::vehicle() {
	seats = 1;
}

vehicle::vehicle(int x) {
	seats = x;
}


void vehicle::set_seats(int s) {
	seats = s;

}

int vehicle::get_seats() {
	return seats;
}

int vehicle::get_toll(int day) {
	return 20*seats;
}
