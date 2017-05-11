#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<cstdlib>

using namespace std;

// COMMAND LINE: [PROGRAM_NAME, ROWS, COLUMNS]
void get_input(int &rows, int &columns);
void generate(int rows, int columns);

int main(){
	int num, rows, columns;
	
	get_input(rows, columns);		
	
	generate(rows, columns);	
	
//	error(rows, columns);
	
//	create_array(rows, columns, arr);	

//	srand(time(NULL));
//	num = rand() % 50 + 1;

//	cout << num << endl;

	return 0;
}

void generate(int rows, int columns){
	int arr[0][];
	for(int i = 0; i < rows - 1; i++){
		srand(time(NULL));
		cout << "Row #" << i << ": ";
		for(int j = 0; j < columns - 1; j++){
			arr[i][j] = rand() % 50 + 1;
		}
	}
	cout << *arr;
}
void get_input(int &rows, int &columns) {
	cout << "Enter rows: ";
	cin >> rows;

	cout << "Enter columns: ";
	cin >> columns;

	
}

//void error(int rows, int columns) {
//	if(rows < 1 or rows > 50){
//		cout << "Out of boundaries." << endl;
//		exit(0);
//	}

//void create_array(int rows, int columns) {
//	arr[rows][columns];
	
//}

//void initialize_array(char* arr){
//	for(int i = 0; i < 






