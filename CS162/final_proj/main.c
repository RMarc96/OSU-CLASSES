/*******************************************************************************************
 * Filename: Main.c
 * Author: Ronald Salinas
 * Date: June 10, 2015
 * Description: Has a main function and an append function to test given merge.c program
 * Input: Integer values
 * Output: Integers
 * *****************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "merge.h"
#define nullptr NULL

void append(struct node** link, int num) {
	struct node* new_node = nullptr;
	struct node* current = *link;

	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->info = num;
	new_node->next = nullptr;

	if(*link == nullptr)
		*link = new_node;
	else{
		while(current->next != NULL)
			current = current->next;

		current->next = new_node;
	}	

}

int main() {
	struct node* first = nullptr;
	struct node* last = nullptr;
	char ans = 'y';
	int val;

	while(ans == 'y') {
		printf("Do you want to enter info? (y or n): ");
		scanf("%1s", &ans);
	
		if(ans == 'y') {
			printf("Enter info: ");
			scanf("%d", &val);
			append(&first, val);
		}
	}

//	append(&last, 1);		//Test case 9

//	append(&last, 2);		//Test case 10
//	append(&last, 4);
//	append(&last, 6);
	

	mergeSort(&first, &last);


	//Print ALL the stuff	
	printf("First:\n");
	while(first != nullptr) {
		printf("%d\t", first->info);	
		first = first->next;
	}	
	
	printf("\nLast:\n");
	while(last != nullptr) {
		printf("%d\t", last->info);
		last = last->next;
	}
	printf("\n");


	return 0;
}
