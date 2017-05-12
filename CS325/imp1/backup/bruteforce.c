#include<stdlib.h>
#include<stdio.h>
#include<string.h>



int main(int argc, char* argv[]) {

	int pairCount;
	FILE* datapoints;
	char buffer[256];
	if(argc < 2){
		printf("Too few arguments!\n");
		exit(1);
	}	
	if((datapoints = fopen(argv[1], "r")) == NULL){
		printf("Input file does not exist!\n");
		exit(1);
	}
	while(fgets(buffer, sizeof(buffer), datapoints)) pairCount++;
	rewind(datapoints);
	
	int arrayX[pairCount], arrayY[pairCount];
	pairCount = 0;
	while(fgets(buffer, sizeof(buffer), datapoints)) {
		arrayX[pairCount] = atoi(strtok(buffer, " "));
		arrayY[pairCount] = atoi(strtok(NULL, " "));
		pairCount++;
	}
	fclose(datapoints);
	printf("# of pairs: %d\n", pairCount);

	int i = 0;
	for(i = 0; i < pairCount; i++) {
		printf("%d %d\n", arrayX[i], arrayY[i]);
	}




	return 0;
}
