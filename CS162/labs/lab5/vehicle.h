#ifndef VEHICLE_H
#define VEHICLE_H

class vehicle {
	public:
		vehicle();

		vehicle(int);
		
	
		int get_seats();
		void set_seats(int);

		virtual int get_toll();
	private:
		int seats;



};


#endif
