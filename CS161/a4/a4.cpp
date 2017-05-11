/******************************************************************************
 * Filename: Assignment 4 ~ Command-line Arguments
 * Author: Ronald Salinas
 * Date: 19 February 2015
 * Description: Converts C-style string to binary and binary to string
 * Input: "-a" followed by a string of characters or "-b" followed by binaries
 * Output: ASCII chars become binary and/or binaries become ASCII chars
 * ****************************************************************************/

#include<iostream>
#include<cmath>
#include<string>
#include<string.h>
#include<stdlib.h>


using namespace std;

int main(int argc, char* argv[]);  //Declare main function.
int check_args(int &argc, char* argv[]);

/*************************************************************
 * Function: ASCII to Binary
 * Description: Converts C-Style string in argv to binary
 * Parameters: i, address of argc, argv
 * Pre-conditions: ASCII chars must be within English language
 * Post-conditions: -
 * ************************************************************/

int ascii_to_bin(int &i, int &argc, char* argv[]) {
	cout << "Your string in binary: ";
	
	for(int x = 0; x < strlen(argv[i+1]); x++) {
		int value = int(char(argv[i+1][x]));
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
 * Function: Binary to ASCII
 * Description: Converts a C-style string of "binaries" to ASCII characters
 * Parameters: i, address of argc, argv
 * Pre-conditions: Binaries must be good (checked by check_bin_values())
 * Post-conditions: ASCII char is within English language
 * ******************************************************************/

int bin_to_ascii(int i, int &argc, char* argv[]) {
	cout << "Your binary in characters: ";
	for(int z = 0; z < strlen(argv[i+1]); z+= 8) {
		int sum = 0;
		for(int b = 0, a = 7; b <= 7, a >= 0; b++, a--) {	
			if(char(argv[i+1][b+z]) == '1') sum = sum+pow(2,a);
			else if(char(argv[i+1][b+z]) == '0') sum = sum + 0;
			}
		if(sum >= 128) {
			cout << "   ERROR - Can't support extended ASCII characters. Try again." << endl;
			exit;

		}
		else{cout << char(sum);}	
	}
	cout << endl;
}	

/**********************************************************************
 * Function: Check binary values
 * Description: Checks if binaries are good. Terminates program if not.
 * Parameters: i, argv
 * Pre-conditions: Input could be good or bad
 * Post-conditions: Input will still be good, else program ends
 * ********************************************************************/

int check_bin_values(int i, char* argv[]) {
	for(int d = 0; d < strlen(argv[i+1]); d++) {
		if(argv[i+1][d] != '0' && argv[i+1][d] != '1') {
			cout << "ERROR: Invalid binary values or length amount. Try again." << endl;
			exit(0);
		}
	}
	if(strlen(argv[i+1])%8 != 0 ) {
		cout << "ERROR: Invalid binary values or length amount. Try again." << endl;
		exit(0);
	}
	

}

/***************************************************************************
 * Function: Check arguments
 * Description: Looks for '-a' or '-b' input. Terminates program if missing.
 * Parameters: Address of argc, argv
 * Pre-conditions: -
 * Post-conditions: -
 * *************************************************************************/

int check_args(int &argc, char* argv[]){
	for(int j = 0; j < argc - 1; j++){
		if(argv[j][0] == '-' && argv[j][1] == 'a' && strlen(argv[j]) == 2) return 0;
		else if(argv[j][0] == '-' && argv[j][1] == 'b' && strlen(argv[j]) == 2) return 0;
	}
	cout << "Input of '-a' for ASCII conversion or '-b' for binary conversion was missing or invalid entry.\nTry again." << endl;
	exit(0);
}

/*************************************************************************
 * Function: Main
 * Description: Gets command line input (if there are any) and does magic
 * Parameters: argc, argv[]
 * Pre-conditions: -
 * Post-conditions: - 
 * ************************************************************************/

int main(int argc, char* argv[]) {
	check_args(argc, argv);
	for(int i = 0; i < argc - 1; i++){
		if(argv[i][0] == '-' && argv[i][1] == 'a' && strlen(argv[i]) == 2) ascii_to_bin(i, argc, argv);
		else if(argv[i][0] == '-' && argv[i][1] == 'b' && strlen(argv[i]) == 2) {
			check_bin_values(i, argv);
			bin_to_ascii(i, argc, argv);
		}
	}
	
	return 0;
}
