#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {
	string strReplace = "HELLO";
	string strNew = "GOODBYE";
	
	ifstream filein("text.txt");
	ofstream fileout("text_temp.txt");
	
	if(!filein || !fileout) {
		cout << "Error opening files!" << endl;
		return 1;
	}

	string strTemp;
	
	while(filein >> strTemp) {
		if(strTemp == strReplace) {
			strTemp = strNew;
		}
		strTemp += "\n";
		fileout << strTemp;
	}
	remove("text.txt");
	rename("text_temp.txt", "text.txt");

	return 0;
}
