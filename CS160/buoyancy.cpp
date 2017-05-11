#include<iostream>
#include<cmath>

using namespace std;

int main() {
float weight, radius, force, volume;


cout << "Enter radius of sphere: ";
cin >> radius;

volume = (4.0/3)*M_PI*pow(radius, 3);

force = volume * 62.4;
cout << "Buoyant force is " << force << endl;
cout << "Enter weight of sphere: ";
cin >> weight;

if(weight <= force) 
	{
	cout << "\nThis sphere will float." << endl;
	}
else if(weight > force) 
	{
	cout << "\nThis sphere will sink." << endl;
	}


return 0;



}

