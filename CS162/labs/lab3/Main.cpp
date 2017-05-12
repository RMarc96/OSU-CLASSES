#include<iostream>
#include<string>
#include "./Pharmacy.h"
#include "./Surgery.h"
#include "./Patient.h"

using namespace std;

int main() {
	Surgery s;
	Pharmacy phar;

	string type;
	int types_med, days;
	float surg_cost, med_cost;

	
	



	cout << "Enter how many types of medications: ";
	cin >> types_med;

	med_cost = phar.pick_meds(types_med);
		







	return 0;
}	
