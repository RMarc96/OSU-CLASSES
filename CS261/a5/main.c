#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"

void _adjustHeap(DynArr *heap, int max, int pos, comparator compare);
void print_task(TYPE val);


int main (int argc, const char * argv[])
{
  char cmd = ' ';
  DynArr* mainList = createDynArr(10);

  FILE *textfile;
  char filename[100];
  char description[100];
  int priority;
  TaskP newTask;

  printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("\n\nPress:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
      /* clear the trailing newline character */
      while (getchar() != '\n');

      /* Fixme:  Your logic goes here! */
	if(cmd == 'l') {		
		printf("Enter name of file you want to load: ");
		scanf("%s", filename);
		textfile = fopen(filename, "r");
		loadList(mainList, textfile);
		_adjustHeap(mainList, sizeDynArr(mainList), 0, compare);
		printf("The list has been loaded successfully.");
		fclose(textfile);
	}
	else if(cmd == 's') {
		printf("Enter name of file you want to save to: ");
		scanf("%s", filename);
		textfile = fopen(filename, "w+");
		saveList(mainList, textfile);
		fclose(textfile);
	}
	else if(cmd == 'a') {
		printf("Enter the task description: ");
		fgets(description, 100, stdin);
		description[strcspn(description, "\n")] = 0;
		//The line above is meant to get rid of \n from fgets()
		printf("Enter the task priority (0-999): ");
		scanf("%d", &priority);	
		newTask = createTask(priority, description);
		addHeap(mainList, newTask, compare);
		_adjustHeap(mainList, sizeDynArr(mainList), 0, compare);
	}
	else if(cmd == 'g') {
		printf("\n");
		printf("Your first task:\n       ");
		print_type(getDynArr(mainList, 0));
	}
	
	else if(cmd == 'r') {
		printf("Your first task: '");
		print_task(getDynArr(mainList, 0));
		printf("' has been removed from the list.");
		removeMinHeap(mainList, compare);
	}

	else if(cmd == 'p') {
		printList(mainList);
	}
	
    } while(cmd != 'e');


  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
