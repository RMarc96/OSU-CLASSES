#include "./car.h"


car::car(): vehicle() {}



car::car(int x): vehicle(x) {}




int car::get_toll(int day) {
	if(day == 6)
		return 10*get_seats();
	else return 20*get_seats();
}
