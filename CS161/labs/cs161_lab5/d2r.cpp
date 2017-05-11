#include<iostream>
using namespace std;

// I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
int get_input(int &decimal), check_one(int &decimal), check_two(int &decimal), check_three(int &decimal), check_four(int &decimal);

void convert(int &decimal);

int get_input(int &decimal) {
	cout << "Enter an integer: ";
	cin >> decimal;
	
	cout << "You entered: " << decimal << endl;

	return decimal;
}

int main() {
	int decimal;

	get_input(decimal);
	cout << "Your integer in roman numerals: ";
	check_one(decimal);
	check_two(decimal);
	check_three(decimal);
	check_four(decimal);
	cout << endl;
	return 0;
}


int check_one(int &decimal) {	
	while(decimal >= 1000) {
		decimal = decimal - 1000;
		cout << "M";
	}
	while(decimal >= 900) {
		decimal = decimal - 900;
		cout << "CM";
	}
	while(decimal >= 500) {
		decimal = decimal - 500;
		cout << "D";
	}
	return decimal;
}

int check_two(int &decimal) {
	while(decimal >= 400) {
		decimal = decimal - 400;
		cout << "CD";
	}
	while(decimal >= 100) {
		decimal = decimal - 100;
		cout << "C";
	}
	while(decimal >= 90) {
		decimal = decimal - 90;
		cout << "XC";
	}
	return decimal;
}

int check_three(int &decimal) {
	while(decimal >= 50) {
		decimal = decimal - 50;
		cout << "L";
	}
	while(decimal >= 40) {
		decimal = decimal - 40;
		cout << "XL";
	}
	while(decimal >= 10) {	
		decimal = decimal - 10;
		cout << "X";
	}

	return decimal;
}

int check_four(int &decimal) {
	while(decimal >= 9) {
		decimal = decimal - 9;
		cout << "IX";
	}
	while(decimal >= 5) {
		decimal = decimal - 5;
		cout << "V";
	}
	while(decimal >= 4) {
		decimal = decimal - 4;
		cout << "IV";
	}
	while(decimal >= 1) {
		decimal = decimal - 1;
		cout << "I";
	}
	return decimal;


}
