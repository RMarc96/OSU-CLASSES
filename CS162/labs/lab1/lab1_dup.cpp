#include<iostream>
#include<cstring>
#include<stdlib.h>
#include "./mult_div.h"

using namespace std;

bool is_valid_dimensions(char* m, char* n){
	for(int i = 0; i < strlen(m); i++) {
		if(!(m[i] >= '0' && m[i] <= '9')) {
			cout << "You entered an invalid dimension for rows. Enter a non-zero integer: ";
			cin >> m;
			return true;
		}
	}
	for(int j = 0; j < strlen(n); j++) {
		if(!(n[j] >= '0' && n[j] <= '9')) {
			cout << "You entered an invalid dimension for columns. Enter a non-zero integer: ";
			cin >> n;
			return true;
		}
	}


}
mult_div_values** create_table(int m, int n) {
	mult_div_values** arr;
	
	arr = new mult_div_values*[m];
	
	for(int i = 0; i < m; i++)
		arr[i] = new mult_div_values[n];

	return arr;

}

void set_mult_values(mult_div_values **table, int m, int n) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			table[i][j].mult = (i+1)*(j+1);
		}
	}
}

void set_div_values(mult_div_values **table, int m, int n) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			table[i][j].div = float(i+1) / float(j+1);
		}
	}
}
void print_matrix(mult_div_values **table, int m, int n) {
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << table[i][j].mult << "\t";
		}
		cout << endl;
	}	
	cout << endl;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << table[i][j].div << "\t";
		}
		cout << endl;
	}


}
void delete_table(mult_div_values ***table, int m){
	for(int i = 0; i < m; i++)
		delete [] (*table)[i];
	delete [] (*table);
	*table = NULL;
}	


