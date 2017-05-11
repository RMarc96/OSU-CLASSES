/*************************************************************
 * Program Filename: C++ Basic Calculator
 * Author: Ronald Salinas
 * Date: 4 December 2014
 * Description: Computes a math operation between two numbers
 * Input: Operation type (+, -, /, *, **, %), real numbers
 * Output: A calculated number
 * ***********************************************************/

#include<iostream>
#include<cmath>
#include<string>

using namespace std;

/********************************************************************************************************************************
 * Function: Main function
 * Description: Asks and does operation for two numbers
 * Parameters: num1, num2, final, "operand", "repeat"
 * Pre-conditions: num1 and num2 are valid numbers (int or float), operand is a valid operation, repeat should either be "1" or "0"
 * Post-conditions: Operation between num1 and num2 is returned to variable final
 * ******************************************************************************************************************************/

int main() {
float num1, num2, final;
string operand, repeat;	

cout << "Enter an operator (+, -, *, /, **, or %): ";
cin >> operand;

cout << "Enter your first value: ";
cin >> num1;

cout << "Enter your second value: ";
cin >> num2;

/*Calculates sum of num1 and num2*/
if(operand == "+") 
	{					
	final = num1 + num2;
	cout << num1 << " + " << num2 << " = " << final << endl;
	}
/*Calculates difference between num1 and num2*/
else if(operand == "-")
	{
	final = num1 - num2;
	cout << num1 << " - " << num2 << " = " << final << endl;
	}
/*Calculates product of num1 and num2*/
else if(operand == "*")
	{
	final = num1 * num2;
	cout << num1 << " * " << num2 << " = " << final << endl;
	}
/*Calculates quotient of num1 and num2*/
else if(operand == "/")
	{
	final = num1 / num2;
	if(num2 == 0)
		{
		cout << "Undefined." << endl;	//If a 0 is entered as the denominator, "Undefined" is returned
		}
	else
		{
		cout << num1 << " / " << num2 << " = " << final << endl;
		}
	}
/*Exponentiates num1 with num2*/
else if(operand == "**")
	{
	if(num1 < 0 and num2 == 0.5){
		cout << "Non-real answer." << endl;  //Added an error for non-real answers
		}
	else{
	final = pow(num1, num2);
	cout << num1 << " ** " << num2 << " = " << final << endl;
	}
	}
/*Finds remainder of num1 from num2*/
else if(operand == "%")
	{
	final = fmod(num1,num2);
	cout << num1 << " % " << num2 << " = " << final << endl;
	}
/*Error message when pre-conditions not fulfilled*/
else
	{
	cout << "You did something wrong." << endl;
	}
/*Loops to beginning or terminates depending on input*/
while(repeat != "1" or repeat != "0")
	{
	cout << "Do you want to make another calculation? \n1-Yes   0-No: ";
	cin >> repeat;
	if(repeat == "1") {
		main();
		}
	else if(repeat == "0") {
		cout << "Goodbye!" << endl;
		break;
		}
	else{continue;} 	/*Continues loop until valid input received*/
	}
return 0;
}
