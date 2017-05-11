/***************************************************************
 * CS261 - Assignment 1 - Q.0
 * Name: Ronald Salinas
 * Date: September 29, 2015
 * Description: Print the value and address of an integer in main() and fooA()
 * **************************************************************/


#include<stdio.h>
#include<stdlib.h>

void fooA(int *iptr) {

	printf("iptr points to the int value: %d\n", *iptr);	

	printf("iptr points to the address: %p\n", iptr);

	printf("The address of iptr is: %p\n", &iptr);
}


int main(int argc, char* argv[]) {

	int x = 12345;

	printf("\nAddress of x: %p\n", &x);

	fooA(&x);
	
	printf("The value of x: %d\n", x);

	return 0;
}
