#ifndef RPS_CLASS_H
#define RPS_CLASS_H
#include<string>

using namespace std;

class Tool {
	public:
		Tool(); // Default constructor	
		Tool(int); //Non-default modifies 'strength'

		virtual	char get_type() { return type; }	
		int get_strength() { return strength; }
		void setStrength(int);
		void set_type(char);
	private:
		int strength;
		char type;


};


class Rock: public Tool{
	public:
		Rock();
		Rock(int);
		void set_type(char);
		char get_rock_type() { return type; }
		int get_r_strength() { return strength; }
	

	private:
		int strength;
		char type;



};


class Paper: public Tool{
	public:
		Paper();
		Paper(int);
		void set_type(char);
		char get_paper_type() { return type; }

		int get_p_strength() { return strength; }

	private:
		int strength;
		char type;

};


class Scissors: public Tool{
	public:
		Scissors();
		Scissors(int);
		void set_type(char);
		char get_scissors_type() { return type; }

		int get_s_strength() { return strength; }
			

	private:
		int strength;
		char type;

};







#endif
