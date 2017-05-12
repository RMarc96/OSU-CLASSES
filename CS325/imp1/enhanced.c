#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct Point {
	int X;
	int Y;
};

int compareStructsX(const void *a, const void *b) {
	struct Point *s1 = (struct Point *)a;
	struct Point *s2 = (struct Point *)b;

	return( s1->X - s2->X );
}

int compareStructsY(const void *a, const void *b) {
	struct Point *s1 = (struct Point *)a;
	struct Point *s2 = (struct Point *)b;

	return( s1->Y - s2->Y );
}

float findMedian(int count, struct Point graph[]) {
	float median;

	//Since we're assuming each point has a distinct X and Y value,
	//this function will not be used


	if(count % 2 == 0) {
		median = (float)(graph[count/2].X + graph[count/2 - 1].X / 2);
	}
	else median = graph[count/2].X;

	return median;
}

float distanceFormula(int X2, int X1, int Y2, int Y1) {

	float d;
	
	d = sqrt(pow(X2-X1,2) + pow(Y2-Y1,2));

	return d;
}

float min(float a, float b) {
	
	float minimum;
		
	minimum = (((a) < (b)) ? (a) : (b));

	return minimum;
}

float closestCrossPair() {




}




float recFindDelta(int count, struct Point xSort[]) {

	int i = 0, j = 0, k = 0;
	float bestMin, deltaL, deltaR, deltaMin = 99999999999, deltaBase = 999999999999;
	float median;

	median = findMedian(count, xSort);

	if(count <= 3) {
		for(i = 0; i < count; i++) {
			for(j = i + 1; count; j++) {
				deltaBase = distanceFormula(xSort[i].X, xSort[j].X, xSort[i].Y, xSort[j].Y);
				if(deltaBase < deltaMin) deltaMin = deltaBase;
			}
		}
		return deltaMin;
	}
	else {
		int leftCount, rightCount;


		if(count % 2 == 0) {
			leftCount = count/2 + 1;
			rightCount = count/2;
		}
		else {
			leftCount = count/2;
			rightCount = count/2;
		}		
		
		struct Point leftGraph[leftCount], rightGraph[rightCount];
		// We have to assume each point has distinct X,Y values	
		// THIS MIGHT HAVE SOME ISSUES
		//

		for(i = 0; i < count/2; i++) {
			leftGraph[i].X = xSort[i].X;
			leftGraph[i].Y = xSort[i].Y;
		
		
			rightGraph[i].X = xSort[count/2+i].X;
			rightGraph[i].Y = xSort[count/2+i].Y;
		}

		deltaL = recFindDelta(count/2, leftGraph);
		deltaR = recFindDelta(count/2, rightGraph);	
		deltaMin = min(deltaL, deltaR); 


		//Create M strip where the range is [median-deltaMin, median+deltaMin]		
	
		struct Point* stripM;
		int size = 0;
		for(i = 0; i < count; i++) {
			if(xSort[i].X >= (median-deltaMin) && xSort[i].X <= (median+deltaMin)) {
				stripM[size] = malloc(sizeof(struct Point));
				stripM[size].X = xSort[i].X;
				stripM[size].Y = xSort[i].Y;
				size++;
			}
		}

	
//		bestMin = closestCrossPair();

/*
		printf("FIRST REC:\n Left graph:\n");
		for(i = 0; i < count/2; i++) {
			printf("%d %d\n", leftGraph[i].X, leftGraph[i].Y);
		}
		printf("\n");
	
		printf("Right graph:\n");
		for(i = 0; i < count/2; i++) {
			printf("%d %d\n", rightGraph[i].X, rightGraph[i].Y);
		}
		printf("\n");

		printf("FIRST REC:\n Full y sorted graph:\n");
		for(i = 0; i < count; i++) {
			printf("%d %d\n", ySort[i].X, ySort[i].Y);
		}
		printf("\n");
*/	


		
		return deltaMin;
		//return bestMin;
	}




}


float findClosestPair(int count, struct Point graph[]) {

	int i = 0;
	float minDelta;
	struct Point xSortedGraph[count], ySortedGraph[count];

	for(i = 0; i < count; i++) {
		xSortedGraph[i].X = graph[i].X;
		ySortedGraph[i].X = graph[i].X;
		xSortedGraph[i].Y = graph[i].Y;
		ySortedGraph[i].Y = graph[i].Y;
	}	
	qsort(xSortedGraph, count, sizeof(struct Point), compareStructsX);
	qsort(ySortedGraph, count, sizeof(struct Point), compareStructsY);


//	minDelta = recFindDelta(count, xSortedGraph, ySortedGraph);
	minDelta = recFindDelta(count, xSortedGraph);

	return minDelta;
/*
	printf("X sorted: \n");
	for(i = 0; i < count; i++) {
		printf("%d %d\n", xSortedGraph[i].X, xSortedGraph[i].Y);
	}
	printf("\n");

	
	printf("Y sorted: \n");
	for(i = 0; i < count; i++) {
		printf("%d %d\n", ySortedGraph[i].X, ySortedGraph[i].Y);
	}
	printf("\n");
*/
}



int main(int argc, char* argv[]) {

	int pairCount;
	FILE* datapoints;
	char buffer[256];
	float closestPair;

	if(argc < 2) {
		printf("Error! Too few arguments\n");
		exit(1);
	}

	if((datapoints = fopen(argv[1], "r")) == NULL) {
		printf("Input file does not exist!\n");
		exit(1);
	}

	while(fgets(buffer, sizeof(buffer), datapoints)) pairCount++;
	rewind(datapoints);

	struct Point graphPoints[pairCount];
	
	pairCount = 0;
	while(fgets(buffer, sizeof(buffer), datapoints)) {
		graphPoints[pairCount].X = atoi(strtok(buffer, " "));
		graphPoints[pairCount].Y = atoi(strtok(NULL, " "));
		pairCount++;
	}
	fclose(datapoints);
	
	
	closestPair = findClosestPair(pairCount, graphPoints);

	return 0;
}
