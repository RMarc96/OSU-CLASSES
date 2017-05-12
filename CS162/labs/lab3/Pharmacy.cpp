#include "./Pharmacy.h"
#include<iostream>
#include<string>

using namespace std;


Pharmacy::Pharmacy() {
	antibiotics = 5.00;
	xanax = 4.00;
	lollipops = 1000.00;
	placebo = 2.99;
	love = 0.99;

}

Pharmacy::~Pharmacy() {};


//PatientAccount::set_charges(float med_costs) {
	

float pick_meds(int med_types) {
	float med_costs = 0;
	cout << "You said " << med_types << " types of medication were taken." << endl;
	cout << "Enter the number for the type of medication taken." << endl;
	cout << "Choices\n1 - antibiotics\n2 - xanax\n3 - lollipops\n4 - placebo\n5 - love " << endl;

	for(int i = 0; i < med_types; i++) {
		int choice = -1;
		cout << "Med " << i+1 << ": ";
		cin >> choice;
	
		if(choice == 1) med_costs += get_antibiotics();
		else if(choice == 2) med_costs += get_xanax();
		else if(choice == 3) med_costs += get_lollipops();
		else if(choice == 4) med_costs += get_placebo();
		else if(choice == 5) med_costs += get_love();
	}
	return med_costs;
}

