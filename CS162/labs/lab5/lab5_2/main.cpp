#include<iostream>
#include "./vehicle.h"
#include "./bike.h"
#include "./motorcycle.h"
#include "./car.h"
#include "./skateboard.h"
#include "./Date.h"

using namespace std;

int main() {
	vehicle v(4);
	bike b(1);

//	vehicle *vptr = &b;

	motorcycle m(1);
	car c(4);
	skateboard s(0);
	

//	v = m;		//Upcasting example


//	vehicle v_array[3] = {bike(1), skateboard(1), car(4)};


	
/*	cout << "Vehicles have: " <<  v.get_seats() << " seats. " << endl;
	cout << "Bikes have " << b.get_seats() << " seats. " << endl;
	cout << "Cars have: " << c.get_seats() << " seats. " << endl;
	cout << "Motorcycles have: " << m.get_seats() << " seats. " << endl;
	cout << "Skateboards have: " << s.get_seats() << " seats. " << endl;

	cout << "\nVehicles have to pay " << v.get_toll() << endl;
	cout << "Bikes have to pay " << b.get_toll() << endl;
	cout << "Cars have to pay " << c.get_toll() << endl;
	cout << "Motorcycles have to pay " << m.get_toll() << endl;
	cout << "Skateboard have to pay " << s.get_toll() << endl;
*/
//	cout << vptr -> get_seats() << endl;
//	cout << vptr -> get_toll() << endl;


/*	vehicle v_array[2] = {bike(1), car(4)};
	
	cout <<	v_array[0].get_toll() << endl; //Bike pays a toll since it is bound to vehicle

	vehicle *v_array_2[2] = {new bike(1), new car(4)};	//Made dynamic

	cout <<	v_array_2[0] -> get_toll() << endl;
*/

	Date d;

	v = m;		//Upcast to car or motorcycle
	d.set_day(3);
	d.set_month("May");
	d.set_year(2015);

	v.set_date(d);
		
	d.print_shrt_date();	
	d.print_long_date();
	cout << "Day of week: " << d.get_day_of_week() << endl;
	cout << "Toll: " << v.get_toll(d.get_day_of_week()) << endl;
	return 0;
}
