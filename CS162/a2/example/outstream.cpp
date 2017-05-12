#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

int main() {

	ofstream outFile;

	outFile.open("sample");

	outFile << "First Number: " << 5 << endl;

	outFile.close();





	return 0;
}
