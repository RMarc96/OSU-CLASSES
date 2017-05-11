#include<iostream>
#include<cmath>

#define WATER_WEIGHT 62.4  //Defines the specific weight of water

using std::cout;
using std::cin;

int main () {
	//Variables needed to calculate buoyancy
	float radius, bforce, volume, weight;

	//Prompt user for weight and radius of sphere
	cout << "Please enter the weight (lbs): ";
	cin>> weight;

	cout << "Please enter the radius: ";
	cin >> radius;
	
	//Calculate the volume and buoyancy
	volume = 4.0/3.0 * M_PI * pow(radius, 3);
	bforce = volume * WATER_WEIGHT;

	//Determine if the sphere will sink or float
	if(bforce >= weight) {
		cout << "The sphere will float!\n";
	}
	else	cout << "The sphere will sink!\n";

	return 0;
}

