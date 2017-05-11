//
//  sll.c
//  Lab4
//
//  Created by Todd Kulesza on 1/25/14.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sll.h"

/* This struct represents a singly-linked list */
/* You shouldn't need to modify this struct */
struct sll {
    struct sll_node *start;
};

/* This struct represents a node in a singly-linked list */
/* You shouldn't need to modify this struct */
struct sll_node {
    char value;
    struct sll_node *next;
};

/* Allocate memory for a new list */
/* You shouldn't need to modify this function */
struct sll* sll_create() {
    struct sll *list = (struct sll*)malloc(sizeof(struct sll));
    list->start = NULL; /* Set the next link to NULL so that we know it
                        * doesn't point to anything. */
    
    return list;
}

/* Iterate over each node in the list and free it */
/* You shouldn't need to modify this function */
void sll_free(struct sll *list) {
    struct sll_node *iterator = NULL;
    struct sll_node *next_node = NULL;
    
    assert(list != NULL);
    
    iterator = list->start;
    while (iterator != NULL) {
        /* Store a pointer to the next node */
        next_node = iterator->next;
        
        /* Free the current node */
        free(iterator);
        
        /* Advance our iterator to the next node */
        iterator = next_node;
    }
}

/* Allocate memory for a new "struct sll_node" and return a pointer to it */
struct sll_node* sll_node_create() {
    struct sll_node *node = NULL;
    
    /* FIXME: finish this function */
    node = (struct sll_node*)malloc(sizeof(struct sll_node));   
    node->next = NULL;
 
    return node;
}

/* Stack interface to our singly linked list (last in, first out) */

/* Add the value to the list */
void sll_push(struct sll *list, char value) {
    assert (list != NULL);
    struct sll_node* traverse = list->start;   
    while(traverse != NULL) {
	traverse = traverse->next;
    }
    traverse = sll_node_create();
    traverse->value = value;
    /* Can you make it run in O(1)? */
    //No, since with a singly-linked list, we would need to traverse to
    //the end from the beginning using a loop.
}

/* Return the value most recently added to the list and remove it from the
 * list. */
char sll_pop(struct sll *list) {
    assert (list != NULL);
    char recent;
    struct sll_node* traverse = list->start;   
    while(traverse->next != NULL) {
	traverse = traverse->next;
    }
    recent = traverse->next->value;
    free(traverse->next);
    traverse->next = NULL;
    /* Can you make it run in O(1)? */

    return recent;  
}

/* Return the value most recently added to the list, but don't remove it from
 * the list. */
char sll_top(struct sll *list) {
    assert (list != NULL);
    
    /* If you've written the previous two function such that they run in O(1),
     * doing the same here should be easy. */
    
    return list->start->value; /* This is just a placeholder to make the code compile */
}
