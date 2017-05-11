#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
        
	struct linkedList * list;

	printf("**************************************************\n");

	printf("TESTING LINKEDLIST.C\n");
	
	printf("Creating linked list...\n");
	list = createLinkedList();

	printf("Adding to back of list: 3\n");
	addBackList(list, 3);
	_printList(list);
	printf("Adding to front of list: 5\n");
	addFrontList(list, 5);
	_printList(list);

	printf("Current front value: %d\n", frontList(list));
	printf("Current back value: %d\n", backList(list));
	
	printf("Removing front value of list...\n");
	removeFrontList(list);
	_printList(list);
	printf("Removing back value of list...\n");
	removeBackList(list);
	_printList(list);
	
	printf("Checking if list is empty...");
	if(!isEmptyList(list)) 
		printf(" NOT EMPTY\n");
	else printf(" EMPTY\n");

	printf("Adding new values to list: 1 2 5 7 8 9\n");
	addList(list, 1);
	addList(list, 2);
	addList(list, 5);
	addList(list, 7);
	addList(list, 8);
	addList(list, 9);
	_printList(list);

	printf("Removing selected value from list: 7\n");
	removeList(list, 7);
	_printList(list);
	printf("Checking if selected value is in the list: 7");
	if(containsList(list, 7))
		printf("\nVALUE IS IN THE LIST\n");
	else printf("\nVALUE IS NOT IN THE LIST\n");
	printf("Checking if selected value is in the list: 5");
	if(containsList(list, 5))
		printf("\nVALUE IS IN THE LIST\n");
	else printf("\nVALUE IS NOT IN THE LIST\n");

	printf("Deleting linked list... DONE! Run valgrind to check\n");
	deleteLinkedList(list);
	printf("**************************************************\n");
	return 0;
}


