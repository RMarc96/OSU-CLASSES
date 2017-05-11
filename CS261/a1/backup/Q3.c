/* CS261- Assignment 1 - Q.3*/
/* Name: Ronald Salinas
 * Date: October 3, 2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
	int i, swap;
	

	for(i = 0; i < n - 1; i++) {
		if(number[i] > number[i+1]) {
			swap = number[i];
			number[i] = number[i+1];
			number[i+1] = swap;
			i = -1;	
		}

	}
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
   	int n = 20, i , j , k; 
	int *arr = NULL;

	srand(time(NULL));
    /*Allocate memory for an array of n integers using malloc.*/
    	arr = (int *)malloc(20*sizeof(int));
    /*Fill this array with random numbers between 0 and n, using rand().*/
   	for(j = 0; j < n; j++)
		arr[j] = (int)(rand() % n + 1);
    /*Print the contents of the array.*/
	printf("\n[");
	for(k = 0; k < n; k++) {
		printf("%d", arr[k]);
		if(k != n - 1) printf(" ,");
		else printf("]\n");
	}
    /*Pass this array along with n to the sort() function.*/
   	sort(arr, n);
    /*Print the contents of the array.*/    
    	printf("\n[");
	for(k = 0; k < n; k++) {
		printf("%d", arr[k]);
		if(k != n - 1) printf(" ,");
		else printf("]\n");
	}
    return 0;
}
