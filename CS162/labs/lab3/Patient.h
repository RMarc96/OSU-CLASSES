#ifndef PATIENT_ACCOUNT_H
#define PATIENT_ACCOUNT_H

#include "./Patient.h"
class PatientAccount {
	public:
		PatientAccount();		//Constructors

		float get_charges() {return charges;} //Accessors
		int get_days() {return days;}
		int get_rate() {return daily_rate};

		void set_charges(float); //Mutators
		void set_days(int);
	
		~Patient();
	private:
		float charges;
		int days_spent;
		int daily_rate;

};






#endif
