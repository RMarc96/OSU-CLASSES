/**************************************************************************************************
 * Filename: RPN Calculator
 * Name: Ronald Salinas
 * Date: October 12, 2015
 * Description: Calculates a postfix-notated operation which the user enters in the command line.
 * ************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"
#include <assert.h>
#include <math.h>

#ifndef M_E
#define M_E 2.718281828459045
#endif

#ifndef M_PI
#define M_PI 3.141592653589793
#endif


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	if(!(sizeDynArr(stack) >= 2)) {
		printf("\nToo few arguments!\n");
		exit(0);
	}
	
	TYPE val1, val2, val;
	
	val1 = topDynArr(stack);
	popDynArr(stack);

	val2 = topDynArr(stack);
	popDynArr(stack);

	val = val2 + val1;
	pushDynArr(stack, val);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	if(!(sizeDynArr(stack) >= 2)) {
		printf("\nToo few arguments!\n");
		exit(0);
	}

	TYPE val1, val2, val;
	
	val1 = topDynArr(stack);
	popDynArr(stack);

	val2 = topDynArr(stack);
	popDynArr(stack);

	val = val2 - val1;
	pushDynArr(stack, val);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	if(!(sizeDynArr(stack) >= 2)) {
		printf("\nToo few arguments!\n");
		exit(0);
	}

	TYPE val1, val2, val;
	
	val1 = topDynArr(stack);
	popDynArr(stack);

	val2 = topDynArr(stack);
	popDynArr(stack);

	val = val2 / val1;
	pushDynArr(stack, val);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their product is pushed back onto the stack.
*/
void multiply(struct DynArr *stack)
{
	if(!(sizeDynArr(stack) >= 2)) {
		printf("\nToo few arguments!\n");
		exit(0);
	}

	TYPE val1, val2, val;
	
	val1 = topDynArr(stack);
	popDynArr(stack);

	val2 = topDynArr(stack);
	popDynArr(stack);

	val = val2 * val1;
	pushDynArr(stack, val);
}

void exponentiate(struct DynArr *stack)
{
	if(!(sizeDynArr(stack) >= 2)) {
		printf("\nToo few arguments!\n");
		exit(0);
	}

	TYPE val1, val2, val;
	
	val1 = topDynArr(stack);
	popDynArr(stack);

	val2 = topDynArr(stack);
	popDynArr(stack);

	val = pow(val2, val1);
	pushDynArr(stack, val);
}

void spec_exponentiate(struct DynArr *stack)
{
	if(!(sizeDynArr(stack) >= 2)) {
		printf("\nToo few arguments!\n");
		exit(0);
	}

	TYPE val1, val2, val;
	
	val1 = topDynArr(stack);
	popDynArr(stack);

	val2 = topDynArr(stack);
	popDynArr(stack);

	val = pow(val1, val2);
	pushDynArr(stack, val);
}
void absolute(struct DynArr *stack)
{
	if(!(sizeDynArr(stack) >= 1)) {
		printf("\nToo few arguments!\n");
		exit(0);
	}
	TYPE val1, val;
	
	val1 = topDynArr(stack);
	popDynArr(stack);

	val = fabs(val1);
	pushDynArr(stack, val);
}

void natural_log(struct DynArr *stack)
{
	if(!(sizeDynArr(stack) >= 1)) {
		printf("\nToo few arguments!\n");
		exit(0);
	}

	TYPE val1, val;

	val1 = topDynArr(stack);
	popDynArr(stack);
	
	val = log(val1);
	pushDynArr(stack, val);
}

void logorithm(struct DynArr *stack) 
{
	if(!(sizeDynArr(stack) >= 1)) {
		printf("\nToo few arguments!\n");
		exit(0);
	}

	TYPE val1, val;

	val1 = topDynArr(stack);
	popDynArr(stack);
	
	val = log10(val1);
	pushDynArr(stack, val);
}
double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0, val = 0.0;
	char *s;
	struct DynArr *stack;

	stack = createDynArr(20);

	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			multiply(stack);
		else if(strcmp(s, "^") == 0)
			exponentiate(stack);
		else if(strcmp(s, "^2") == 0) {
			pushDynArr(stack, 2);
			exponentiate(stack);
		}
		else if(strcmp(s, "^3") == 0) {
			pushDynArr(stack, 3);
			exponentiate(stack);
		}
		else if(strcmp(s, "abs") == 0)
			absolute(stack);
		else if(strcmp(s, "sqrt") == 0) {
			pushDynArr(stack, 0.5);
			exponentiate(stack);
		}
		else if(strcmp(s, "exp") == 0) {
			pushDynArr(stack, M_E);
			spec_exponentiate(stack);
		}
		else if(strcmp(s, "ln") == 0)
			natural_log(stack);
		else if(strcmp(s, "log") == 0)
			logorithm(stack);
		else 
		{
			if(isNumber(s, &val)) {
				pushDynArr(stack, val);
			}
			else if(strcmp(s, "pi") == 0)
				pushDynArr(stack, M_PI);
			else if(strcmp(s, "e") == 0)
				pushDynArr(stack, M_E);
			else {
				printf("\nEntered invalid an operand/operator:   '%s'  \n", s);
				exit(0);
			}		
		}
	}	//end for 

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
	
	if(sizeDynArr(stack) > 1) {
		printf("\nToo many arguments!\n");
		exit(0);
	}
	result = topDynArr(stack);	

	return result;
}

int main(int argc , char** argv)
{
	double calc;
	if (argc == 1)
		return 0;

	calc = calculate(argc,argv);
	printf("\nResult: %lf\n", calc);
	return 0;
}
