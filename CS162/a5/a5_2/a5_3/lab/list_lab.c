#include "./list.h"
#include<stdio.h>
#include<stdlib.h>

void push(struct node** link, int num) {
	
	struct node* temp = NULL;

	temp = (struct node*)malloc(sizeof(struct node));
	temp->val = num; 
	temp->next = *link;
	*link = temp;
}

void append(struct node** link, int num) {
	
	struct node* new_node = NULL;
	struct node* current = *link;


	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->val = num;
	new_node->next = NULL;

	
	if(*link == NULL) {
		*link = new_node;
		return;
	}

	else{
		while(current->next != NULL) {
			current = current->next;			
		}	
		current->next = new_node;
	}

//	(*link)->next = current;		
}

		

int length(struct node* list) {
	int iteration = 0;

	while(list != NULL) {
		iteration++;	
		list = list->next;
	}

	return iteration;
}

void print(struct node* list, int iterations) {
	while(list != NULL) {
		printf("%d\t", list->val);
		list = list->next;

	}
	printf("\nThe size of your list is: %d. ", iterations);
	printf("\n");

}



int main() {
	char ans[2];
	int num;
	struct node* head = NULL;

	ans[0] = 'y';

	while(ans[0] == 'y') {
		printf("Enter a number: ");
		scanf("%d", &num);

//		push(&head, num);
		append(&head, num);
	
		printf("Do you want another num (y or n): ");
		scanf("%1s", ans);


	}	

	print(head, length(head));
	return 0;
}
