#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<string>
#include<fstream>

#define DASH_TEST_LEN 5
using namespace std;

void get_input(int &r, int &c);
void create_array(int ***arr, int rows, int columns);
void randomize(int ***arr, int rows, int columns);
void check_test(int argc, char* argv[], int &rows, int &columns, int &test);
void use_file_array(int ***arr, int rows, int columns);
int find_greatest_product(int ***arr, int rows, int columns);

int main(int argc, char* argv[]) {
	int **arr;
	int rows, columns, test;

	check_test(argc, argv, rows, columns, test);
	

	create_array(&arr, rows, columns);
	
	if(test == 0) randomize(&arr, rows, columns);
	else if(test == 1) use_file_array(&arr, rows, columns);

	find_greatest_product(&arr, rows, columns);

	return 0;


}

void use_file_array(int ***arr, int rows, int columns){
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < rows; j++) {
			cin >> (*arr)[i][j];
			cout << (*arr)[i][j] << "\t";
		}
	cout << endl;
	}
}

void check_test(int argc, char* argv[], int &rows, int &columns, int &test) {
	int i = 0;
	while(argv[i] != NULL){
		if(argv[i][0] == '-' && argv[i][1] == 't' && argv[i][2] == 'e' && argv[i][3] == 's' && argv[i][4] == 't' && strlen(argv[i]) == DASH_TEST_LEN){
			test = 1;
			cin >> rows;
			cin >> columns;
			break;
		}
	
		i++;
	}	
	if(argv[i] == NULL){
		test = 0;
		get_input(rows, columns);
	}
	return;
}



void randomize(int ***arr, int rows, int columns) {
	srand(time(NULL));
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++) {
			(*arr)[i][j] = rand() % 50 + 1;	
			cout << (*arr)[i][j] << "\t";
		}
	cout << endl;
	}
}
void create_array(int ***arr, int rows, int columns) {
	*arr = new int*[rows];

	for(int i = 0; i < rows; i++)
		(*arr)[i]= new int[columns];
			
}


void get_input(int &r, int &c) {
	cout << "Enter rows: ";
	cin >> r;

	cout << "Enter columns: ";
	cin >> c;

}

int find_greatest_product(int ***arr, int rows, int columns){
	int largest = 0, row_loc, col_loc;
	int r, c;
	string shape;
//VERTICAL LINE
	for(r = 0; r < rows - 3; r++) {
		for(c = 0; c < columns; c++) {
			if(largest < ((*arr)[r][c]) * ((*arr)[r+1][c]) * ((*arr)[r+2][c]) * ((*arr)[r+3][c])) {
				
				largest = ((*arr)[r][c]) * ((*arr)[r+1][c]) * ((*arr)[r+2][c]) * ((*arr)[r+3][c]);
				row_loc = r;
				col_loc = c;
				shape = "Vertical line";
			}
		}
	}
//HORIZONTAL LINE
	for(c = 0; c < columns - 3; c++) {
		for(r = 0; r < rows; r++) {
			if(largest < ((*arr)[r][c]) * ((*arr)[r][c+1]) * ((*arr)[r][c+2]) * ((*arr)[r][c+3])) {

				largest = ((*arr)[r][c]) * ((*arr)[r][c+1]) * ((*arr)[r][c+2]) * ((*arr)[r][c+3]);
				row_loc = r;
				col_loc = c;
				shape = "Horizontal line";
			}	
		}
	}
//"POSITIVE" DIAGONAL
	for(r = 0; r < rows - 3; r++) {
		for(c = 0; c < columns - 3; c++) {
			if(largest < ((*arr)[r][c])*((*arr)[r+1][c+1])*((*arr)[r+2][c+2])*((*arr)[r+3][c+3])) {
				largest = ((*arr)[r][c])*((*arr)[r+1][c+1])*((*arr)[r+2][c+2])*((*arr)[r+3][c+3]);
				row_loc = r;
				col_loc = c;
				shape = "Diagonal v1";
			}
		}
	}	
//"NEGATIVE" DIAGONAL
	for(r = rows - 1; r > 3; r--) {
		for(c = 0; c < columns - 3; c++) {
			if(largest < ((*arr)[r][c])*((*arr)[r-1][c+1])*((*arr)[r-2][c+2])*((*arr)[r-3][c+3])) {
				largest = ((*arr)[r][c])*((*arr)[r-1][c+1])*((*arr)[r-2][c+2])*((*arr)[r-3][c+3]);
				row_loc = r;
				col_loc = c;
				shape = "Diagonal v2";
			}
		}
	}
//SQUARE
	for(r = 0; r < rows - 1; r++) {
		for(c = 0; c < columns - 1; c++) {
			if(largest < ((*arr)[r][c]) * ((*arr)[r][c+1]) * ((*arr)[r+1][c]) * ((*arr)[r+1][c+1])) {
				
				largest = ((*arr)[r][c]) * ((*arr)[r][c+1]) * ((*arr)[r+1][c]) * ((*arr)[r+1][c+1]);
				row_loc = r;
				col_loc = c;
				shape = "Square";
			}
		}
	}

	cout << "Largest product: " << largest << endl;
	cout << "Location - Row " << row_loc + 1 << " Col " << col_loc + 1 << endl;
	cout << "Shape: " << shape << endl;

}


int vertical_line(int &largest, int rows, int columns, int &row_loc, int &col_loc, string &shape) {
	//VERTICAL LINE
	for(int r = 0; r < rows - 3; r++) {
		for(c = 0; c < columns; c++) {
			if(largest < ((*arr)[r][c]) * ((*arr)[r+1][c]) * ((*arr)[r+2][c]) * ((*arr)[r+3][c])) {
				
				largest = ((*arr)[r][c]) * ((*arr)[r+1][c]) * ((*arr)[r+2][c]) * ((*arr)[r+3][c]);
				row_loc = r;
				col_loc = c;
				shape = "Vertical line";
			}
		}
	}


