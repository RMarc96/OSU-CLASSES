/********************************************************************************************
 * Filename: Assignment 5 ~ Greatest Product of 4 Numbers
 * Author: Ronald M. Salinas
 * Date 5 March 2015
 * Description: Makes a matrix (from file or prompt) of numbers and finds greatest product
 * Input: Optional "-test" in command line
 * Output: Matrix, product, location, shape
 * ****************************************************************************************/

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
void vertical_line(int ***arr, int &largest, int rows, int columns, int &row_loc, int &col_loc, string &shape);
void square(int ***arr, int &largest, int rows, int columns, int &row_loc, int &col_loc, string &shape);
void diagonal_line_neg(int ***arr, int &largest, int rows, int columns, int &row_loc, int &col_loc, string &shape);
void diagonal_line_pos(int ***arr, int &largest, int rows, int columns, int &row_loc, int &col_loc, string &shape);
void horizontal_line(int ***arr, int &largest, int rows, int columns, int &row_loc, int &col_loc, string &shape);


/****************************************************************************************
 * Function: Main
 * Description: Does magic
 * Parameters: Arguments
 * Pre-conditions: -
 * Post-conditions: -
 * ****************************************************************************************/

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

/***********************************************************************************
 * Function: Use file array
 * Description: If indicated, uses a file's matrix instead of generating one
 * Parameters: Row number, column number, **array
 * Pre-conditions: File must supply valid dimensions and matrix
 * Post-conditions: Matrix is still good
 * *********************************************************************************/

void use_file_array(int ***arr, int rows, int columns){
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < rows; j++) {
			cin >> (*arr)[i][j];
			cout << (*arr)[i][j] << "\t";
		}
	cout << endl;
	}
}

/***************************************************************************
 * Function: Check for -test
 * Description: Checks command line for argument '-test'
 * Parameters: Argc, argv, address rows, address columns, address verifier
 * Pre-conditions: Nothing went wrong so far with the values
 * Post-conditions: Rows and columns will be good
 * *************************************************************************/

void check_test(int argc, char* argv[], int &rows, int &columns, int &test) {
	if(argc > 1){
		if(argv[1][0] == '-' && argv[1][1] == 't' && argv[1][2] == 'e' && argv[1][3] == 's' && argv[1][4] == 't' && strlen(argv[1]) == DASH_TEST_LEN){
			cin >> rows;
			cin >> columns;
			test = 1;
			return;
		}
	}	
	test = 0;
	cout << "'-test' argument not given or you did something wrong. Enter something after prompt." << endl;
	get_input(rows, columns);

}	

/*************************************************************************
 * Function: Randomize Matrix
 * Description: Randomizes values within a matrix (if no -test)
 * Parameters: array, rows, columns
 * Pre-conditions: Rows and columns create a valid matrix
 * Post-conditions: -
 * ************************************************************************/

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

/***************************************************************
 * Function: Create array
 * Description: Makes matrix from given dimensions
 * Pre-conditions: Rows and columns must be good
 * Post-conditions: Matrix will be filled with garbage
 * ************************************************************/

void create_array(int ***arr, int rows, int columns) {
	*arr = new int*[rows];

	for(int i = 0; i < rows; i++)
		(*arr)[i]= new int[columns];
			
}

/***********************************************************
 * Function: Get input
 * Description: Prompts user for dimensions (if no -test)
 * Parameters: r, c
 * Pre-conditions: Rows and columns must be good ints
 * Post-conditions: -
 * ********************************************************/

void get_input(int &r, int &c) {
	cout << "Enter rows: ";
	cin >> r;

	cout << "Enter columns: ";
	cin >> c;
}

/*********************************************************************************
 * Function: Find greates product
 * Description: Looks for largest product of a sequence of four numbers in matrix
 * Paramters: array, rows, columns
 * Pre-conditions: -
 * Post-conditions: -
 * *******************************************************************************/

