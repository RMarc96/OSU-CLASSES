#include "./list.h"
#include<stdlib.h>
#include<stdio.h>
struct node* push(struct node* link, int num) {

	struct node *temp = link;

	link = (struct node*)malloc(sizeof(struct node));
	link->val = num;
	link->next = NULL;	

	if(temp != NULL) link->next = temp; 

	return link;
}

/*
struct node *append(struct node *link, int num) {
	struct node* new_node = NULL;

	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->next = NULL;
	new_node->val = num;


	while(link != NULL) {
		link = link->next;
	}

	link = new_node;	
}
*/

/*struct node *sort_ascending(struct node * list) {
	struct node* temp = list;
	int switch_val;
		
	if(temp->next == NULL) return temp;
	else{
		while(temp->next != NULL) {
			if(temp->val > temp->next->val) {
				switch_val = temp->next->val;
				temp->next->val = temp->val;
				temp->val = switch_val;
		
			}
			temp = temp->next;
		}
	}
	return temp;
}
*/
void print(struct node* list) {
	printf("This is working\n");

	while(list != NULL) {
		printf("%d\t", list->val);
		list = list->next;
	}

}



int main() {
	char ans;
	int num;
	struct node *head = NULL;

	do{
		printf("Enter a number: ");
		scanf("%d", &num);
		
		head = push(head, num);	//Can change to append
		printf("Head val: %d\n", head->val);
		print(head);	
		
		printf("\nDo you want another num (y or n): ");
		scanf("%1s", &ans);
	
	} while(ans == 'y');
	
	return 0;
}
