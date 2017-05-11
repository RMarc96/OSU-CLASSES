/* CS261- Assignment 1 - Q.5*/
/* Name: Ronald Salinas
 * Date: October 6, 2015
 * Solution description: Takes in a string from the user and converts it to studly-case
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void studly(char* word){
     /*Convert to studly caps*/
	int i = 0, case_switch = 0;

	while(word[i] != '\0') {
		//Note: The ASCII decimal values for capital English letters are from 65 to 90
		if(word[i] >= 65 && word[i] <= 90) {
			if(case_switch % 2 != 0) word[i] = toLowerCase(word[i]);
		}
		else{
			if(case_switch % 2 == 0) word[i] = toUpperCase(word[i]);
		}
		i++;
		case_switch++;
	}
	
}
int main(){
    /*Read word from the keyboard using scanf*/
 	char input[100];
	printf("Enter a word: ");
	scanf("%s", input);
    /*Call studly*/
   	studly(input); 
    /*Print the new word*/
	printf("%s\n", input);

    return 0;
}
