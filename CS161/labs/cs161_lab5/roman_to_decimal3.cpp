#include<iostream>
#include<string>


using namespace std;
int convert(string &roman, int &decimal), single_convert(string &roman, int &decimal);

int main(){
	int decimal = 0;
	string roman;

	cout << "Enter a roman numeral: ";
	cin >> roman;

	if(roman.length() == 1){	
		single_convert(roman, decimal);	
	}
	else convert(roman, decimal);
	
	cout << "Your roman numeral in decimal is: " << decimal << endl;
	return 0;
}

int single_convert(string &roman, int &decimal){
	if(roman == "I"){
		decimal = 1;
	}
	return decimal;
}
int convert(string &roman, int &decimal){
	for(int i = 0; i < roman.length(); i += 2){
		if(roman[i] == 'I'){
			if(roman[i] != roman[i+1]){
				if(roman[i+1] == 'V'){
					decimal += 4;
				}
				if(roman[i+1] == 'X'){
					decimal += 9;
				} 
			}
		else decimal += 2;
		}

	}


	return decimal;
}	
