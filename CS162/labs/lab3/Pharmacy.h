#ifndef PHARMACY_H
#define PHARMACY_H

#include "./Pharmacy.h"

class Pharmacy {
	public:
		Pharmacy(); //Constructor
		float pick_meds(int);
		
		void get_antibiotics() { return antibiotics; }
		void get_xanax() { return xanax; }
		void get_lollipops() { return lollipops; }
		void get_placebo() { return placebo; }
		void get_love() { return love; }

		void PatientAccount::set_charges(float); //Mutator

		~Pharmacy();

	private:
		float antibiotics;
		float xanax;
		float lollipops;
		float placebo;
		float love;




};












#endif
