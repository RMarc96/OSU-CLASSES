/* CS261- Assignment 1 - Q.2*/
/* Name: Ronald Salinas
 * Date: October 1, 2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
	(*a) = (*a)*2;	
    /*Set b to half its original value*/
   	(*b) = (*b)/2; 
    /*Assign a+b to c*/
    	c = (*a)+(*b);
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
	int x = 7, y = 8, z = 9, val;   
    /*Print the values of x, y and z*/
   	printf("\nx = %d\ty = %d\tz = %d\n", x, y, z); 
    /*Call foo() appropriately, passing x,y,z as parameters*/
   	val = foo(&x, &y, z); 
    /*Print the value returned by foo*/
	printf("foo() gave: %d\n", val);	   	 
    /*Print the values of x, y and z again*/ 
   	printf("x = %d\ty = %d\tz = %d\n", x, y, z); 
    /*Is the return value different than the value of z?  Why?*/

	//The return value is different. The direct value of z is not being sent to foo().
    return 0;
}
    
    
