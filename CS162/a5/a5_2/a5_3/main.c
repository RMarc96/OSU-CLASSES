/********************************************************************************
 * Filename: CS162 - Assignment 5
 * Author: Ronald Salinas
 * Date: June 6, 2015
 * Description: Demonstrates various actions that can be done in a linked list
 * Input: Number insertion values, yes or no
 * Output: New/modified linked list of integers
 * ******************************************************************************/

#include "./list.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
	struct node* head = NULL;	
	int num, method, sort, index;
	char ans[2]; 
	ans[0] = 'y';

	printf("(1)Push or (2)Append : ");
	scanf("%d", &method);
	
	if(method != 1 && method != 2) {
		printf("Invalid entry.\n");
		return 0;
	}
	while(ans[0] == 'y') {
		while(ans[0] == 'y') {
			printf("\nEnter number: ");
			scanf("%d", &num);
		
			if(method == 1) head = push(head, num);
			else if(method == 2) head = append(head, num);	

			printf("Enter another number (y or n): ");
			scanf("%1s", &ans[0]);
		}

		printf("\nSort ascending, descending, or neither (a or d or etc)? ");
		scanf("%1s", &ans[1]);

	
		if(ans[1] == 'a') head = sort_ascending(head);	
		else if(ans[1] == 'd') head = sort_descending(head);
		else head = head;

		do{
			print(head, length(head));
			printf("\nDo you want to insert any numbers on this list? (y or n): ");
			scanf("%1s", &ans[1]);

			if(ans[1] == 'y') {
				printf("\nWhat number do you want to add? ");
				scanf("%d", &sort);
				printf("Where in the list do you want it added? (index) : ");
				scanf("%d", &index);
				
				head = insert_middle(head, sort, index);
			}

		} while(ans[1] == 'y');
	
		do {
			print(head, length(head));
			printf("\nDo you want to remove any numbers on this list? (y or n): ");
			scanf("%1s", &ans[1]);
			
			if(ans[1] == 'y') {
				printf("Which number do you want to remove? ");
				scanf("%d", &sort);
				head = remove_node(head, sort);
			} 
		} while(ans[1] == 'y');
		
		printf("Do you want to do this again (y or n): ");
		scanf("%1s",&ans[0]);
		
		head = clear(head);
	}
	return 0;
}
