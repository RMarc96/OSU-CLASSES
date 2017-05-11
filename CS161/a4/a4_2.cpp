#include<iostream>
#include<string>

using namespace std;

int main(int argc, char* argv[]){
	if(argc==1) cout << "Usage: ./program_name arg1" << endl;
	
	else{
		for(int i = 1; i < argc; i++){
			cout << argv[i] << endl;
		}
	}

		return 0;
}


