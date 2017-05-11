#include<iostream>

#define PROMPT "Please enter a whole number: "
#define NOT_PRIME "The number is not a prime number ./n"
#define PRIME "The number is a prime number ./n"
#define DONE 0		/* ends successful program */
#define FIRST_FACTOR 2	/*initial value in for loop */

using std::cout;
using std::cin;

int main() {
	int i;		/* loop counter */
	int number; /* number provided by user */

	cout << PROMPT;	/* prompt user */
	cin >> number;	/* wait for user input*/


	for(i = FIRST_FACTOR; i <= number/2; i++)	{
		if( number%i == 0 ){	/* if divisible */
			cout << NOT_PRIME << number;	/* not prime */
			return DONE;	/* exit program */
		}


		else{
			cout << PRIME << number;
			return DONE;
		}
	}
	return 0;
}
