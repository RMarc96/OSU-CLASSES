/* CS261- Assignment 1 - Q.4*/
/* Name: Ronald Salinas
 * Date: October 2, 2015
 * Solution description: Sorts a list of student scores and ids  by their score value (ascending)
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     
     /* Remember, each student must be matched with their original score after sorting */

	int i, id_swap, score_swap;

	for(i = 0; i < n - 1; i++)
		if(students[i].score > students[i+1].score) {
			id_swap = students[i].id;
			score_swap = students[i].score;

			students[i].id = students[i+1].id;
			students[i].score = students[i+1].score;

			students[i+1].id = id_swap;
			students[i+1].score = score_swap;

			i = -1;
		}
}

void generate(struct student *students, int n) {
	int i, j;
	srand(time(NULL));
	
	for(i = 0; i < n; i++) {
		students[i].id = rand() % n + 1;
	
		for(j = 0; j < i; j++)
			if(students[i].id == students[j].id) {
				students[i].id = rand() % n + 1;
				j = -1;
			}
		students[i].score = rand() % 100 + 1;;
	}

}

void print_stuff(struct student *students, int n) {
	int i;
	
	for(i = 0; i < n; i++)
		printf("%d\t%d\n", students[i].id, students[i].score);	
	printf("\n");
}

int main(){
    /*Declare an integer n and assign it a value.*/
   	int n = 10; 
    /*Allocate memory for n students using malloc.*/
   	struct student *arr = (struct student *)malloc(sizeof(struct student)*n);
    /*Generate random IDs and scores for the n students, using rand().*/
	generate(arr, n); 
    /*Print the contents of the array of n students.*/
	printf("\nBefore sort:\n");
	print_stuff(arr, n);
    /*Pass this array along with n to the sort() function*/
	sort(arr, n);    
    /*Print the contents of the array of n students.*/ 
	printf("\nAfter sort:\n");
	print_stuff(arr, n);


    return 0;
}
