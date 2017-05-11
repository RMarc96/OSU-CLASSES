#include<iostream>
#include<string>

using namespace std;

main() {
	string message;
	
	cout << "Enter a message: ";
	cin >> message;

	cout << "Number of characters: " << message.length() << endl;
	
	for(int i=0; i<message.length(); i++) {
		cout << message.at(i) << endl;
		}
	return 0;
}
