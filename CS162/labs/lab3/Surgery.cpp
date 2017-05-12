#include"./Surgery.h"
#include<iostream>
#include<string>


using namespace std;


Surgery::Surgery() {

	lobotomy = 49.99;
	knee = 39.99;
	heart = 29.99;
	liposuction = 11.99;
	fracture = 0.99;


}

void PatientAccount::set_surg_charges(string surg_type) {
	if(surg_type == "lobotomy")
		charges += 49.99;
	else if(surg_type == "knee")
		charges += 39.99;
	else if(surg_type == "heart")
		charges += 29.99;
	else if(surg_type == "liposuction")
		charges += 19.99;
	else if(surg_type == "fracture")
		charges += 0.99;
	else charges += 0.0;
}


