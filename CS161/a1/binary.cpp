#include<iostream>
#include<cmath>

using namespace std;

main() {

	char character;

	cout << "Enter a single random character: ";
	cin >> character;

	cout << "You entered: " << character << endl;
	cout << "Your character's binary value: " << endl;

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

	
	if(num / int(pow(2,5)))	{
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
		

	
	cout << "\n" << "Your character's ASCII decimal value: " << int(character) << endl;
	cout << "Your character's ASCII hexadecimal value: " << hex << int(character) << endl;


	return 0;


}

