#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

int main() {

	ifstream inFile;
	inFile.open("./list");

	//Check for error
	if(inFile.fail()) {
		cerr << "Error Opening File" << endl;
		exit(1);
	}

	string item;
	

	int count = 0;

	//Read a file until you've reached the end
	while(!inFile.eof()) {
		inFile >> item;
		if(item == "orange")
			count++;	
	}

	inFile.close();
	cout << count-1 << " instances found." << endl;	
	return 0;
}
