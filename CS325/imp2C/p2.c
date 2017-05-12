#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

int main(int argc, char *argv[]) {

	FILE *file;
	char costTable[6][6];


	if(argc != 3) {
		printf("Invalid argument count!\n");
		exit(1);
	}
	
	file = fopen(argv[1], "r");	
	if(file == NULL) {
		printf("Cost file is invalid\n");
		exit(1);
	}

	int i=0, j=0, first = 0;;
	char *token;
	char line[256];
	

	while(fgets(line, 256, file) != NULL) {
	//	printf("%s", line);
		if(!first) {
			token = strtok(line, ",");
			first++;
		}
		else token = strtok(NULL, ",");	

	//	costTable[i][j] = token;
	//	j++;
	//	if(j == 6) { j = 0; i++; }
	}

	return 0;
}
