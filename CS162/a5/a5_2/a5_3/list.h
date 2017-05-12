/****************************************************************
 * Filename: CS162 - Assignment 5: Linked list header file
 * Author: Ronald Salinas
 * Date: June 6, 2015
 * Description: Contains declarations for functions in program
 * Input: - 
 * Output: - 
 * *************************************************************/

struct node{
	int val;
	struct node* next;
};

int length(struct node*);
void print(struct node*, int);
struct node* push(struct node*, int);
struct node* append(struct node*, int);
struct node* clear(struct node*);
struct node* sort_ascending(struct node*);
struct node* sort_descending(struct node*);
struct node* remove_node(struct node*, int);
struct node* insert_middle(struct node*, int, int);
