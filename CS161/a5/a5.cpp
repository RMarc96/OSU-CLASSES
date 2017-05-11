#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<cstdlib>

using namespace std;
void get_input(int &rows, int &columns);
int initialize_array(int *arr, int rows, int columns);
int create_array(int rows, int columns);

int main(){
	int num, rows, columns;
	int **arr;
	get_input(rows, columns);
	**arr = create_array(rows, columns);
	
//	cout << arr;

	return 0;

}

void get_input(int &rows, int &columns){
	cout << "Enter rows: ";
	cin >> rows;

	cout << "Enter columns: ";
	cin >> columns;

}

int create_array(int rows, int columns){
	int **a;
	a = new int *[rows];
	for(int i = 0; i < rows; i++)
		a[i] = new int[columns];
	return **a;	
	
}

//int initialize_array(int *arr, int rows, int columns){
//	for(int i = 0; i < rows; i++){
//		for(int j = 0; j < columns; j++){
//			arr[i][j] = 0;
		//	cout << 0 << "  ";
//		}
//	
//	}
//	cout << *arr;

//}
