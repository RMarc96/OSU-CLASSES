/****************************************
 * Filename: [a1.cpp] Assignment 1 - Macros & Character Converter
 * Author: Ronald Salinas
 * Date: 16 January 2015
 * Decription: Calculates max's and min's of signed and unsigned of  int, long, and short data types. Also converts a characters to binary, decimal, and hexadecimal.
 * Input: A single character
 * Output: Character in values of binary, decimal, and hexadecimal
 * ***************************************/

#include<iostream>
#include<climits>
#include<cmath>

using namespace std;

/*************************************
 * Function: Main function
 * Description: Outputs raw calculations for int, short, and long, outputs macros; prompts user for a character and converts to dec,hex,and bin
 * Parameters: -
 * Pre-conditions: Input must not be empty
 * Post-conditions: Outputs are integers, hex conversion may contain letters
 *************************************/
main()	{
	cout << "\nInt max (unsigned): " << (unsigned int)pow(2,sizeof(int)*8) - 1 << endl;
	cout << "\t\tCheck: " << UINT_MAX << endl; 
	
	cout << "Int min (unsigned): " << 0 << "\n" << endl;
	
	cout << "Int max (signed): " << (signed int)pow(2,sizeof(int)*8 - 1) -1 << endl;
	cout << "\t\tCheck: " << INT_MAX << endl;

	cout << "Int min (signed): " << -(signed int)pow(2,sizeof(int)*8 - 1) << endl;
	cout << "\t\tCheck: " << INT_MIN << "\n" << endl;

	cout << "Short max (unsigned): " << (unsigned short)pow(2,sizeof(short)*8-2)*2*2-1 << endl;
	cout << "\t\tCheck: " << USHRT_MAX << endl;
		
	cout << "Short min (unsigned): " << 0 << "\n" << endl;

	cout << "Short max (signed): " << ((signed short)pow(2,sizeof(short)*8-2)-1)*2+1 << endl;
	cout << "\t\tCheck: " << SHRT_MAX << endl;

	cout << "Short min (signed): " << -((signed short)pow(2,sizeof(short)*8-2)*2) << endl;
	cout << "\t\tCheck: " << SHRT_MIN << "\n" << endl;

	cout << "Long max (unsigned): " << (unsigned long)pow(2,sizeof(long)*4) - 1 << endl;
	cout << "\t\tCheck: " << ULONG_MAX << endl;

	cout << "Long min (unsigned): " << 0 << "\n" << endl;
	
	cout << "Long max (signed): " << (((long)pow(2,sizeof(long)*4-2)-1)*2-1) << endl;
	cout << "\t\tCheck: " << LONG_MAX << endl;		//What's going on here?
	
	cout << "Long min (signed): " << -(((long)pow(2,sizeof(long)*4-2)-1)*2) << endl;
	cout << "\t\tCheck: " << LONG_MIN << "\n" << endl;	//Here too.

/*
 * This next part is the character converter.
 * This will first output the character you entered,
 * then will convert it to a decimal and will "convert" that to binary
 * by marking each bit within a byte accordingly.
 * Will then output decimal value and hexadecimal.
 */	

	char character;

	cout << " LE CHARACTER CONVERTER " << endl;
	cout << "Enter a single random character: ";
	cin >> character;
	
	cout << "You entered: " << character << endl;
	cout << "Your character's binary value: ";

	int num = int(character);

	

	if(num / int(pow(2,7))) {
		num = num%int(pow(2,7));
		cout << 1;
		}
	else cout << 0;
	
	if(num / int(pow(2,6))) {
		num = num%int(pow(2,6));
		cout << 1;
		}
	else cout << 0;
	
	if(num / int(pow(2,5))) {
		num = num%int(pow(2,5));
		cout << 1;
		}
	else cout << 0;
	
	if(num / int(pow(2,4))) {
		num = num%int(pow(2,4));
		cout << 1;
		}
	else cout << 0;

	if(num / int(pow(2,3))) {
		num = num%int(pow(2,3));
		cout << 1;
		}
	else cout << 0;

	if(num / int(pow(2,2))) {
		num = num%int(pow(2,2));
		cout << 1;
		}
	else cout << 0;
	
	if(num / int(pow(2,1))) {
		num = num%int(pow(2,1));
		cout << 1;
		}
	else cout << 0;
	
	if(num / int(pow(2,0))) {
		num = num%int(pow(2,0));
		cout << 1;
		}
	else cout << 0;



	cout << endl << "Your character's decimal value: " << int(character) << endl;
	cout << "Your character's hexadecimal value: " << hex << int(character) << endl;



	return 0;

}
