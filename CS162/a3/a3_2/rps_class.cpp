#include "./rps_class.h"
#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;
/**************************************************************
 * Functions: Tool class constructors and mutators
 * Descriptions: Sets up base class Tool
 * Parameters: Int for strength mutator, char for type mutator
 * Pre-conditions: Will be constructed from child classes
 * Post-conditions: -
 * ************************************************************/

Tool::Tool() {
	strength = 1;
	type = NULL;	//NULL as default?
	

}


Tool::Tool(int str) {
	strength = str;
	type = NULL; 	//Rock as default?
}


void Tool::setStrength(int str) {
	strength = str;
}
void Tool::set_type(char t) {
	type = t;
}


/***************************************************************
 * Functions: Rock class constructors, mutators, and accessors
 * Descriptions: Sets up derived Rock class
 * Parameters: int for nondefault and char for type mutator
 * Pre-conditions: Tool class must be constructed first
 * Post-conditions: Class has proper values
 * *************************************************************/

Rock::Rock(): Tool() {
	strength = 1;
	type = 'r';

}

Rock::Rock(int str): Tool() {
	strength = str;
	type = 'r';
}

void Rock::set_type(char t) {
	type = t;
} 

/***************************************************************
 * Functions: Paper class constructors, mutators, and accessors
 * Descriptions: Sets up derived Paper class
 * Parameters: int for nondefault and char for type mutator
 * Pre-conditions: Tool class must be constructed first
 * Post-conditions: Class has proper values
 * *************************************************************/

Paper::Paper(): Tool() {
	strength = 1;
	type = 'p';
}


Paper::Paper(int str): Tool() {
	strength = str;
	type = 'p';
}
void Paper::set_type(char t) {
	type = t;
}
/***************************************************************
 * Functions: Scissors class constructors, mutators, and accessors
 * Descriptions: Sets up derived Scissors class
 * Parameters: int for nondefault and char for type mutator
 * Pre-conditions: Tool class must be constructed first
 * Post-conditions: Class has proper values
 * *************************************************************/

Scissors::Scissors(): Tool() {
	strength = 1;
	type = 's';
	
}

Scissors::Scissors(int str): Tool() {
	strength = str;
	type = 's';
}
void Scissors::set_type(char t) {
	type = t;
}	
