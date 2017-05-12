#include "./mult_div.h"
#include<stdlib.h>

int main(int argc, char *argv[]) {
	mult_div_values **table;
	bool valid = 1;

	while(valid) valid = is_valid_dimensions(argv[1], argv[2]);
	
	int rows = atoi(argv[1]), cols = atoi(argv[2]);

	table = create_table(rows, cols);
	set_mult_values(table, rows, cols);
	set_div_values(table, rows, cols);
	print_matrix(table, rows, cols);
	
	delete_table(&table, rows);

	return 0;
}
