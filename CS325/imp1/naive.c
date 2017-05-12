#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>


#define MIN(a,b)(((a)<(b)) ? (a) : (b))

struct point {
	float X;
	float Y;
};

void checkArgs(int argc, char* argv[]) {
	if(argc < 2) {
		printf("Error! Too few arguments\n");
		exit(1);
	}
}

int compareStructs(const void *a, const void *b) {
	struct point *s1 = (struct point *)a;
	struct point *s2 = (struct point *)b;

	return( s1->X - s2->X);

}

float findMedian(int count, struct point graph[]) {
	float median;

	if(count <= 3) {
		switch(count) {
			case 3:
				median = (float)graph[1].X;
				break;
			case 2:
				median = (float)(graph[1].X + graph[0].X) / 2;
				break;
			case 1:
				median = (float)(graph[0].X);
				break;
			case 0:
				median = 0;
				break;
		}
	}
	else if(count % 2 == 0) {
		median = (float)(graph[count/2].X + graph[count/2 - 1].X) / 2;
	}
	else { median = graph[count/2].X; }

	return median;	
}


float closestPair(int pairCount, struct point graph[]) {
	
	float middleCut;
	float deltaL, deltaR, minDelta, minDelta2, minDelta3, crossDistance;
	int i, j;
	
	struct point copyStructArray[pairCount];	
	
	qsort(graph, pairCount, sizeof(struct point), compareStructs);

	if(pairCount <= 3) {
		switch(pairCount) {
			case 3:
				minDelta = sqrt(pow(graph[1].X-graph[0].X, 2) +  pow(graph[1].Y-graph[0].Y, 2));
				minDelta2 = sqrt(pow(graph[2].X-graph[0].X, 2) + pow(graph[2].Y-graph[0].Y, 2));
				minDelta3 = sqrt(pow(graph[2].X-graph[1].X, 2) + pow(graph[2].Y-graph[1].Y, 2));
			
				if(minDelta < minDelta2) minDelta = minDelta2;
				if(minDelta < minDelta3) minDelta = minDelta3;
				break;
			case 2:
				minDelta = sqrt(pow(graph[1].X-graph[0].X, 2) + pow(graph[1].Y-graph[0].Y, 2));
				break;
		}
		return minDelta;
	}
	else {	
		middleCut = findMedian(pairCount, graph);


		struct point leftGraph[pairCount/2], rightGraph[pairCount/2];

		for(i = 0; i < pairCount/2; i++) {
			leftGraph[i].X = graph[i].X;
			leftGraph[i].Y = graph[i].Y;
			rightGraph[i].X = graph[i+pairCount/2].X;
			rightGraph[i].Y = graph[i+pairCount/2].Y;
		}

		deltaL = closestPair(pairCount/2, leftGraph);
		printf("Min delta left: %d\n", (int)deltaL);

//		return crossDistance;
	}
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
	
	struct point graphPoints[pairCount];

	pairCount = 0;
	while(fgets(buffer, sizeof(buffer), datapoints)) {
		graphPoints[pairCount].X = atoi(strtok(buffer, " "));
		graphPoints[pairCount].Y = atoi(strtok(NULL, " "));
		pairCount++;
	}
	fclose(datapoints);


	closestPair(pairCount, graphPoints);
	

	return 0;
}
