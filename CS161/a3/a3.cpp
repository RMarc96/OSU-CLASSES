/**********************************************************************
 * Filename: Assignment 3 - Decomposition/Functions
 * Author: Ronald Salinas
 * Date: 8 February 2015
 * Description: Converts characters to binary and binary to characters
 * Input: String of characters and string of binary set(s)
 * Output: Binary set(s) and string of characters
 * ********************************************************************/


#include<iostream>
#include<cmath>
#include<sstream>
#include<string>

using namespace std;

int main();  //Declare main function.

/***********************************************************
 * Function: Get user input
 * Descrition: Prompts user for characters and binary
 * Parameters: String line, string binary
 * Pre-conditions: -
 * Post-conditions: Assigns values to variables line and binary
 * ***********************************************************/

void get_input(string &line, string &binary) {
	cout << "Enter a string of characters: ";
	cin >> line;
	cout << "Enter a string of binary: ";
	cin >> binary;

	return;
}


/*************************************************************************
 * Function: ASCII Characters to binary
 * Description: Takes each character's decimal in a string and converts to binary
 * Parameters: String line
 * Pre-conditions: -
 * Post-conditions: -
 * ************************************************************************/

int ascii_to_bin(string &line) {
	cout << "Your string in binary: ";
	for(int x = 0; x<line.length(); x++) {
		int value = int(line.at(x));
		for(int y = 7; y >= 0; y--) {	
			if(value / int(pow(2,y))) {
				value = value-int(pow(2,y));
				cout << 1;
			}
			else cout << 0;
		}
	}
	cout << endl;
}

/********************************************************************
 * Function: Binary to ASCII Characters
 * Description: Goes through sets of binary and converts to character
 * Parameters: String of binary
 * Pre-conditions: Binary may be bad (not in octets, has non-binary numbers, etc.)
 * Post-conditions: If bad, new binary will be reprompted
 * *****************************************************************/

int bin_to_ascii(string &binary) {
	cout << "Your binary in characters: ";
	for(int z = 0; z<binary.length(); z+= 8) {
		int sum = 0;
		for(int b = 0, a = 7; b <= 7, a >= 0; b++, a--) {	
			if(binary.at(z+b) == '1') sum = sum+pow(2,a);
			else if(binary.at(z+b) == '0') sum = sum + 0;
			}
		if(sum >= 128) {
			cout << "   ERROR - Can't support extended ASCII characters. Try again." << endl;
			main();
		}
		else{ cout << char(sum);}	
	}
}	

/******************************************************
 * Function: Check binary values
 * Description: Checks for unsupported binary conversions
 * Parameters: string binary
 * Pre-conditions: Binary may be bad
 * Post-conditions: Binary will be good
 * *****************************************************/


void check_bin_values(string &binary) {
	for(int d = 0; d<binary.length(); d++) {
		while(binary.at(d) != '0' && binary.at(d) != '1'){
			cout << "Invalid binary values or length amount." << endl << "Enter a string of binary: ";
			cin >> binary;			
		}
	}
	while(binary.length()%8 != 0) {
		cout << "Invalid binary values or length amount." << endl << "Enter a string of bianry values: ";
		cin >> binary;
	}
	return;
}

/**********************************************
 * Function: Main
 * Description: Calls other functions
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * **********************************************/

int main() {
	string line, binary, value;
	get_input(line, binary);
	check_bin_values(binary);
	ascii_to_bin(line);
	bin_to_ascii(binary);
	cout << endl;
	return 0;
}
