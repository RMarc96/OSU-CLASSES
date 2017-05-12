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

/**************************************************************************
 * Function: Sort ascending
 * Description: Changes order of given linked list by ascending values
 * Parameters: Beginning of linked list
 * Pre-conditions: Linked list is either empty or not empty
 * Post-conditions: Linked list will not be empty
 * ************************************************************************/

struct node* sort_ascending(struct node* list) {
	struct node* current = list;
	struct node* prev = NULL;
	int val_swap;

	//If list only has one node
	if(list->next == NULL) return list;

	while(current->next != NULL) {
		prev = current;
		current = current->next;
		//Note: This is swap-by-value (I'm lazy)
		if(current->val < prev->val) {
			val_swap = current->val;
			current->val = prev->val;
			prev->val = val_swap;
			current = list;
		}
	}	
	return list;

}

/**************************************************************************
 * Function: Sort descending
 * Description: Changes order of given linked list by descending values
 * Parameters: Beginning of linked list
 * Pre-conditions: Linked list is either empty or not empty
 * Post-conditions: Linked list will not be empty
 * ************************************************************************/

struct node* sort_descending(struct node* list) {
	struct node* current = list;
	struct node* prev = NULL;
	int val_swap;

	//If list only has one node
	if(list->next == NULL) return list;

	while(current->next != NULL) {
		prev = current;
		current = current->next;
		//Note: This is swap-by-value (I'm lazy)
		if(current->val > prev->val) {
			val_swap = current->val;
			current->val = prev->val;
			prev->val = val_swap;
			current = list;
		}
	}	
	return list;

}

/**************************************************************************
 * Function: Push list
 * Description: Adds a new node to the beginning of linked list
 * Parameters: Current linked list, integer for insertion
 * Pre-conditions: Linked list is either empty or not empty
 * Post-conditions: Integer will be the new beginning of linked list
 * ************************************************************************/

struct node* push(struct node* link, int num) {
	
	struct node* temp = NULL;

	temp = (struct node*)malloc(sizeof(struct node));
	temp->val = num; 
	temp->next = link;
	link = temp;
	
	return link;
}

/**************************************************************************
 * Function: Append list
 * Description: Adds a new node to the end of linked list
 * Parameters: Current linked list, integer for insertion
 * Pre-conditions: Linked list is either empty or not empty
 * Post-conditions: Integer will be the new end of linked list
 * ************************************************************************/

struct node* append(struct node* link, int num) {
	
	struct node* temp = link;
	struct node* new_node = NULL;
		

	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->val = num;
	new_node->next = NULL;

	
	if(link == NULL) {
		return new_node;
	}

	else{
		while(temp->next != NULL) {
			temp = temp->next;			
		}	
		temp->next = new_node;
		return link;
	}
}

/**********************************************************************************************************
 * Function: Insert in middle
 * Description: Adds a new node to an arbitrary spot in linked list
 * Parameters: Current linked list, integer for insertion, a spot (index) to put that number
 * Pre-conditions: Linked list is either empty or not empty, index may or may not be within bounds of list
 * Post-conditions: Integer will take spot depending on where the user wanted it to be
 * ********************************************************************************************************/

struct node* insert_middle(struct node* link, int num, int index) {
	struct node* current = link;
	struct node* prev = NULL;
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	int iteration;

	new_node->val = num;
	new_node->next = NULL;

	if(link == NULL) {
		current = new_node;
	}
	else if(link->next == NULL) {
		current->next = new_node;
	}
	else if(index == 0) {
		link = push(link, num);
	}	
	else {
		iteration = 0;
		while(iteration != index && current != NULL) {
			prev = current;
			current = current->next;
			iteration++;
		}
		
		if(current == NULL) link = append(link, num);
		else if(iteration == index) {
			new_node->next = prev->next;
			prev->next = new_node;
		}
	}
	return link;
}		

/*******************************************************************************
 * Function: Length
 * Description: Returns length of linked list
 * Parameters: Current linked list
 * Pre-conditions: Linked list is either empty or not empty
 * Post-conditions: Return value will be an integer greater than or equal to 0
 * *****************************************************************************/

int length(struct node* list) {
	int iteration = 0;

	while(list != NULL) {
		iteration++;	
		list = list->next;
	}

	return iteration;
}


/**************************************************************************
 * Function: Print
 * Description: Outputs the values of linked list to screen
 * Parameters: Current linked list, integer length of linked list 
 * Pre-conditions: Linked list is either empty or not empty
 * Post-conditions: Contents and length of list displayed 
 * ************************************************************************/

void print(struct node* list, int size) {
	printf("\nYour current list:\n");
	while(list != NULL) {
		printf("%d\t", list->val);
		list = list->next;

	}
	printf("\nThe size of your list is: %d. \n", size);
}

/**************************************************************************
 * Function: Clear list
 * Description: Frees all allocated memory of linked list
 * Parameters: Current linked list
 * Pre-conditions: Linked list is either empty or not empty
 * Post-conditions: Linked list will be empty
 * ************************************************************************/

struct node* clear(struct node* list) {
	struct node* prev = NULL;
		
	if(list == NULL) return NULL;

	while(list->next != NULL) {
		prev = list;
		list = list->next;
		free(prev);
	}
	free(list);
	return NULL;
}

/*********************************************************************************************
 * Function: Remove node
 * Description: Removes nodes which contain a specific value
 * Parameters: Current linked list, integer that will be removed
 * Pre-conditions: Linked list is either empty or not empty, integer is or is not in the list
 * Post-conditions: Nodes with that number are removed from the linked list
 * *******************************************************************************************/

struct node* remove_node(struct node* list, int num_remove) {
	struct node* current = list;
	struct node* next_node = NULL;	
	struct node* prev_node = NULL;
	
	//If list is empty
	if(current == NULL)   return list;	

	//If list only has one node
	else if(current->next == NULL && current->val == num_remove) {
		free(current);	
		return NULL;
	}

	//If first node is node to remove
	else if(current->val == num_remove) {
		printf("Does this\n");
		list = current->next;
		free(current);
		current = list;
	}
	else {
		next_node = current->next;	
		while(next_node != NULL) {
			current = current->next;
			if(next_node->val == num_remove) {
				if(next_node == NULL) current->next = NULL; 
				else current->next = next_node->next;
					
				free(next_node);
				current = list;
			}
			next_node = next_node->next;
		}
	}
	return list;
}
