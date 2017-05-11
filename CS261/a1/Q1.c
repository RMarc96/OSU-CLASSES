/* CS261- Assignment 1 - Q.1*/
/* Name: Ronald Salinas
 * Date: October 2, 2015
 * Solution description: Generates and prints out a list of structs containing unique student IDs and scores
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student* arr;     
	
	arr = (struct student*)malloc(sizeof(struct student)*10);
     /*return the pointer*/
	return arr;
}	

void generate(struct student* students){
     /*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/ 
	int i, j;

	srand(time(NULL));	

	for(i = 0; i < 10; i++) {
		students[i].id = rand() % 10 + 1;
		
		for(j = 0; j < i; j++)
			if(students[i].id == students[j].id) {
				students[i].id = rand() % 10 + 1;
				j = -1;
			}
		students[i].score = rand() % 100 + 1;

	}
}

void output(struct student* students){
	
	int i;

	printf("\n");

	for(i = 0; i < 10; i++)
		printf("%d\t%d\n", students[i].id, students[i].score);


	printf("\n");
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	int i, j;
	float min = 100, max = 0, sum, avg;

	for(i = 0; i < 10; i++) {
		if(students[i].score < min)
			min = students[i].score;
		else if(students[i].score > max)
			max = students[i].score;
	}

	for(j = 0; j < 10; j++) 
		sum += students[j].score;

	avg = sum / 10;
	
	printf("\nMinimum score: %f\nMaximum score:%f\nAverage: %f\n", min, max, avg);
}

void deallocate(struct student* stud){
	free(stud);
	
	stud = NULL;	
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
   	stud = allocate(); 
    /*call generate*/
   	generate(stud); 
    /*call output*/
   	output(stud); 
    /*call summary*/
   	summary(stud); 
    /*call deallocate*/
	deallocate(stud);
    return 0;
}
