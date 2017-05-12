#include<iostream>
#include<string>
#include<stdlib.h>
#include<cstring>

using namespace std;

bool is_valid_dimensions(char* m, char* n) {
	for(int i = 0; i < strlen(m); i++){
		if(!(m[i] > '0' && m[i] <= '9')) {
			cout << "You entered an invalid dimension for rows. Enter a non-zero integer: ";
			cin >> m;
			return true;
		}	
	}
	for(int i = 0; i < strlen(n); i++){
		if(!(n[i] > '0' && n[i] <= '9')) {
			cout << "You entered an invalid dimension for columns. Enter a non-zero integer: ";
			cin >> n;
			return true;
		}
	
	}	

}
int main(int argc, char* argv[]) {
	bool success = 1;
	while(success){
		success = is_valid_dimensions(argv[1], argv[2]);
	}
	cout << "Arg 1: " << argv[1] << endl;
	cout << "Arg 2: " << argv[2] << endl;





	return 0;

}