int find_greatest_product(int ***arr, int rows, int columns){
	int largest = 0, row_loc, col_loc, r, c;
	string shape;
	

	if(rows < 4 && columns < 4) square(arr, largest, rows, columns, row_loc, col_loc, shape);
	else {
		vertical_line(arr, largest, rows, columns, row_loc, col_loc, shape);
		horizontal_line(arr, largest, rows, columns, row_loc, col_loc, shape);
		diagonal_line_pos(arr, largest, rows, columns, row_loc, col_loc, shape);
		diagonal_line_neg(arr, largest, rows, columns, row_loc, col_loc, shape);
		square(arr, largest, rows, columns, row_loc, col_loc, shape);
	}

	cout << "Largest product: " << largest << "\tLocation - Row " << row_loc + 1 << " Col " << col_loc + 1 << "\t    Shape: " << shape << endl;

}

/*************************************************************************************************
 * Functions: Five shapes
 * Description: Checks a matrix for largest product of a sequence in a line, diagonal, or square
 * Parameters: array, largest product, rows, columns, bookmarks for rows and columns, shape
 * Pre-conditions: Nothing went wrong
 * Pre-conditions: Stuff looks good
 * ***********************************************************************************************/

void vertical_line(int ***arr, int &largest, int rows, int columns, int &row_loc, int &col_loc, string &shape) {
	//VERTICAL LINE
	for(int r = 0; r < rows - 3; r++) {
		for(int c = 0; c < columns; c++) {
			if(largest < ((*arr)[r][c]) * ((*arr)[r+1][c]) * ((*arr)[r+2][c]) * ((*arr)[r+3][c])) {
				
				largest = ((*arr)[r][c]) * ((*arr)[r+1][c]) * ((*arr)[r+2][c]) * ((*arr)[r+3][c]);
				row_loc = r;
				col_loc = c;
				shape = "Vertical line";
			}
		}
	}

}

void horizontal_line(int ***arr, int &largest, int rows, int columns, int &row_loc, int &col_loc, string &shape) {
	//HORIZONTAL LINE
	for(int c = 0; c < columns - 3; c++) {
		for(int r = 0; r < rows; r++) {
			if(largest < ((*arr)[r][c]) * ((*arr)[r][c+1]) * ((*arr)[r][c+2]) * ((*arr)[r][c+3])) {

				largest = ((*arr)[r][c]) * ((*arr)[r][c+1]) * ((*arr)[r][c+2]) * ((*arr)[r][c+3]);
				row_loc = r;
				col_loc = c;
				shape = "Horizontal line";
			}	
		}
	}	
}


void diagonal_line_pos(int ***arr, int &largest, int rows, int columns, int &row_loc, int &col_loc, string &shape) {
	//"POSITIVE" DIAGONAL
	for(int r = 0; r < rows - 3; r++) {
		for(int c = 0; c < columns - 3; c++) {
			if(largest < ((*arr)[r][c])*((*arr)[r+1][c+1])*((*arr)[r+2][c+2])*((*arr)[r+3][c+3])) {
				largest = ((*arr)[r][c])*((*arr)[r+1][c+1])*((*arr)[r+2][c+2])*((*arr)[r+3][c+3]);
				row_loc = r;
				col_loc = c;
				shape = "Diagonal";
			}
		}
	}
}







void diagonal_line_neg(int ***arr, int &largest, int rows, int columns, int &row_loc, int &col_loc, string &shape) {
	//"NEGATIVE" DIAGONAL
	for(int r = rows - 1; r > 3; r--) {
		for(int c = 0; c < columns - 3; c++) {
			if(largest < ((*arr)[r][c])*((*arr)[r-1][c+1])*((*arr)[r-2][c+2])*((*arr)[r-3][c+3])) {
				largest = ((*arr)[r][c])*((*arr)[r-1][c+1])*((*arr)[r-2][c+2])*((*arr)[r-3][c+3]);
				row_loc = r;
				col_loc = c;
				shape = "Diagonal";
			}
		}
	}
}

void square(int ***arr, int &largest, int rows, int columns, int &row_loc, int &col_loc, string &shape) {
	//SQUARE
	for(int r = 0; r < rows - 1; r++) {
		for(int c = 0; c < columns - 1; c++) {
			if(largest < ((*arr)[r][c]) * ((*arr)[r][c+1]) * ((*arr)[r+1][c]) * ((*arr)[r+1][c+1])) {
				
				largest = ((*arr)[r][c]) * ((*arr)[r][c+1]) * ((*arr)[r+1][c]) * ((*arr)[r+1][c+1]);
				row_loc = r;
				col_loc = c;
				shape = "Square";
			}
		}
	}
}
