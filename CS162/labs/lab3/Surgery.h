#ifndef SURGERY_H
#define SURGERY_H
#include "./Surgery.h"
#include<string>
class Surgery {
	public:
		PatientAccount p;
		Surgery();	 //Questionable constructor

		void get_lobotomy() { return lobotomy; }   //Accessors
		void get_knee(){ return plastic_surgery; }
		void get_heart() { return open_heart; }
		void get_liposuction() { return liposuction; }
		void get_fracture() { return fracture; }
	
		friend PatientAccount set_surg_charges(string);	

	private:
		float lobotomy;
		float knee;
		float open_heart;
		float liposuction;
		float fracture;







};





#endif
