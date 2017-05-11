#include<iostream>
#include<string>

using namespace std;

int main() {
	string roman;
	int num = 0, prev = 0;
	
	cout << "Enter a roman numeral: ";
	cin >> roman;
	
	for(int i = 0; i<roman.length(); i++){
			if(roman[i] == 'M'){
				if(prev < 1000){
					num += 1000 - (2*prev);
					prev = 1000;
				}
				else num += 1000;
			}
	
			if(roman[i] == 'D'){
				if(prev < 500){
					num += 500 - (2*prev);
					prev = 500;
				}
				else num += 500;
			}
				
			if(roman[i] == 'C'){
				if(prev < 100){
					num += 100 - (2*prev);
					prev = 100;
				}
				else num += 100;
			}
			
			if(roman[i] == 'L'){
				if(prev < 50){
					num += 50 - (2*prev);
					prev = 50;
				}
				else num += 50;
			}
		
			if(roman[i] == 'X'){
				if(prev < 10){
					num += 10 - (2*prev);
					prev = 10;
				}
				else num += 10;
			}

			if(roman[i] == 'V'){
				if(prev < 5){
					num += 5 - (2*prev);
					prev = 5;
				}
				else num += 5;
			}
			if(roman[i] == 'I'){
				if(roman[i+1] == 'V'){
					num += 4;
					prev = 5;
					i += 1;
				}
				else if(roman[i+1] == 'X'){
					num += 9;
					prev = 10;
					i += 1;
				}
				else num += 1;
			}
	}	
cout << "Your roman numeral in decimal is: " << num << endl;

return 0;
}
