#include "./Patient.h"
#include<iostream>
#include<string>
#include<stdlib.h>


using namespace std;

PatientAccount::PatientAccount() {
	charges = 0.0;
	days_spent = 0;
	daily_rate = 2.00;
}


PatientAccount::~PatientAccount() {}


void set_charges(float total_charges) {
	charges += total_charges;
}

void set_days(int total_days) {
	days = total_days;
}


