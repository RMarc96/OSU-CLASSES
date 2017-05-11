
/*********************************************************
 * Program Filename: Assignment 2
 * Author: Ronald Salinas
 * Date: 24 January 2015
 * Description: Converts user's entered string to binary and user's binary to string
 * Input: String of characters (1 or more), binary numbers
 * Output: Binary numbers, string of characters
 * ********************************************************/


#include<iostream>
#include<string>
#include<cmath>
#include<sstream>

using namespace std;

/***********************************************************
 * Function: Main function
 * Description: Asks user for random characters and binary numbers, converts to binary and decimal (then to string)
 * Parameters: -
 * Input: Strings of characters and binaries
 * Output: Binary values and string values
 * **********************************************************/



main() {
	string line;
	
	cout << "Enter a random string of characters: ";
	getline(cin, line);
	

	cout << "You entered: " << line << endl;
	cout << "Your string in binary is: ";
	
	for(int x = 0; x<line.length(); x++) {
		int value = int(line.at(x));
		
		if(value / int(pow(2,7))) {
			value = value-int(pow(2,7));
			cout << 1;
			}	
		else cout << 0;			
	
		
		if(value / int(pow(2,6))) {
			value = value-int(pow(2,6));
			cout << 1;
			}
		else cout << 0;

		
		if(value / int(pow(2,5))) {
			value = value-int(pow(2,5));
			cout << 1;
			}
		else cout << 0;
	
	
		if(value / int(pow(2,4))) {
			value = value-int(pow(2,4));
			cout << 1;
			}
		else cout << 0;
		
			
		if(value / int(pow(2,3))) {
			value = value-int(pow(2,3));
			cout << 1;
			}
		else cout << 0;
		
		
		if(value / int(pow(2,2))) {
			value = value-int(pow(2,2));
			cout << 1;
			}
		else cout << 0;

		
		if(value / int(pow(2,1))) {
			value = value-int(pow(2,1));
			cout << 1;
			}
		else cout << 0;

		
		if(value / int(pow(2,0))) {
			value = value-int(pow(2,0));
			cout << 1 << " ";
			}
		else cout << 0 << " ";
	}
	string binary;
	
	cout << "\nEnter a string of binary values: ";
	cin >> binary;
	
	for(int y = 0; y<binary.length(); y++) {
		while(binary.at(y) != '0' && binary.at(y) != '1'){
			cout << "Only enter 1's and 0's. " << endl;
			cout << "Enter a string of binary values: ";
			cin >> binary;
			}
		}		
	while(binary.length()%8 != 0) {
		cout << "Incomplete binary lengths." << endl;
		cout << "Enter a string of binary values: ";
		cin >> binary;
		}

	cout << "You entered: " << binary << endl;
		
	cout << "Your binary in a string of characters: ";
	
	//CONVERTING A BINARY TO A DECIMAL TO CHAR
	//"binary" string is entered
	//Cycle through each bit to add corresponding size
	for(unsigned int i = 0; i <binary.length(); i += 8) {
		int num7, num6, num5, num4, num3, num2, num1, num0, num_total;
		
		num_total = 0;

		if(binary.at(i) == '1') num7 = pow(2,7);
		else if(binary.at(i) == '0') num7 = 0;

		
		if(binary.at(1+i) == '1') num6 = pow(2,6);
		else if(binary.at(1+i) == '0') num6 = 0;
		
		
		if(binary.at(2+i) == '1') num5 = pow(2,5);
		else if(binary.at(2+i) == '0') num5 = 0;
		
		
		if(binary.at(3+i) == '1') num4 = pow(2,4);
		else if(binary.at(3+i) == '0') num4 = 0;

		
		if(binary.at(4+i) == '1') num3 = pow(2,3);
		else if(binary.at(4+i) == '0') num3 = 0;

		
		if(binary.at(5+i) == '1') num2 = pow(2,2);
		else if(binary.at(5+i) == '0') num2 = 0;

		
		if(binary.at(6+i) == '1') num1 = pow(2,1);
		else if(binary.at(6+i) == '0') num1 = 0;

		if(binary.at(7+i) == '1') num0 = pow(2,0);
		else if(binary.at(7+i) == '0') num0 = 0;
	

		num_total = num7 + num6 + num5 + num4 + num3 + num2 + num1 + num0;

		cout << (char)num_total;
	}


	cout << endl;
		

	return 0;
	
}
