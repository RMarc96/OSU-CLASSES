#include "cirListDeque.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	struct cirListDeque *deque;
	printf("\n**************************************************\n");
	printf("TESTING CIRCULAR DOUBLY LINKED LIST\n");
	
	printf("Creating circular doubly linked list...\n");
	deque = createCirListDeque();
	printf("Adding to the front of the deque: 6 then 7 then 8\n");
	addFrontCirListDeque(deque, 6);	
	addFrontCirListDeque(deque, 7);
	addFrontCirListDeque(deque, 8);
	printCirListDeque(deque);
	printf("Adding to the back of the deque: 5 then 4\n");
	addBackCirListDeque(deque, 5);
	addBackCirListDeque(deque, 4);
	printCirListDeque(deque);

	printf("The current front value of the deque: %f\n", frontCirListDeque(deque));
	printf("The current back value of the deque: %f\n", backCirListDeque(deque));

	printf("Removing front value of the deque...\n");
	removeFrontCirListDeque(deque);
	printCirListDeque(deque);

	printf("Removing back value of the deque...\n");
	removeBackCirListDeque(deque);
	printCirListDeque(deque);

	printf("Checking if deque is empty...  ");
	if(!isEmptyCirListDeque(deque)) 
		printf("THE DEQUE IS NOT EMPTY\n");
	else printf("THE DEQUE IS EMPTY\n");

	printf("Reversing order of values in deque...\n");
	reverseCirListDeque(deque);
	printCirListDeque(deque);

	printf("Adding to the front of deque: 8\n");
	addFrontCirListDeque(deque, 8);
	printCirListDeque(deque);
	printf("Reversing order again...\n");
	reverseCirListDeque(deque);
	printCirListDeque(deque);

	printf("Deleting deque... DONE. Use valgrind to check.\n");
	deleteCirListDeque(deque);	

	printf("\n**************************************************\n");
	return 0;
}


