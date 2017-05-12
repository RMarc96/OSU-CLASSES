#include<stdio.h>
#include<stdlib.h>
#include "list.h"

int length(struct node *head) {
	struct node *temp = head;
	int iteration = 0;
	
	
	while(temp != NULL) {
		temp = temp->next;
		iteration++;
	}
	return iteration;
}


void print(struct node *head, int length) {
	printf("%d\n", &head->val);
	printf("%d\n", length);	

}

void push(struct node **head, int i) {
	struct node *temp = *head;

	*head = malloc(sizeof(struct nod));
	(*head)->val = i;
	(*head)->next = temp;
}

void append(struct node **head, int i) {
	struct node *temp = *head;

	while(temp->next != NULL) {
		temp = temp->next;
	}	
	temp->next = malloc(sizeof(struct node));

//	*head = temp;
//	(*head) -> val = i;
		
}

int main() {
	char ans;
	int num;	
	struct node *head = NULL;

//	do {
	printf("Enter a number: ");
	scanf("%d", &num);

	push(&head, num);		//adds to the front
	append(&head, num);		//adds to the back
//	printf("Do you want another num (y or n): ");
//	scanf("%1s", &ans);

//	while(ans == 'y');
		print(head, length(head));	
	


	return 0;
}
