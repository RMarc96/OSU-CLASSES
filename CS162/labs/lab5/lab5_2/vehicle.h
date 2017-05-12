#ifndef VEHICLE_H
#define VEHICLE_H
#include "./Date.h"

class vehicle {
	public:
		vehicle();

		vehicle(int);
		
	
		int get_seats();
		void set_seats(int);

		virtual int get_toll(int);
		void set_date(Date obj) {
			obj.set_day(5);
			d = obj;
		}
		Date get_d() { return d; }	
		
	private:
		int seats;
		Date d;


};


#endif
