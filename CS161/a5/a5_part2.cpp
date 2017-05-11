#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<fstream>


using namespace std;

int create_array(int ***arr, int rows, int columns);


int main(){
	int rows, columns;
	int **arr;

	cin >> rows;
	cin >> columns;
	
	create_array(&arr, rows, columns);
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < rows; j++) {
			cin >> arr[i][j];
			cout << arr[i][j] << "  ";
		}
	cout << endl;
	}


	return 0;

}


int create_array(int ***arr, int rows, int columns) {
	*arr = new int*[rows];
	
	for(int i = 0; i < rows; i++){
		(*arr)[i] = new int[columns];
	}
}
