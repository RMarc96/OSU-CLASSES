#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"

struct hashLink {
   KeyType key; /*the key is what you use to look up a hashLink*/
   ValueType value; /*the value stored with the hashLink, a pointer to int in the case of concordance*/
   struct hashLink * next; /*notice how these are like linked list nodes*/
};
typedef struct hashLink hashLink;

struct hashMap {
    hashLink ** table; /*array of pointers to hashLinks*/
    int tableSize; /*number of buckets in the table*/
    int count; /*number of hashLinks in the table*/
};
typedef struct hashMap hashMap;

void keyPrint(KeyType k);
void valPrint(ValueType v);

/*the first hashing function you can use*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*the second hashing function you can use*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/*
 Free all memory used by the buckets.
 */
void _freeLinks (struct hashLink **table, int tableSize)
{
	/*write this*/
	int i;
	struct hashLink* currentLink;

	for(i = 0; i < tableSize; i++) {
		currentLink = table[i];
		while(currentLink != NULL) {
			table[i] = currentLink->next;
			free(currentLink);
			currentLink = table[i];
		}		

	}

}

/* Deallocate buckets, table, and hashTable structure itself.*/
void deleteMap(hashMap *ht) {


	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeLinks(ht->table, ht->tableSize);
        /* Free the array of buckets */
        free(ht->table);
	/* free the hashMap struct */
	free(ht);
}

/*
Resizes the hash table to be the size newTableSize
*/
void _setTableSize(struct hashMap * ht, int newTableSize)
{
	//Holds old information
	struct hashLink** oldTable = ht->table;
	int oldSize = capacity(ht);
//	int oldCount = ht->count;
	int i;

	_initMap(ht, newTableSize);

	for(i = 0; i < oldSize; i++) {
	
		while(oldTable[i] != NULL) {
			insertMap(ht, oldTable[i]->key, oldTable[i]->value);
			oldTable[i] = oldTable[i]->next;
		}
	}	

	_freeLinks(oldTable, oldSize);

	free(oldTable);
}

struct hashLink* allocateNewLink(KeyType k, ValueType v) {
	struct hashLink* newLink;

	newLink = (struct hashLink *)malloc(sizeof(struct hashLink));

	newLink->key = k;
	newLink->value = v;
	newLink->next = NULL;

	return newLink;
}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".

 if a hashLink already exists in the table for the key provided you should
 replace the value for that key.  As the developer, you DO NOT FREE UP THE MEMORY FOR THE VALUE.
 We have to leave that up to the user of the hashMap to take care of since they may or may not
 have allocated the space with malloc.


 Also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{
	/*write this*/
	int bucketIndex;
	struct hashLink* traverse;
//	struct hashLink* newLink;
	//If threshold is exceeded, we double the size of the hashtable
	if(tableLoad(ht) >= LOAD_FACTOR_THRESHOLD) {
		_setTableSize(ht, capacity(ht)*2);
	}

	//REMOVE THE ABOVE RESIZING OPTION IF RUNNING TIME TESTS FOR CONCORDANCE 

	bucketIndex = stringHash1(k) % capacity(ht);

	if(ht->table[bucketIndex] == NULL) {
		ht->table[bucketIndex] = allocateNewLink(k, v);
		ht->count++;
	}
	else{
		traverse = ht->table[bucketIndex];
		//If key is already in the bucket
		if(containsKey(ht, k) == 1) {
			while(traverse != NULL) {
				if(strcmp(traverse->key, k) == 0) {
					traverse->value = v;
					return;
				}
				else traverse = traverse->next;
			}
		}
		//If key is not in the bucket, we're INSERTING which means it goes in the beginning
		else {
			while(traverse != NULL) {
				traverse = traverse->next;	
			}
			
			traverse = allocateNewLink(k,v);

			traverse->next = ht->table[bucketIndex];
			ht->table[bucketIndex] = traverse;
			ht->count++;
		}

	}
}

/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.

 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.

 if the supplied key is not in the hashtable return NULL.
 */
ValueType atMap (struct hashMap * ht, KeyType k)
{
	/*write this*/
	int bucketIndex = stringHash1(k) % capacity(ht);
	struct hashLink *currentLink;
	struct hashLink *prevLink;

/*	if(ht->table[bucketIndex] == NULL) {
		return NULL;
	}
	
	else return ht->table[bucketIndex]->value;
*/

	if(ht->table[bucketIndex] == NULL) return NULL;

	else {
		currentLink = ht->table[bucketIndex];
		prevLink = ht->table[bucketIndex];
		
		while(currentLink != NULL) {
			if(strcmp(currentLink->key, k) == 0)
				return currentLink->value;
			else {
				prevLink = currentLink;
				currentLink = currentLink->next;
			}	
		}
	}
	return NULL;
}

/*
 a simple yes/no if the key is in the hashtable.
 0 is no, all other values are yes.
 */
int containsKey (struct hashMap * ht, KeyType k)
{
	/*write this*/
	int bucketIndex = stringHash1(k) % capacity(ht);
	struct hashLink* traverse = ht->table[bucketIndex];

	while(traverse != NULL) {
		if(strcmp(traverse->key, k) == 0) return 1;
		else traverse = traverse->next;
	}
	
	return 0;
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{
	/*write this*/
	int bucketIndex;
	struct hashLink* currentLink;
	struct hashLink* prevLink;

	bucketIndex = stringHash1(k) % capacity(ht);

	if(containsKey(ht, k) == 0) {
		printf("'");
		keyPrint(k);
		printf("' is not in the table\n");
		return;
	}
	else {
	
		currentLink = ht->table[bucketIndex];
		prevLink = ht->table[bucketIndex];
	
		while(currentLink != NULL) {
			if(strcmp(currentLink->key, k) != 0) {
				prevLink = currentLink;
				currentLink = currentLink->next;
			}
	
			else {
				if(currentLink == ht->table[bucketIndex]) {
					ht->table[bucketIndex] = currentLink->next;
				}
				else {
					prevLink->next = currentLink->next;
				}
				
				free(currentLink);
				ht->count--;
				break;
			}
		}
	}
		//THE PROBLEM LIES HERE 
	/*	if(currentLink->next == NULL) {
			prevLink->next = NULL;
			free(currentLink);
			ht->count--;
		}	
		
		else {
			prevLink->next = currentLink->next;
			free(currentLink);
			ht->count--;
		}
	}
	*/
}

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{
	/*write this*/
	return ht->count;
}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{
	/*write this*/
	return ht->tableSize;
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{
	/*write this*/
	int i;
	int emptyCount;

	for(i = 0; i < ht->tableSize; i++) {
		if(ht->table[i] == 0) {
			emptyCount++;
		}
	}
	return emptyCount;
}

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)

 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{
	/*write this*/
	return size(ht) / capacity(ht);
}

/* print the hashMap */
 void printMap (struct hashMap * ht, keyPrinter kp, valPrinter vp)
{
	int i;
	struct hashLink *temp;
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		if(temp != 0) {
			printf("\nBucket Index %d -> ", i);
		}
		while(temp != 0){
                        printf("Key:");
                        (*kp)(temp->key);
                        printf("| Value: ");
                        (*vp)(temp->value);
			printf(" -> ");
			temp=temp->next;
		}
	}
}

/* print the keys/values ..in linear form, no buckets */
 void printKeyValues (struct hashMap * ht, keyPrinter kp, valPrinter vp)
{
	int i;
	struct hashLink *temp;
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		while(temp != 0){
                        (*kp)(temp->key);
			printf(":");
                        (*vp)(temp->value);
			printf("\n");
			temp=temp->next;
		}
	}
}
