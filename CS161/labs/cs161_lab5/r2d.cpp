#include<iostream>
#include<string>

using namespace std;

string get_input(string &roman), error(string &roman);
int check_M(string &roman, int &num, int &prev, int &j), check_D(string &roman, int &num, int &prev, int &j), check_L(string &roman, int &num, int &prev, int &j);
int check_X(string &roman, int &num, int &prev, int &j), check_V(string &roman, int &num, int &prev, int &j), check_I(string &roman, int &num, int &prev, int &j);
int check_C(string &roman, int &num, int &prev, int &j);
int convert(string &roman, int &num, int &prev, int &j);



 


int main(){
	string roman;
	int num = 0, prev = 0, j = 0;
	
	get_input(roman);
	convert(roman, num, prev, j);
	cout << "You entered: " << roman << endl;
	cout << roman << " in Arabic numbers is: " << num << endl;

	return 0;
}
string get_input(string &roman){
	cout << "Enter a roman numeral: ";
	cin >> roman;

	return roman;

}

string error(string &roman){
	for(int i = 0; i < roman.length(); i++){
		if(roman[i] != 'I' && roman[i] != 'V' && roman[i] != 'X' && roman[i] != 'L' && roman[i] != 'C' && roman[i] != 'D' && roman[i] != 'M'){
			cout << "Invalid entry." << endl;
			main();
		}
	}
	return roman;
}

int convert(string &roman, int &num, int &prev, int &j){
	for(j = 0; j<roman.length(); j++){
		check_M(roman, num, prev, j);
		check_D(roman, num, prev, j);
		check_C(roman, num, prev, j);
		check_L(roman, num, prev, j);
		check_X(roman, num, prev, j);
		check_V(roman, num, prev, j);
		check_I(roman, num, prev, j);
	}
	return num;
}

int check_M(string &roman, int &num, int &prev, int &j){
	if(roman[j] == 'M'){
		if(prev<1000){
			num += 1000 - (2*prev);
			prev = 1000;
		}
		else num += 1000;
	}
	return num, prev, j;
}

int check_D(string &roman, int &num, int &prev, int &j){
	if(roman[j] == 'D'){
		if(prev<500){
			num += 500 - (2*prev);
			prev = 500;
		}
		else num += 500;
	}
	return num, prev, j;
}	

int check_C(string &roman, int &num, int &prev, int &j){
	if(roman[j] == 'C'){
		if(prev<100){
			num += 100 - (2*prev);
			prev = 100;
		}
		else num += 100;
	}
	return num, prev, j;
}

int check_L(string &roman, int &num, int &prev, int &j){
	if(roman[j] == 'L'){
		if(prev<50){
			num += 50 - (2*prev);
			prev = 50;
		}
		else num += 50;
	}
	return num, prev, j;
}

int check_X(string &roman, int &num, int &prev, int &j){
	if(roman[j] == 'X'){
		if(prev<10){
			num += 10 - (2*prev);
			prev = 10;
		}
		else num += 10;
	}
	return num, prev, j;
}

int check_V(string &roman, int &num, int &prev, int &j){
	if(roman[j] == 'V'){
		if(prev<5){
			num += 5 - (2*prev);
			prev = 5;
		}
		else num += 5;
	}
	return num, prev, j;
}


int check_I(string &roman, int &num, int &prev, int &j){
	if(roman[j] == 'I'){
		if(roman[j+1] == 'V'){
			num += 4;
			prev = 5;
			j += 1;
		}
	else if(roman[j+1] == 'X'){
		num += 9;
		prev = 10;
		j += 1;
	}
	else num += 1;
	}
	return num, prev, j;
}

