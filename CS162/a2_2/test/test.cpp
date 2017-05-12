#include<iostream>
#include<fstream>
#include<string>


using namespace std;

int main() {
	string search;
	int offset;
	string line;
		
	ifstream MyFile;
	
	MyFile.open("names.txt");

	cout << "Type the name you want to seatch: ";
	getline(cin,search);

	if(MyFile.is_open()) {
		while(!MyFile.eof()) {
			getline(MyFile, line);
			if ((offset = line.find(search, 0)) != string::npos) {
				cout << "The word '" << search << "' was found." << endl;	
				MyFile.close();
				break;
			}
		}
	}
	if(input.fail()) {
		cout << "Could not open file. " << endl;
	}
	return 0;

}

