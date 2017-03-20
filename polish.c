/*

STUDENT NO. : 	2016-90653
STUDENT NAME:	Karen Michelle A. Alarcon
-----------------------------------------------------------------------------------------------------------------------------------

REFERENCES:
- Deitel, Paul, and Harvey Deitel. "How To Program C". 7th ed. USA: Pearson Education, 2013. Print.
- "Removing Spaces from a String in C?" Stack Overflow. N.p., n.d. Web. 07 Mar. 2017. <http://stackoverflow.com/questions/1726302/removing-spaces-from-a-string-in-c>.
- Tutorialspoint.com. "C library function - strstr()." Www.tutorialspoint.com. N.p., n.d. Web. 07 Mar. 2017. <https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm>.
- "How does C store negative numbers in signed vs unsigned integers?" Int - How does C store negative numbers in signed vs unsigned integers? - Stack Overflow. N.p., n.d. Web. 07 Mar. 2017. <http://stackoverflow.com/questions/26673013/how-does-c-store-negative-numbers-in-signed-vs-unsigned-integers>.
- "Returning an array using C." Stack Overflow. N.p., n.d. Web. 07 Mar. 2017. <http://stackoverflow.com/questions/11656532/returning-an-array-using-c>.
- "makes pointer from integer without a cast" when outputting a pointer to a text file." C - "makes pointer from integer without a cast" when outputting a pointer to a text file - Stack Overflow. N.p., n.d. Web. 07 Mar. 2017. <http://stackoverflow.com/questions/25224148/makes-pointer-from-integer-without-a-cast-when-outputting-a-pointer-to-a-text>.
- Yabut, Mary Ann. "Idea on storing the token in an array variable." Interview. n.d.: n. pag. Print. 
- Tutorialspoint.com. "C library function - strcat()." Www.tutorialspoint.com. N.p., n.d. Web. 27 Feb. 2017. <https://www.tutorialspoint.com/c_standard_library/c_function_strcat.htm>.
- "How does one represent the empty char?" C - How does one represent the empty char? - Stack Overflow. N.p., n.d. Web. 23 Feb. 2017. <http://stackoverflow.com/questions/18410234/how-does-one-represent-the-empty-char>.
- "C Programming Strings." C Programming Strings. N.p., n.d. Web. 18 Feb. 2017. <https://www.programiz.com/c-programming/c-strings>
- "C program to read a file." C program to read a file | Programming Simplified. N.p., n.d. Web. 18 Feb. 2017. <http://www.programmingsimplified.com/c-program-read-file>.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "stack.h"
#include "polish_functions.h"

#define MAX_LENGTH 100

int main(){
	
	//declaration and initialization of variables
	char inputfile[20], input[MAX_LENGTH], infix[MAX_LENGTH], postfix[MAX_LENGTH];
	int n, line = 0, r=0;

	printf("Program Started.\n\n");			//program start prompt
	printf("Enter file name> ");			//ask user to type in the file to read
	scanf("%s", inputfile);				//save the file name to inputfile variable

	FILE *file = fopen(inputfile,"r");		//open and read the file

	fscanf(file, "%d", &n);				//read the first line and store the value to n 
	fgets(input, sizeof(input), file);		//read the first line

	while(++line <= n){				//loop until n is reached
		fgets(input, sizeof(input), file);	//function to get the string in the current line

		printf("\nExpression %d:\nInfix: ", line);
		printf("%s", input);			//outputs the infix expression

		FORMAT(infix, input);			//function call to format the input to parenthesized infix expression
		POLISH(infix, postfix, r);		//function call to generate postfix expression given the infix expression

		printf("POSTFIX: %s \n", postfix);	//outputs the postfix expression
	}

	printf("\nProgram Terminated.\n");		//program termination prompt
	
	fclose(file);					//close the file
}

