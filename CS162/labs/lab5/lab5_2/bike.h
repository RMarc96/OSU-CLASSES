#ifndef BIKE_H
#define BIKE_H
#include "./vehicle.h"

class bike : public vehicle {
	public:
		bike();		
		bike(int);
		int get_toll();
};

#endif
