#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>


void checkArgs(int argc, char* argv[]) {
	if(argc < 2) {
		printf("Error! Too fe arguments\n");
		exit(1);
	}
}

int compareFunction(const void *a, const void *b) {
	return(*(int*)a - *(int*)b);
}

float findMedian(int count, int arrayX[]) {
	int i;
	float median;
	int copy[count];	
	
	for(i = 0; i < count; i++) copy[i] = arrayX[i];
	qsort(copy, count, sizeof(int), compareFunction);

	if(count <= 3) {
		switch(count) {
			case 3:
				median = (float)copy[1];
				break;
			case 2:
				median = (float)(copy[1]+copy[0]) / 2;
				break;
			case 1:
				median = (float)(copy[0]);
				break;
			case 0:
				median = 0;
				break;
		}
	}
	else if(count % 2 == 0) {
		median = (float)(copy[count/2] + copy[count/2 - 1]) / 2;
	}
	else { median = copy[count/2]; }

	return median;	
}




float closestPair(int pairCount, int arrayX[], int arrayY[]) {
	
	float middleCut;
	float deltaL, deltaR, minDelta, crossDistance;
	int i;
	
	int leftX[pairCount/2], leftY[pairCount/2],
	    rightX[pairCount/2], rightY[pairCount/2];

	

	middleCut = findMedian(pairCount, arrayX);

	//deltaL = closestPair(left half);
	//deltaR = closestPair(right half);
	//minDelta = min(deltaL, deltaR);
	
	// Identify all points within delta from L
	// Sort them by y-coordinate into My (list)
	//
	// crossDistance = closestCrossPair(My, minDelta);
	
//	crossDistance = closts

	return crossDistance;
}


int main(int argc, char* argv[]) {

	int pairCount;
	FILE* datapoints;
	char buffer[256];
	
	checkArgs(argc, argv);

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

	closestPair(pairCount, arrayX, arrayY);
	
/*	printf("# of pairs: %d\n", pairCount);

	int i = 0;
	for(i = 0; i < pairCount; i++) {
		printf("%d %d\n", arrayX[i], arrayY[i]);
	}
*/


	return 0;
}
