#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>


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





	//BRUTE FORCE METHOD

	float bestDist = 9001;
	float currentDist;
	float deltaX, deltaY;
	int k = 0, j = 0;


	for(j = 0; j < pairCount; j++) {		
		for(k = 0; k < pairCount; k++) {
			deltaX = (float)(arrayX[j] - arrayY[k]);
			deltaY = (float)(arrayY[j] - arrayY[k]);
	
			currentDist = sqrt((pow(deltaX, 2) + pow(deltaY, 2)));
			
			if(currentDist < bestDist && currentDist != 0) {
				bestDist = currentDist;
				printf("%d,%d --> %d,%d\tDist: %f\n", 
					arrayX[j], arrayY[j], 
					arrayX[k], arrayY[k], currentDist);
					
			}
		}
	}
	
	printf("Best distance is: %f\n", bestDist);


	return 0;
}
