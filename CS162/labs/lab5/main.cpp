#include<iostream>
#include "./vehicle.h"
#include "./bike.h"
#include "./motorcycle.h"
#include "./car.h"
#include "./skateboard.h"

using namespace std;

int main() {
	vehicle v(4);
	bike b(1);
	motorcycle m(1);
	car(4);
	skateboard(4);
	
//	vehicle *vptr = &b;


	vehicle v_array[3] = {bike(1), skateboard(1), car(4)};


	
/*	cout << "Vehicles have: " <<  v.get_seats() << " seats. " << endl;
	cout << "Bikes have " << b.get_seats() << " seats. " << endl;

	cout << "Vehicles have to pay " << v.get_toll() << endl;
	cout << "Bikes have to pay " << b.get_toll() << endl;

	cout << vptr -> get_seats() << endl;
	cout << vptr -> get_toll() << endl;

*/
	return 0;
}
